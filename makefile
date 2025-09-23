NAME = DVD_CE
ICON = icon.png
DESCRIPTION = "The classic DVD screensaver, now for the CE!"

COMPRESSED = YES
ARCHIVED = YES

MAKE_GFX = cd $(GFXDIR) && $(CONVIMG)

include $(shell cedev-config --makefile)