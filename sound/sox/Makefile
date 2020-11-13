
include $(TOPDIR)/rules.mk

PKG_NAME:=sox
PKG_VERSION:=15.5.5
PKG_VERSION2:=0be259eaa9ce3f3fa587a3ef0cf2c0b9c73167a2
PKG_VERSION2:=21ac447002cebcf866a5c88ebe02dd15dbb0cd84
PKG_RELEASE:=5

PKG_HASH:=795e90314462e4b0f028d731c748d52aa95391688a09c5ef9752d1cddb5b8072
PKG_HASH:=a6c90ad6d5d3ffd3bd3a9e298af3dbd5
PKG_SOURCE_URL=https://codeload.github.com/mansr/$(PKG_NAME)/tar.gz/$(PKG_VERSION2)?
PKG_SOURCE_URL=https://codeload.github.com/hyphop/$(PKG_NAME)/tar.gz/$(PKG_VERSION2)?
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION2).tar.gz
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION2)

PKG_MAINTAINER:=hyphop
PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

TARGET_LDFLAGS+= \
	-Wl,-rpath-link=$(STAGING_DIR)/usr/lib

define Package/sox
  SECTION:=sound
  CATEGORY:=Sound
  DEPENDS:=+libmad +libid3tag +libmagic +libvorbis +alsa-lib +libflac +libopus +libopusfile
  TITLE:=Sox is a general purpose sound converter/player/recorder
  URL:=http://sox.sourceforge.net/
endef

define Package/sox/description
	custom SoX with dsd dsf dop support 
endef

CONFIGURE_ARGS += \
		--without-oss \
		--without-ao \
		--without-twolame \
		--without-lame \
		--with-alsa \
		--without-libltdl \
		--with-flac \
		--with-opus \
		--without-ladspa \
		--without-png \
		--without-sndfile \
		--with-id3tag \
		--disable-openmp

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/include \
		$(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(CP) \
		$(PKG_INSTALL_DIR)/usr/lib/libsox.{a,so*,la} \
		$(1)/usr/lib/
	$(INSTALL_DATA) \
		$(PKG_INSTALL_DIR)/usr/lib/pkgconfig/* \
		$(1)/usr/lib/pkgconfig/
endef

define Package/sox/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/bin/{play,rec,sox} $(1)/usr/bin/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libsox.so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,sox))
