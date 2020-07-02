# ## hyphop ##
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=brcmfmac-khadas
PKG_VERSION:=2020-01-01
PKG_RELEASE:=1

PKG_OPENWRT_WIFI_FW:=openwrt_khadas_fw_vims.tar.xz

include $(INCLUDE_DIR)/package.mk

define Download/brcmfmac_khadas
  FILE:=$(PKG_OPENWRT_WIFI_FW)
  URL:=https://github.com/hyphop/pkg/releases/download/wlan-firmware-khadas/
  URL_FILE:=$(PKG_OPENWRT_WIFI_FW)
  HASH:=7e91a32352287668b52e402f273982c5e6775998d96acca3f547c802bb40def1
endef
$(eval $(call Download,brcmfmac_khadas))

PKG_MAINTAINER:=hyphop <art@khadas.com>

define Package/brcmfmac-khadas
  SECTION:=firmware
  CATEGORY:=Firmware
  URL:=https://github.com/khadas/fenix/tree/master/archives/hwpacks/wlan-firmware/brcm
  TITLE:=BCMxxxxx SDIO NVRAM
  PKGARCH:=all
endef

define Package/brcmfmac-khadas/description
  NVRAM for the Broadcom khadas boards
endef

define Build/Prepare
	rm -rf $(PKG_BUILD_DIR)
	mkdir -p $(PKG_BUILD_DIR)
	$(TAR) -xf $(DL_DIR)/$(PKG_OPENWRT_WIFI_FW) -C $(PKG_BUILD_DIR)/
endef

define Build/Compile
	true
endef

define Package/brcmfmac-khadas/install
#	$(INSTALL_DIR) $(1)/lib/firmware/brcm/
#	$(INSTALL_DATA) $(PKG_BUILD_DIR)/lib $(1)
	$(CP) -a $(PKG_BUILD_DIR)/lib $(1)
endef

$(eval $(call BuildPackage,brcmfmac-khadas))
