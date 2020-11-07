#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

## broken boost lib

include $(TOPDIR)/rules.mk

PKG_NAME:=ncmpcpp
PKG_VERSION:=0.8.2
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
#PKG_SOURCE_URL:=git://github.com/notandy/ympd.git
PKG_SOURCE_URL:=git://github.com/arybczak/ncmpcpp.git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=31ee76e8eee0cdc953f85d6c9369fb0aca010889
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz
PKG_MAINTAINER:=hyphop
CMAKE_INSTALL:=1

#PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
#PKG_HASH:=3e23b16c469f849b21a5a1854076bb4b

PKG_LICENSE:=GPL-2.0+
PKG_LICENSE_FILES:=COPYING
PKG_MAINTAINER:=hyphop

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
#include $(INCLUDE_DIR)/nls.mk

define Package/ncmpcpp
  SECTION:=sound
  CATEGORY:=Sound
  DEPENDS:=+libmpdclient +glib2 +libncursesw
  TITLE:=Music Player Daemon Console Client
  URL:=http://www.musicpd.org/
endef

define Package/ncmpcpp/description
	MPD is a music player supporting flac, mp3 and ogg files.
	It is typically controlled over a network using one of it's many
	clients including mpc(console), gmpc(gnome), phpmp(php) etc.
	this is MPC
endef

define Build/Configure
$(call Build/Configure/Default, \
	--disable-iconv \
)
endef

define Build/Compile
$(call Build/Compile/Default,\
		CFLAGS="$(TARGET_CFLAGS) -std=gnu99" \
		prefix="/usr" \
		all \
)
endef

define Package/ncmpcpp/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/ncmpcpp $(1)/usr/bin/
#	$(INSTALL_BIN) ./files/pls-handler.sh $(1)/usr/bin/
endef

$(eval $(call BuildPackage,ncmpcpp))
