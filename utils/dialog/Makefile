# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=dialog
PKG_VERSION:=1.3-20171209
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).orig.tar.gz
PKG_SOURCE_URL:=https://launchpad.net/ubuntu/+archive/primary/+sourcefiles/dialog/$(PKG_VERSION)-1build1/
PKG_MD5SUM:=f66f28beca900b54f5fc90fdcce93508

PKG_MAINTAINER:=hyphop <art@khadas.com>

include $(INCLUDE_DIR)/package.mk

define Package/dialog
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libncurses
  TITLE:=Dialog
  URL:=http://invisible-island.net/dialog/
endef

define Package/dialog/description
 A script-interpreter which provides a set of curses widgets.
endef

define Package/dialog/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/dialog $(1)/usr/bin
endef

$(eval $(call BuildPackage,dialog))
