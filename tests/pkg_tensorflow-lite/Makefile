# Ensure minimal size by default
DEVELHELP ?= 0

WERROR = 0

include ../Makefile.tests_common

# Other available example: hello_world, mnist
EXAMPLE ?= micro_speech

USEPKG += tensorflow-lite
USEPKG += kissfft

# internal mnist example is available as an external module
ifneq (hello_world,$(EXAMPLE))
  # TensorFlow-Lite crashes on M4/M7 CPUs when FPU is enabled, so disable it by
  # default for now
  DISABLE_MODULE += cortexm_fpu

  CXXEXFLAGS += -Wno-type-limits

  USEMODULE += tensorflow-lite-$(EXAMPLE)
  USEMODULE += tensorflow-liite-micro_features
  USEMODULE += tensorflow-liite-micro_frontend
  USEMODULE += tensorflow-liite-micro_frontend_lib
  USEMODULE += tensorflow-liite-micro_frontend_ops
  # USEMODULE += $(EXAMPLE)
  # EXTERNAL_MODULE_DIRS += $(CURDIR)/$(EXAMPLE)
else
  # Use upstream example
  USEMODULE += tensorflow-lite-$(EXAMPLE)
endif

include $(RIOTBASE)/Makefile.include
