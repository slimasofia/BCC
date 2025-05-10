.PHONY: clean image
SOURCE = logica

all: image

floppy.img:
	dd if=/dev/zero of=$@ bs=512 count=2880

$(SOURCE).o: $(SOURCE).s
	as $< -o $@

$(SOURCE).bin: $(SOURCE).o
	ld --Ttext 0x7c00 --oformat=binary $(SOURCE).o -o $(SOURCE).bin


image: $(SOURCE).bin floppy.img
	dd if=$(SOURCE).bin of=floppy.img bs=512 count=1 conv=notrunc


clean:
	$(RM) -f floppy.img
	$(RM) -f $(SOURCE).o
	$(RM) -f $(SOURCE).bin
