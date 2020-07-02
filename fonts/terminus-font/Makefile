## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=terminus-font
PKG_VERSION:=4.48
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/terminus-font
PKG_HASH:=34799c8dd5cec7db8016b4a615820dfb43b395575afbb24fc17ee19c869c94af
PKG_LICENSE:=Terminus Font is licensed under the SIL Open Font License, Version 1.1
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=hyphop <art@khadas.com>

include $(INCLUDE_DIR)/package.mk

define Package/terminus-font
  TITLE:=terminus-font
  SECTION:=fonts
  CATEGORY:=Fonts
  SUBMENU:=DejaVu
  URL:=http://dejavu.sourceforge.net/
endef

MAKE_FLAGS += ter-v32n.psf
MAKE_FLAGS += ter-v32b.psf

#define Build/Compile
#	true
#endef

define Build/Configure
	true
endef

define Package/terminus-font/description
    terminus-font
endef

define Package/terminus-font/install
	$(INSTALL_DIR) $(1)/usr/share/fonts/psf
	$(CP) $(PKG_BUILD_DIR)/*.psf $(1)/usr/share/fonts/psf
endef

$(eval $(call BuildPackage,terminus-font))
