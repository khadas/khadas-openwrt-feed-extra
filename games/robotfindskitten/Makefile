# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=robotfindskitten
PKG_VERSION:=e959478639e4145837223eae0802feaa13467ad3
PKG_RELEASE:=1

PKG_HASH:=601cf847d6d5a5fffcbcb97852c45d2cbcc86bf819266666c9f2bcc4d3aecb2f
PKG_SOURCE_URL=https://codeload.github.com/hyphop/$(PKG_NAME)/tar.gz/$(PKG_VERSION)?
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

PKG_MAINTAINER:=hyphop <art@khadas.com>

PKG_LICENSE:=GPL-3.0+
PKG_LICENSE_FILES:=COPYING

#PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/robotfindskitten
  SECTION:=games
  CATEGORY:=Games
  SUBMENU:=Filesystem
  DEPENDS:=+libstdcpp +libncurses
  TITLE:=robot finds kitten
  URL:=http://robotfindskitten.org
endef

define Package/robotfindskitten/description
	https://en.wikipedia.org/wiki/Robotfindskitten 
endef

define Package/robotfindskitten/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_DIR) $(1)/usr/share/games/robotfindskitten
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/robotfindskitten $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/vanilla.nki $(1)/usr/share/games/robotfindskitten
endef

$(eval $(call BuildPackage,robotfindskitten))

