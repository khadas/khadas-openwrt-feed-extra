# spi update write

write data to spi flash write data by blocks 
rewrite blocks only is diff

## USAGE

    [VARS] spiupdate OUT < INPUT_image

    gzip -dc VIM2.krescue.spi.img.gz | RATE=10 spiupdate /dev/mtdblock0  ; echo $?

## ARGS and VARS

+ NL   - progress new line
+ RATE - output rate
+ SIZE - output size
+ OUT  - /dev/mtdblock0

## GET && BUILD

## AUTHOR

\## hyphop ##

## LICENSE

    cat ./LICENSE