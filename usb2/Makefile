include $(TOPDIR)/rules.mk

PKG_NAME:=ranga-usb2
PKG_VERSION:=1.0
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/ranga-usb2
  SECTION:=ranga
  CATEGORY:=NSWA Ranga
  SUBMENU:=Extra
  DEPENDS:=+kmod-usb2 +ranga-usb-common
  TITLE:=NSWA USB 2.0 support
endef

define Package/ranga-usb2/description
  USB 2.0
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Compile
	true
endef

define Package/ranga-usb2/install
	cp -r ./files/. $(1)/
	true
endef

$(eval $(call BuildPackage,ranga-usb2))
