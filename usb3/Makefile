include $(TOPDIR)/rules.mk

PKG_NAME:=ranga-usb3
PKG_VERSION:=1.0
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/ranga-usb3
  SECTION:=ranga
  CATEGORY:=NSWA Ranga
  SUBMENU:=Extra
  DEPENDS:=+kmod-usb3 +ranga-usb-common
  TITLE:=NSWA USB 3.0 support
endef

define Package/ranga-usb3/description
  USB 3.0
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
endef

define Build/Compile
	true
endef

define Package/ranga-usb3/install
	cp -r ./files/. $(1)/
	true
endef

$(eval $(call BuildPackage,ranga-usb3))
