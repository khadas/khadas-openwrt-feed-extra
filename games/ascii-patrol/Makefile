# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ascii-patrol
PKG_VERSION:=af138857385002161b722bf49ce7f231d7bdd2da
PKG_RELEASE:=1

PKG_HASH:=a6ccbbd17bb6e008683b96474cc7fc250189043c38a0baae5adf141aa3c6b7a5
PKG_SOURCE_URL=https://codeload.github.com/hyphop/$(PKG_NAME)/tar.gz/$(PKG_VERSION)?
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

PKG_MAINTAINER:=hyphop <art@khadas.com>

PKG_LICENSE:=GPL-3.0+
PKG_LICENSE_FILES:=COPYING

#PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/ascii-patrol
  SECTION:=games
  CATEGORY:=Games
  SUBMENU:=Filesystem
  DEPENDS:=+libstdcpp +libpthread
  TITLE:=ascii-patrol - terminal moon-patrol clone
  URL:=http://ascii-patrol.com/
endef

define Package/ascii-patrol/description
	ascii-patrol - terminal moon-patrol clone
endef

define Package/ascii-patrol/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/asciipat $(1)/usr/bin
endef

$(eval $(call BuildPackage,ascii-patrol))

