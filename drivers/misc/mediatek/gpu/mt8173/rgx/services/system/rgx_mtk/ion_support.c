/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */


#include "pvrsrv_error.h"
#include "img_types.h"
#include "pvr_debug.h"
#include "ion_support.h"
#include "ion_sys.h"

#include <linux/version.h>
#include PVR_ANDROID_ION_HEADER
#define ION_RUNTIME_DEBUGGER 0
#include PVR_ANDROID_ION_PRIV_HEADER
#include <linux/err.h>
#include <linux/slab.h>

struct ion_client *MTKGetIonClient(void);

#ifdef MTK_USE_IMG_ION_IMPLEMENTATION
/* Just the system heaps are used by the generic implementation */
static struct ion_platform_data generic_config = {
	.nr = 2,
	.heaps =
#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,4,39))
#else
		(struct ion_platform_heap [])
#endif
		{
			{
				.type = ION_HEAP_TYPE_SYSTEM_CONTIG,
				.name = "system_contig",
				.id = ION_HEAP_TYPE_SYSTEM_CONTIG,
			},
			{
				.type = ION_HEAP_TYPE_SYSTEM,
				.name = "system",
				.id = ION_HEAP_TYPE_SYSTEM,
			}
		}
};

struct ion_heap **g_apsIonHeaps;
struct ion_device *g_psIonDev;
static struct ion_client *g_ion_client;

PVRSRV_ERROR IonInit(void *phPrivateData)
{
	int uiHeapCount = generic_config.nr;
	int uiError;
	int i;

	PVR_UNREFERENCED_PARAMETER(phPrivateData);

	g_apsIonHeaps = kzalloc(sizeof(struct ion_heap *) * uiHeapCount, GFP_KERNEL);

	/* Create the ion devicenode */
	g_psIonDev = ion_device_create(NULL);
	if (IS_ERR_OR_NULL(g_psIonDev)) {
		kfree(g_apsIonHeaps);
		return PVRSRV_ERROR_OUT_OF_MEMORY;
	}

	/* Register all the heaps */
	for (i = 0; i < generic_config.nr; i++)
	{
		struct ion_platform_heap *psPlatHeapData = &generic_config.heaps[i];

		g_apsIonHeaps[i] = ion_heap_create(psPlatHeapData);
		if (IS_ERR_OR_NULL(g_apsIonHeaps[i]))
		{
			uiError = PTR_ERR(g_apsIonHeaps[i]);
			goto failHeapCreate;
		}
		ion_device_add_heap(g_psIonDev, g_apsIonHeaps[i]);
	}

	g_ion_client = ion_client_create(g_psIonDev, "RGX");

	return PVRSRV_OK;

failHeapCreate:
	for (i = 0; i < uiHeapCount; i++) {
		if (g_apsIonHeaps[i])
		{
				ion_heap_destroy(g_apsIonHeaps[i]);
		}
	}
	kfree(g_apsIonHeaps);
	ion_device_destroy(g_psIonDev);

	return PVRSRV_ERROR_OUT_OF_MEMORY;
}

struct ion_device *IonDevAcquire(void)
{
	return g_psIonDev;
}

void IonDevRelease(struct ion_device *psIonDev)
{
	/* Nothing to do, sanity check the pointer we're passed back */
	/*PVR_ASSERT(psIonDev == g_ion_device);*/
}

unsigned int IonPhysHeapID(void)
{
	return 0;
}

void IonDeinit(void)
{
	int uiHeapCount = generic_config.nr;
	int i;

	ion_client_destroy(g_ion_client);

	for (i = 0; i < uiHeapCount; i++) {
		if (g_apsIonHeaps[i])
		{
				ion_heap_destroy(g_apsIonHeaps[i]);
		}
	}
	kfree(g_apsIonHeaps);
	ion_device_destroy(g_psIonDev);
}

struct ion_client *MTKGetIonClient(void)
{
	return g_ion_client;
}

#else
extern struct ion_device *g_ion_device;

static struct ion_client *g_ion_client;

PVRSRV_ERROR IonInit(void *phPrivateData)
{
	g_ion_client = ion_client_create(g_ion_device, "RGX");

	return PVRSRV_OK;
}

struct ion_device *IonDevAcquire(void)
{
	return g_ion_device;
}

void IonDevRelease(struct ion_device *psIonDev)
{
	/* Nothing to do, sanity check the pointer we're passed back */
	PVR_ASSERT(psIonDev == g_ion_device);
}

void IonDeinit(void)
{
	ion_client_destroy(g_ion_client);
}

struct ion_client *MTKGetIonClient(void)
{
	return g_ion_client;
}
#endif