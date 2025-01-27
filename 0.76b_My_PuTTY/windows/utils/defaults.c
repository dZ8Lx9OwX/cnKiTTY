/*
 * windefs.c: default settings that are specific to Windows.
 */

#include "putty.h"

#include <commctrl.h>

FontSpec *platform_default_fontspec(const char *name)
{
    if (!strcmp(name, "Font"))
        return fontspec_new("黑体", false, 12, GB2312_CHARSET);
    else
        return fontspec_new("", false, 0, 0);
}

Filename *platform_default_filename(const char *name)
{
    if (!strcmp(name, "LogFileName"))
#ifdef MOD_PERSO
	return filename_from_str("kitty.log");
#else
	return filename_from_str("putty.log");
#endif
    else
	return filename_from_str("");
}

char *platform_default_s(const char *name)
{
    if (!strcmp(name, "SerialLine"))
	return dupstr("COM1");
    return NULL;
}

bool platform_default_b(const char *name, bool def)
{
    return def;
}

int platform_default_i(const char *name, int def)
{
    return def;
}
