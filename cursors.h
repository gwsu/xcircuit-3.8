/*------------------------------------------------------------------*/
/* cursors.h --- definitions for bitmapped cursors used by xcircuit */
/* Copyright (c) 2002  Tim Edwards, Johns Hopkins University        */
/*------------------------------------------------------------------*/

#define arrow_width 16
#define arrow_height 18
#define arrow_x_hot 0
#define arrow_y_hot 1
static u_char arrow_bits[] = {
   0x00, 0x00, 0x01, 0x00, 0x07, 0x00, 0x1e, 0x00, 0xfe, 0x00, 0xfc, 0x07,
   0xfc, 0x01, 0x78, 0x00, 0xf8, 0x00, 0xb8, 0x01, 0x10, 0x03, 0x10, 0x06,
   0x00, 0x0c, 0x00, 0x18, 0x00, 0x30, 0x00, 0x60, 0x00, 0x20, 0x00, 0x00};
static u_char arrowmask_bits[] = {
   0x00, 0x00, 0x07, 0x00, 0x1f, 0x00, 0xff, 0x00, 0xfe, 0x07, 0xfe, 0x0f,
   0xfc, 0x07, 0xfc, 0x01, 0xfc, 0x01, 0xf8, 0x03, 0xb8, 0x07, 0x38, 0x0f,
   0x10, 0x1e, 0x00, 0x3c, 0x00, 0x78, 0x00, 0xf0, 0x00, 0x70, 0x00, 0x20};
#define scissors_width 20
#define scissors_height 14
#define scissors_x_hot 8
#define scissors_y_hot 6
static u_char scissors_bits[] = {
   0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x1c, 0xc0, 0x03, 0xf0, 0x20, 0x04,
   0xc0, 0x23, 0x04, 0x00, 0xaf, 0x03, 0xff, 0x7b, 0x00, 0xfe, 0x3f, 0x00,
   0x00, 0xe0, 0x01, 0x00, 0x80, 0x02, 0x00, 0x40, 0x04, 0x00, 0x40, 0x04,
   0x00, 0x80, 0x03, 0x00, 0x00, 0x00};
static u_char scissorsmask_bits[] = {
   0x06, 0x00, 0x00, 0x1f, 0xc0, 0x03, 0xfe, 0xe0, 0x07, 0xfc, 0x73, 0x0e,
   0xf0, 0x3f, 0x0c, 0xc0, 0xff, 0x07, 0xff, 0xfb, 0x03, 0xff, 0xff, 0x01,
   0xfe, 0xff, 0x03, 0x00, 0xe0, 0x07, 0x00, 0x60, 0x0c, 0x00, 0xe0, 0x0e,
   0x00, 0xc0, 0x07, 0x00, 0x80, 0x03};
#define cross_width 17
#define cross_height 17
#define cross_x_hot 8
#define cross_y_hot 8
static u_char cross_bits[] = {
   0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
   0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
   0xff, 0xff, 0x01, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
   0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,
   0x00, 0x01, 0x00};
static u_char crossmask_bits[] = {
   0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00,
   0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0xff, 0xff, 0x01,
   0xff, 0xff, 0x01, 0xff, 0xff, 0x01, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00,
   0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00,
   0x80, 0x03, 0x00};
#define copy_width 17
#define copy_height 17
#define copy_x_hot 8
#define copy_y_hot 8
static u_char copy_bits[] = {
   0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x03, 0x80, 0x01, 0x07, 0xc0, 0x01,
   0x0d, 0x60, 0x01, 0x19, 0x30, 0x01, 0x31, 0x18, 0x01, 0x61, 0x0c, 0x01,
   0xc1, 0x06, 0x01, 0x61, 0x0c, 0x01, 0x31, 0x18, 0x01, 0x19, 0x30, 0x01,
   0x0d, 0x60, 0x01, 0x07, 0xc0, 0x01, 0x03, 0x80, 0x01, 0x01, 0x00, 0x01,
   0x00, 0x00, 0x00};
static u_char copymask_bits[] = {
   0x01, 0x00, 0x01, 0x03, 0x80, 0x01, 0x07, 0xc0, 0x01, 0x0f, 0xe0, 0x01,
   0x1f, 0xf0, 0x01, 0x3d, 0x78, 0x01, 0x79, 0x3c, 0x01, 0xf1, 0x1e, 0x01,
   0xe1, 0x0e, 0x01, 0xf1, 0x1e, 0x01, 0x79, 0x3c, 0x01, 0x3d, 0x78, 0x01,
   0x1f, 0xf0, 0x01, 0x0f, 0xe0, 0x01, 0x07, 0xc0, 0x01, 0x03, 0x80, 0x01,
   0x01, 0x00, 0x01};
#define question_width 17
#define question_height 17
#define question_x_hot 8
#define question_y_hot 5
static u_char question_bits[] = {
   0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0xe0, 0x0f, 0x00, 0x70, 0x1c, 0x00,
   0x30, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x0e, 0x00,
   0x00, 0x07, 0x00, 0x80, 0x03, 0x00, 0x80, 0x01, 0x00, 0x80, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x80, 0x01, 0x00,
   0x00, 0x00, 0x00};
static u_char questionmask_bits[] = {
   0xc0, 0x07, 0x00, 0xe0, 0x0f, 0x00, 0xf0, 0x1f, 0x00, 0x70, 0x3c, 0x00,
   0x70, 0x38, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x0f, 0x00,
   0x80, 0x07, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x01, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x01, 0x00,
   0x00, 0x00, 0x00};
#define circle_width 17
#define circle_height 17
#define circle_x_hot 8
#define circle_y_hot 8
static u_char circle_bits[] = {
   0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x70, 0x1c, 0x00, 0x18, 0x30, 0x00,
   0x0c, 0x60, 0x00, 0x04, 0x40, 0x00, 0x06, 0xc0, 0x00, 0x82, 0x83, 0x00,
   0x82, 0x83, 0x00, 0x82, 0x83, 0x00, 0x06, 0xc0, 0x00, 0x04, 0x40, 0x00,
   0x0c, 0x60, 0x00, 0x18, 0x30, 0x00, 0x70, 0x1c, 0x00, 0xc0, 0x07, 0x00,
   0x00, 0x00, 0x00};
static u_char circlemask_bits[] = {
   0xc0, 0x07, 0x00, 0xf0, 0x1f, 0x00, 0x7c, 0x7c, 0x00, 0x1c, 0x70, 0x00,
   0x0e, 0xe0, 0x00, 0x06, 0xc0, 0x00, 0x07, 0xc1, 0x01, 0x83, 0x83, 0x01,
   0xc3, 0x87, 0x01, 0x83, 0x83, 0x01, 0x07, 0xc1, 0x01, 0x06, 0xc0, 0x00,
   0x0e, 0xe0, 0x00, 0x1c, 0x70, 0x00, 0x7c, 0x7c, 0x00, 0xf0, 0x1f, 0x00,
   0xc0, 0x07, 0x00};
#define exx_width 17
#define exx_height 17
#define exx_x_hot 8
#define exx_y_hot 8
static u_char exx_bits[] = {
   0x00, 0x00, 0x00, 0x06, 0xc0, 0x00, 0x0e, 0xe0, 0x00, 0x1c, 0x70, 0x00,
   0x18, 0x38, 0x00, 0x30, 0x08, 0x00, 0x40, 0x04, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x04, 0x00, 0x20, 0x18, 0x00,
   0x38, 0x30, 0x00, 0x1c, 0x70, 0x00, 0x0e, 0xe0, 0x00, 0x06, 0xc0, 0x00,
   0x00, 0x00, 0x00};
static u_char exxmask_bits[] = {
   0x0f, 0xe0, 0x01, 0x1f, 0xf0, 0x01, 0x3f, 0xf8, 0x01, 0x3f, 0xfc, 0x01,
   0x7e, 0xfc, 0x00, 0xfc, 0x7e, 0x00, 0xf8, 0x1e, 0x00, 0xe0, 0x0e, 0x00,
   0x00, 0x00, 0x00, 0xe0, 0x0e, 0x00, 0xf0, 0x3e, 0x00, 0xfc, 0x7e, 0x00,
   0x7e, 0xfc, 0x00, 0x7f, 0xf8, 0x01, 0x3f, 0xf8, 0x01, 0x1f, 0xf0, 0x01,
   0x0f, 0xe0, 0x01};
#define rot_width 17
#define rot_height 17
static u_char rot_bits[] = {
   0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0xf0, 0x1f, 0x00, 0x78, 0x3d, 0x00,
   0x1c, 0x71, 0x00, 0x0c, 0x61, 0x00, 0x0e, 0xe1, 0x00, 0x06, 0xc1, 0x00,
   0x06, 0xc1, 0x00, 0x06, 0xc1, 0x00, 0x0e, 0xe1, 0x00, 0x0c, 0x61, 0x00,
   0x1c, 0x71, 0x00, 0x78, 0x3d, 0x00, 0xf0, 0x1f, 0x00, 0xc0, 0x07, 0x00,
   0x00, 0x00, 0x00};
static u_char rotmask_bits[] = {
   0xc0, 0x07, 0x00, 0xf0, 0x1f, 0x00, 0xf8, 0x3f, 0x00, 0xfc, 0x7f, 0x00,
   0xfe, 0xff, 0x00, 0x9e, 0xf3, 0x00, 0x9f, 0xf3, 0x01, 0x8f, 0xe3, 0x01,
   0x8f, 0xe3, 0x01, 0x8f, 0xe3, 0x01, 0x9f, 0xf3, 0x01, 0x9e, 0xf3, 0x00,
   0xfe, 0xff, 0x00, 0xfc, 0x7f, 0x00, 0xf8, 0x3f, 0x00, 0xf0, 0x1f, 0x00,
   0xc0, 0x07, 0x00};
#define hand_width 20
#define hand_height 20
#define hand_x_hot 7
#define hand_y_hot 12
static unsigned char hand_bits[] = {
   0x80, 0x0d, 0x00, 0xb0, 0x0d, 0x00, 0xb0, 0x0d, 0x00, 0xb0, 0x0d, 0x00,
   0xb6, 0x0d, 0x00, 0xb6, 0x0d, 0x00, 0xb6, 0x0d, 0x00, 0xf6, 0x0f, 0x03,
   0xfe, 0x8f, 0x03, 0xfe, 0xcf, 0x03, 0xfc, 0xef, 0x01, 0xfc, 0xef, 0x00,
   0xfc, 0xff, 0x00, 0xfc, 0x7f, 0x00, 0xfc, 0x3f, 0x00, 0xf8, 0x1f, 0x00,
   0xf8, 0x1f, 0x00, 0xf0, 0x0f, 0x00, 0xe0, 0x0f, 0x00, 0xe0, 0x0f, 0x00};
static unsigned char handmask_bits[] = {
   0x80, 0x0d, 0x00, 0xb0, 0x0d, 0x00, 0xb0, 0x0d, 0x00, 0xb0, 0x0d, 0x00,
   0xb6, 0x0d, 0x00, 0xb6, 0x0d, 0x00, 0xb6, 0x0d, 0x00, 0xf6, 0x0f, 0x03,
   0xfe, 0x8f, 0x03, 0xfe, 0xcf, 0x03, 0xfc, 0xef, 0x01, 0xfc, 0xef, 0x00,
   0xfc, 0xff, 0x00, 0xfc, 0x7f, 0x00, 0xfc, 0x3f, 0x00, 0xf8, 0x1f, 0x00,
   0xf8, 0x1f, 0x00, 0xf0, 0x0f, 0x00, 0xe0, 0x0f, 0x00, 0xe0, 0x0f, 0x00};