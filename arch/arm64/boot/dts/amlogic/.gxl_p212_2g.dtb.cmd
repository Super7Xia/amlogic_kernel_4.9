cmd_arch/arm64/boot/dts/amlogic/gxl_p212_2g.dtb := mkdir -p arch/arm64/boot/dts/amlogic/ ; aarch64-linux-gnu-gcc -E -Wp,-MD,arch/arm64/boot/dts/amlogic/.gxl_p212_2g.dtb.d.pre.tmp -nostdinc -I./arch/arm64/boot/dts -I./arch/arm64/boot/dts/include -I./drivers/of/testcase-data -undef -D__DTS__ -x assembler-with-cpp -o arch/arm64/boot/dts/amlogic/.gxl_p212_2g.dtb.dts.tmp arch/arm64/boot/dts/amlogic/gxl_p212_2g.dts ; ./scripts/dtc/dtc -O dtb -o arch/arm64/boot/dts/amlogic/gxl_p212_2g.dtb -b 0 -i arch/arm64/boot/dts/amlogic/ -Wno-unit_address_vs_reg -d arch/arm64/boot/dts/amlogic/.gxl_p212_2g.dtb.d.dtc.tmp arch/arm64/boot/dts/amlogic/.gxl_p212_2g.dtb.dts.tmp ; cat arch/arm64/boot/dts/amlogic/.gxl_p212_2g.dtb.d.pre.tmp arch/arm64/boot/dts/amlogic/.gxl_p212_2g.dtb.d.dtc.tmp > arch/arm64/boot/dts/amlogic/.gxl_p212_2g.dtb.d

source_arch/arm64/boot/dts/amlogic/gxl_p212_2g.dtb := arch/arm64/boot/dts/amlogic/gxl_p212_2g.dts

deps_arch/arm64/boot/dts/amlogic/gxl_p212_2g.dtb := \
  arch/arm64/boot/dts/include/dt-bindings/interrupt-controller/arm-gic.h \
  arch/arm64/boot/dts/include/dt-bindings/interrupt-controller/irq.h \
  arch/arm64/boot/dts/amlogic/mesongxl.dtsi \
  arch/arm64/boot/dts/include/dt-bindings/reset/amlogic,gxl-reset.h \
  arch/arm64/boot/dts/include/dt-bindings/clock/amlogic,gxl-clkc.h \
  arch/arm64/boot/dts/include/dt-bindings/gpio/gxl.h \
  arch/arm64/boot/dts/include/dt-bindings/gpio/gpio.h \
  arch/arm64/boot/dts/include/dt-bindings/pwm/meson.h \
  arch/arm64/boot/dts/include/dt-bindings/input/input.h \
  arch/arm64/boot/dts/include/dt-bindings/input/linux-event-codes.h \
  arch/arm64/boot/dts/include/dt-bindings/input/meson_rc.h \
  arch/arm64/boot/dts/include/dt-bindings/pwm/pwm.h \
  arch/arm64/boot/dts/amlogic/mesongxbb-gpu-mali450.dtsi \

arch/arm64/boot/dts/amlogic/gxl_p212_2g.dtb: $(deps_arch/arm64/boot/dts/amlogic/gxl_p212_2g.dtb)

$(deps_arch/arm64/boot/dts/amlogic/gxl_p212_2g.dtb):
