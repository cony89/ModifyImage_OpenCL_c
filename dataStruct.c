/* Created by Alessandro Bigiotti */

// A variable to show some error
int e = 0;

// The path to the image
char image[1082];

// The path to the results
char result[1082];
char result2[1082];
char result3[1082];
char result4[1082];

// Path to the current directory
char currentDirectory[1082];

// Mantaine the pixels of the image
ILubyte* data_raw;

// The image dimensions in pixels
unsigned int S;

// Pointer to a file
FILE *fp;

// A buffer to save the .cl source code
size_t source_size;
char *source_str;

// Path to the .cl file
char path_to_kernel[1082];

// Choose the type of kernel (single or combined)
int type_kernel;

// Selected filter_kernel
int filter_selected;

// Some possible Masks:
float smooth_mask[49] = { 1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1, 1, 1 };

float smooth_mask2[25] = { 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1 };

float gauss_mask[9] = { 1, 2, 1,
                        2, 4, 2,
                        1, 2, 1 };

float gauss_mask2[25] = {0, 1, 2, 1, 0,
                         1, 2, 4, 2, 1,
                         2, 4, 8, 4, 2,
                         1, 2, 4, 2, 1,
                         0, 2, 2, 1, 0 };

float sharpening[9] = {  0,-1, 0,
                        -1, 4,-1,
                         0,-1, 0 };

float prewitt_mask_Nord[9] = { -1,-1,-1,
                                0, 0, 0,
                                1, 1, 1 };

float prewitt_mask_Est[9] = {  -1, 0, 1,
                               -1, 0, 1,
                               -1, 0, 1 };

// A range to apply some filters
// 3 -> a 7x7 Mask
// 2 -> a 5x5 Mask
// 1 -> a 3x3 Mask
int range = 3;
int range1 = 2;
int range2 = 1;
// A moltiplication factor for median operation
float factor = 1;


///////////////////////////////////////////////////////////////////////////////
//       OPEN CL data

// A variable to show some possible error
cl_int err;

// The number of Configured platform and its id
cl_uint Num_Platform = 0;
cl_platform_id Platform_id[10];

// The number of Available Devices and its id
cl_uint Num_Device = 0;
cl_device_id Devices_id[10];

// OpenCL Context
cl_context context;

// OpenCL Command Queue
cl_command_queue commands;

// OpenCL Program
cl_program program;

// OpenCL Kernel
cl_kernel kernel_negativo;
cl_kernel binarizza;
cl_kernel kernel_mask_factor2;
cl_kernel kernel_mask_factor;
cl_kernel kernel_mask;
cl_kernel kernel_mask2;
cl_kernel kernel_mask3;
cl_kernel edge_detection;

// OpenCL Memory
cl_mem dev_image;
cl_mem out_put;
cl_mem out_put2;
cl_mem out_put3;
cl_mem out_put4;
cl_mem smooth;
cl_mem smooth2;
cl_mem mask_gaus;
cl_mem mask_gaus2;
cl_mem prewN;
cl_mem prewE;
cl_mem sharp;
