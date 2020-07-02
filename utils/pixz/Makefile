# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pixz
PKG_VERSION:=1.0.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL=https://github.com/vasi/$(PKG_NAME)/releases/download/v$(PKG_VERSION)/
PKG_HASH:=f6dc5909c9a31b192f69aa397ae8df48

PKG_MAINTAINER:=hyphop <art@khadas.com>

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/pixz
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Compression
  TITLE:=pixz
  URL:=https://github.com/vasi/pixz
  DEPENDS:=+liblzma +libarchive-custom
endef

define Package/pixz/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/pixz $(1)/usr/bin/pixz
endef

$(eval $(call BuildPackage,pixz))

