
include $(TOPDIR)/rules.mk

PKG_NAME:=saugns
PKG_VERSION2:=c175b4a4e979406ac8a2187b69677a3102205553
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_HASH:=a6c90ad6d5d3ffd3bd3a9e298af3dbd5
PKG_SOURCE_URL=https://codeload.github.com/$(PKG_NAME)/$(PKG_NAME)/tar.gz/$(PKG_VERSION2)?
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION2).tar.gz
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION2)

PKG_MAINTAINER:=hyphop
PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/saugns
  SECTION:=sound
  CATEGORY:=Sound
  TITLE:=Scriptable AUdio GeNeration System
  URL:=https://github.com/saugns/saugns
endef

define Package/saugns/description
	saugns is the Scriptable AUdio GeNeration System, the implementation of the SAU (Scriptable AUdio) language.
endef

define Package/saugns/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(CP) $(PKG_INSTALL_DIR)/usr/bin/{saugns} $(1)/usr/bin/
endef

$(eval $(call BuildPackage,saugns))
