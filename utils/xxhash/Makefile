# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=xxhash
PKG_VERSION:=0.7.2
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://github.com/hyphop/$(PKG_NAME)
PKG_SOURCE_VERSION:=70e88e869afdbf45b1c96e8d85202b3081724558

PKG_MAINTAINER:=hyphop <art@khadas.com>

PKG_LICENSE:=GPL-2.0
PKG_LICENSE_FILES:=COPYING

include $(INCLUDE_DIR)/package.mk

define Package/xxhash
  SUBMENU:=Compression
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=xxhash
  URL:=http://cyan4973.github.io/xxHash/
endef

define Package/xxhash/Description
 xxHash is an extremely fast non-cryptographic hash algorithm, working at speeds close to RAM limits. It is proposed in two flavors, 32 and 64 bits.
endef


define Package/xxhash/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/xxhsum $(1)/usr/bin
endef

$(eval $(call BuildPackage,xxhash))
