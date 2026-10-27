#ifndef VITA_MISSING_H
#define VITA_MISSING_H

#ifdef __cplusplus
extern "C" {
#endif

/* SceShellUtil, NID 0x636544FB. No stub in vitasdk: see vita_missing.c */
int sceShellUtilRequestColdReset(int flag);

/* SceRegMgrForSDK (inside the SceRegistryMgr stub), NID 0x8154D696 */
int sceRegMgrUtilityGetInt(int id, int *value);

/* SceAVConfig, NID 0x830B950B and 0xC411D984 */
int sceAVConfigGetVolCtrlEnable(unsigned int *ctrl, int *muted, int *avls);
int sceAVConfigWriteRegSystemVol(int volume);

#ifndef SCE_AVCONFIG_VOLUME_AVLS_MAX
#define SCE_AVCONFIG_VOLUME_AVLS_MAX 21
#endif

/* SceVshBridge, NID 0xC114F160 */
int vshPowerSetPsButtonPushTime(int push_time_us);

/* SceLibKernel, NID 0x2E581B88 */
long long sceClibStrtoll(const char *str, char **endptr, int base);

#ifdef __cplusplus
}
#endif

#endif /* VITA_MISSING_H */
