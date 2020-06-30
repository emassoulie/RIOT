PKG_NAME=kissfft
PKG_URL=https://github.com/mborgerding/kissfft
PKG_VERSION=master
PKG_LICENSE=BSD-3-Clause

include $(RIOTBASE)/pkg/pkg.mk

all:
	"$(MAKE)" -C $(PKG_SOURCE_DIR) -f $(CURDIR)/Makefile.$(PKG_NAME)
	"$(MAKE)" -C $(PKG_SOURCE_DIR)/tools -f $(CURDIR)/Makefile.$(PKG_NAME)_tools
