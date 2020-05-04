include $(TOPDIR)/rules.mk

PKG_NAME:=ranga-usb-common
PKG_VERSION:=1.0
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/ranga-usb-common
  SECTION:=ranga
  CATEGORY:=NSWA Ranga
  SUBMENU:=Extra
  DEPENDS:=+kmod-usb-storage +libpthread +@BUILD_PATENTED +kmod-fs-vfat +kmod-fs-exfat +aria2 +ca-bundle +samba36-server
  TITLE:=NSWA USB comment
endef

define Package/ranga-usb-common/description
  USB
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	cp -r ./src $(PKG_BUILD_DIR)/src
	$(Build/Patch)
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/src/aumount $(TARGET_LDFLAGS) $(PKG_BUILD_DIR)/src/aumount.c -pthread
endef

define Package/ranga-usb-common/install
	cp -r ./files/. $(1)/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/aumount $(1)/lib/ranga/libexec/
endef

$(eval $(call BuildPackage,ranga-usb-common))
