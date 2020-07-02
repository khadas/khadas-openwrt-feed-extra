# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=vitetris
PKG_VERSION:=0.58.0
PKG_RELEASE:=1

PKG_SOURCE_URL=https://codeload.github.com/vicgeralds/$(PKG_NAME)/tar.gz/v$(PKG_VERSION)?
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_HASH:=e7e7cb74bb814b9fec80fe4ede3c3f04134d8217d630e092a097238248d604f9

PKG_MAINTAINER:=hyphop <art@khadas.com>

PKG_LICENSE:=GPL-3.0+
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Build/Configure
    ( cd $(PKG_BUILD_DIR); ./configure 2player=no joystick=no network=no allegro=no xlib=no term_resizing=no menu=no pctimer=no )
endef

define Package/vitetris
  SECTION:=games
  CATEGORY:=Games
  SUBMENU:=Filesystem
  TITLE:=VITETRIS - Virtual terminal *tris clone
  URL:=http://victornils.net/tetris
endef

define Package/vitetris/description
	terminal tetris
endef

define Package/vitetris/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/local/bin/tetris $(1)/usr/bin
endef

$(eval $(call BuildPackage,vitetris))
