
include $(TOPDIR)/rules.mk

PKG_NAME:=saugns
PKG_VERSION2:=6bb0653ed03edd2593505417296c46d5bca15b17
PKG_VERSION:=0.1
PKG_RELEASE:=1

PKG_HASH:=0e8c3c30d26b0897ab9fb437bf917257
PKG_SOURCE_URL=https://codeload.github.com/hyphop/$(PKG_NAME)/tar.gz/$(PKG_VERSION2)?
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION2).tar.gz
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION2)

PKG_MAINTAINER:=hyphop
PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/saugns
  SECTION:=sound
  CATEGORY:=Sound
  DEPENDS:=+alsa-lib
  TITLE:=Scriptable AUdio GeNeration System
  URL:=https://github.com/saugns/saugns
endef

define Package/saugns/description
	saugns is the Scriptable AUdio GeNeration System, the implementation of the SAU (Scriptable AUdio) language.
endef

define Package/saugns/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(CP) $(PKG_INSTALL_DIR)/usr/local/bin/saugns $(1)/usr/bin/
endef

$(eval $(call BuildPackage,saugns))
