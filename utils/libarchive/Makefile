#
# Copyright (C) 2014 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

## hyphop ##

include $(TOPDIR)/rules.mk

PKG_NAME:=libarchive
PKG_VERSION:=3.4.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://www.libarchive.org/downloads
PKG_HASH:=0bfc3fd40491768a88af8d9b86bf04a9e95b6d41a94f9292dbc0ec342288c05f

PKG_MAINTAINER:=Johannes Morgenroth <morgenroth@ibr.cs.tu-bs.de>

#PKG_MAINTAINER:=hyphop <art@khadas.com>

PKG_LICENSE:=BSD-2-Clause
PKG_LICENSE_FILES:=COPYING
PKG_CPE_ID:=cpe:/a:libarchive:libarchive

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libarchive/Default
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+zlib +liblzma
  TITLE:=Multi-format archive and compression library
  URL:=https://www.libarchive.org/
endef

define Package/libarchive
  $(call Package/libarchive/Default)
  DEPENDS += +libopenssl +libexpat +libbz2
endef

define Package/libarchive-noopenssl
  $(call Package/libarchive/Default)
  DEPENDS += +libexpat +libbz2
  TITLE += (without OpenSSL dependency)
  VARIANT:=noopenssl
endef

define Package/libarchive-custom
  $(call Package/libarchive/Default)
  DEPENDS += +libzstd
  TITLE += (custom without ssl expat bz2)
  VARIANT:=custom
endef

define Package/bsdtar/Default
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Compression
  TITLE:=tar BSD variant
  URL:=https://www.libarchive.org/
endef

define Package/bsdtar
  $(call Package/bsdtar/Default)
  DEPENDS:= +libarchive
endef

define Package/bsdtar-noopenssl
  $(call Package/bsdtar/Default)
  TITLE += (without OpenSSL dependency)
  DEPENDS:= +libarchive-noopenssl
  VARIANT:=noopenssl
endef

define Package/bsdtar-custom
  $(call Package/bsdtar/Default)
  TITLE += (custom)
  DEPENDS:= +libarchive-custom
  VARIANT:=custom
endef

define Package/bsdtar/description
  Reads a variety of formats including tar, pax, zip, xar, lha, ar,
  cab, mtree, rar, warc, 7z and ISO images. Writes tar, pax, zip,
  xar, ar, ISO, mtree and shar archives. Automatically handles
  archives compressed with gzip, bzip2, lzip, xz, lzma or compress.
endef

CONFIGURE_ARGS += \
	--enable-bsdtar=shared \
	--disable-bsdcpio \
	--disable-rpath \
	--disable-acl \
	--disable-xattr \
	--without-cng \
	--without-iconv \
	--without-lz4 \
	--without-lzo2 \
	--without-nettle \
	--without-xml2

ifeq ($(BUILD_VARIANT),noopenssl)
	CONFIGURE_ARGS += --without-openssl --without-zstd
else
ifeq ($(BUILD_VARIANT),custom)
	CONFIGURE_ARGS += --without-openssl --without-bz2lib --without-expat
else
	CONFIGURE_ARGS += --with-openssl --without-zstd
endif
endif

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/* $(1)/usr/lib/
endef

define Package/libarchive/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/*.so.* $(1)/usr/lib/
endef

define Package/bsdtar/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(CP) $(PKG_INSTALL_DIR)/usr/bin/bsdtar $(1)/usr/bin
endef

Package/libarchive-noopenssl/install = $(Package/libarchive/install)
Package/bsdtar-noopenssl/install = $(Package/bsdtar/install)
Package/libarchive-custom/install = $(Package/libarchive/install)
Package/bsdtar-custom/install = $(Package/bsdtar/install)

#$(eval $(call BuildPackage,libarchive))
#$(eval $(call BuildPackage,libarchive-noopenssl))
$(eval $(call BuildPackage,libarchive-custom))
#$(eval $(call BuildPackage,bsdtar))
#$(eval $(call BuildPackage,bsdtar-noopenssl))
$(eval $(call BuildPackage,bsdtar-custom))
