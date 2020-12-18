# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pixz
PKG_VERSION:=1.0.6
PKG_VERSION:=1.0.7.1
PKG_VERSION2:=3c7e8bc68c8443f5bc7cf685c3d4274cfcf64da9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL=https://github.com/vasi/$(PKG_NAME)/releases/download/v$(PKG_VERSION)/
PKG_SOURCE_URL=https://codeload.github.com/vasi/$(PKG_NAME)/tar.gz/$(PKG_VERSION2)?

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION2).tar.gz
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION2)

PKG_HASH:=f6dc5909c9a31b192f69aa397ae8df48
PKG_HASH:=27365b9d27e7f3b3d98193f8194e3ee0

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

