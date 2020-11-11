#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("can not find your file!");
        return 1;
    }

    // Initialize and store file name
    char *img = argv[1]; //必须用指针指向argv，否则fopen将无法读取argv的文件
    
    //open a file
    FILE *file = fopen(img, "r"); 
    if(file == NULL){
        printf("can not open your file!");
        return 2;
    }

    //filename counter
    int filecount = 0;

    //define a null file
    FILE *picture = NULL;

    //check whether found a jpg yet or not
    int jpeg_found = 0;

    //read fisrt 4 bytes
    unsigned char buffer[512]; //此处必须用unsigned char，否则会出现一个奇怪的叫作“分割错误”的东西

    // go through(仔细检查) cardfile until there aren't any blocks left
    while(fread(buffer, 512, 1, file) == 1){
        //read first 4 bytes of buffer
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){

            if(jpeg_found == 1){
                // We found the start of a new pic so close out current picture
                fclose(picture);
            }
            else{
                // jepg has been found
                jpeg_found = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", filecount);
            picture = fopen(filename, "a");
            filecount++;
        }

        if(jpeg_found == 1){
            // write 512 bytes to file once we start finding jpegs
            fwrite(&buffer, 512, 1, picture);
        }
    }

    //close files
    fclose(file);
    fclose(picture);

    return 0;
}
