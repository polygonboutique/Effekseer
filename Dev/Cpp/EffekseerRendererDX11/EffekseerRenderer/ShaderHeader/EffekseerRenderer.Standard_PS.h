#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tps_4_0 /Emain /D __EFFEKSEER_BUILD_VERSION16__=1 /Fh
//    ShaderHeader/EffekseerRenderer.Standard_PS.h
//    Shader/standard_renderer_PS.fx
//
//
// Buffer Definitions: 
//
// cbuffer PS_ConstanBuffer
// {
//
//   float4 flipbookParameter;          // Offset:    0 Size:    16
//   float4 uvDistortionParameter;      // Offset:   16 Size:    16
//   float4 blendTextureParameter;      // Offset:   32 Size:    16
//   float4 emissiveScaling;            // Offset:   48 Size:    16
//   float4 edgeColor;                  // Offset:   64 Size:    16
//   float4 edgeParameter;              // Offset:   80 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_sampler                         sampler      NA          NA    0        1
// g_alphaSampler                    sampler      NA          NA    1        1
// g_uvDistortionSampler             sampler      NA          NA    2        1
// g_blendSampler                    sampler      NA          NA    3        1
// g_blendAlphaSampler               sampler      NA          NA    4        1
// g_blendUVDistortionSampler        sampler      NA          NA    5        1
// g_texture                         texture  float4          2d    0        1
// g_alphaTexture                    texture  float4          2d    1        1
// g_uvDistortionTexture             texture  float4          2d    2        1
// g_blendTexture                    texture  float4          2d    3        1
// g_blendAlphaTexture               texture  float4          2d    4        1
// g_blendUVDistortionTexture        texture  float4          2d    5        1
// PS_ConstanBuffer                  cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// COLOR                    0   xyzw        1     NONE  float   xyzw
// TEXCOORD                 0   xy          2     NONE  float   xy  
// TEXCOORD                 7     zw        2     NONE  float     zw
// TEXCOORD                 1   xyzw        3     NONE  float       
// TEXCOORD                 2   xyzw        4     NONE  float       
// TEXCOORD                 3   xyzw        5     NONE  float       
// TEXCOORD                 4   xyzw        6     NONE  float   xyzw
// TEXCOORD                 5   xyzw        7     NONE  float   xyzw
// TEXCOORD                 6   xyzw        8     NONE  float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
ps_4_0
dcl_constantbuffer cb0[6], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_sampler s2, mode_default
dcl_sampler s3, mode_default
dcl_sampler s4, mode_default
dcl_sampler s5, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_resource_texture2d (float,float,float,float) t2
dcl_resource_texture2d (float,float,float,float) t3
dcl_resource_texture2d (float,float,float,float) t4
dcl_resource_texture2d (float,float,float,float) t5
dcl_input_ps linear v1.xyzw
dcl_input_ps linear v2.xy
dcl_input_ps linear v2.zw
dcl_input_ps linear v6.xyzw
dcl_input_ps linear v7.xyzw
dcl_input_ps linear v8.xyzw
dcl_output o0.xyzw
dcl_temps 7
sample r0.xyzw, v6.zwzz, t2.xyzw, s2
mad r0.xy, r0.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mad r0.z, -r0.y, cb0[1].w, cb0[1].z
mad r0.yw, r0.xxxz, cb0[1].xxxx, v2.xxxy
sample r1.xyzw, r0.ywyy, t0.xyzw, s0
mul r1.xyzw, r1.xyzw, v1.xyzw
lt r0.y, l(0.000000), cb0[0].x
if_nz r0.y
  mad r0.yw, r0.xxxz, cb0[1].xxxx, v8.zzzw
  sample r2.xyzw, r0.ywyy, t0.xyzw, s0
  eq r0.y, cb0[0].y, l(1.000000)
  mad r2.xyzw, r2.xyzw, v1.xyzw, -r1.xyzw
  mad r2.xyzw, v2.zzzz, r2.xyzw, r1.xyzw
  movc r1.xyzw, r0.yyyy, r2.xyzw, r1.xyzw
endif 
mad r0.xy, r0.xzxx, cb0[1].xxxx, v6.xyxx
sample r0.xyzw, r0.xyxx, t1.xyzw, s1
mul r0.x, r0.w, r0.x
mul r0.y, r0.x, r1.w
max r0.z, v2.w, l(0.000000)
ge r0.z, r0.z, r0.y
discard r0.z
sample r2.xyzw, v7.zwzz, t5.xyzw, s5
mad r2.xy, r2.xyxx, l(2.000000, 2.000000, 0.000000, 0.000000), l(-1.000000, -1.000000, 0.000000, 0.000000)
mad r0.z, -r2.y, cb0[1].w, cb0[1].z
mad r2.z, cb0[1].w, r0.z, cb0[1].z
mad r0.zw, r2.xxxz, cb0[1].yyyy, v8.xxxy
sample r3.xyzw, r0.zwzz, t3.xyzw, s3
mad r0.zw, r2.xxxz, cb0[1].yyyy, v7.xxxy
sample r2.xyzw, r0.zwzz, t4.xyzw, s4
mul r0.z, r2.w, r2.x
mul r0.w, r0.z, r3.w
mul r2.xyz, r3.xyzx, r0.wwww
mad r0.z, -r3.w, r0.z, l(1.000000)
mad r4.xyz, r0.zzzz, r1.xyzx, r2.xyzx
mad r5.xyz, r0.wwww, r3.xyzx, r1.xyzx
mad r3.xyz, -r0.wwww, r3.xyzx, r1.xyzx
eq r6.xyzw, cb0[2].xxxx, l(0.000000, 1.000000, 2.000000, 3.000000)
mul r2.xyz, r1.xyzx, r2.xyzx
movc r1.xyz, r6.wwww, r2.xyzx, r1.xyzx
movc r1.xyz, r6.zzzz, r3.xyzx, r1.xyzx
movc r1.xyz, r6.yyyy, r5.xyzx, r1.xyzx
movc r1.xyz, r6.xxxx, r4.xyzx, r1.xyzx
mul r2.xyz, cb0[4].xyzx, cb0[5].yyyy
mad r0.x, r1.w, r0.x, -v2.w
add r0.x, r0.x, -cb0[5].x
round_pi r0.x, r0.x
mad r1.xyz, r1.xyzx, cb0[3].xxxx, -r2.xyzx
mad o0.xyz, r0.xxxx, r1.xyzx, r2.xyzx
mov o0.w, r0.y
ret 
// Approximately 51 instruction slots used
#endif

const BYTE g_main[] =
{
     68,  88,  66,  67, 179,  46, 
     29,  86,  36, 174,  86,  89, 
    180,  77, 123, 210, 158, 131, 
    177, 106,   1,   0,   0,   0, 
    248,  13,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     56,   4,   0,   0,  84,   5, 
      0,   0, 136,   5,   0,   0, 
    124,  13,   0,   0,  82,  68, 
     69,  70, 252,   3,   0,   0, 
      1,   0,   0,   0, 168,   2, 
      0,   0,  13,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    255, 255,  16,   1,   0,   0, 
    200,   3,   0,   0, 188,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    198,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 213,   1,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 235,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    250,   1,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  14,   2,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  41,   2, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
     51,   2,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   1,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0,  66,   2,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   2,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,  88,   2, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
    103,   2,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   4,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0, 123,   2,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   5,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0, 150,   2, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    103,  95, 115,  97, 109, 112, 
    108, 101, 114,   0, 103,  95, 
     97, 108, 112, 104,  97,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 103,  95, 117, 118,  68, 
    105, 115, 116, 111, 114, 116, 
    105, 111, 110,  83,  97, 109, 
    112, 108, 101, 114,   0, 103, 
     95,  98, 108, 101, 110, 100, 
     83,  97, 109, 112, 108, 101, 
    114,   0, 103,  95,  98, 108, 
    101, 110, 100,  65, 108, 112, 
    104,  97,  83,  97, 109, 112, 
    108, 101, 114,   0, 103,  95, 
     98, 108, 101, 110, 100,  85, 
     86,  68, 105, 115, 116, 111, 
    114, 116, 105, 111, 110,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 103,  95, 116, 101, 120, 
    116, 117, 114, 101,   0, 103, 
     95,  97, 108, 112, 104,  97, 
     84, 101, 120, 116, 117, 114, 
    101,   0, 103,  95, 117, 118, 
     68, 105, 115, 116, 111, 114, 
    116, 105, 111, 110,  84, 101, 
    120, 116, 117, 114, 101,   0, 
    103,  95,  98, 108, 101, 110, 
    100,  84, 101, 120, 116, 117, 
    114, 101,   0, 103,  95,  98, 
    108, 101, 110, 100,  65, 108, 
    112, 104,  97,  84, 101, 120, 
    116, 117, 114, 101,   0, 103, 
     95,  98, 108, 101, 110, 100, 
     85,  86,  68, 105, 115, 116, 
    111, 114, 116, 105, 111, 110, 
     84, 101, 120, 116, 117, 114, 
    101,   0,  80,  83,  95,  67, 
    111, 110, 115, 116,  97, 110, 
     66, 117, 102, 102, 101, 114, 
      0, 171, 150,   2,   0,   0, 
      6,   0,   0,   0, 192,   2, 
      0,   0,  96,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  80,   3,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    100,   3,   0,   0,   0,   0, 
      0,   0, 116,   3,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    100,   3,   0,   0,   0,   0, 
      0,   0, 138,   3,   0,   0, 
     32,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    100,   3,   0,   0,   0,   0, 
      0,   0, 160,   3,   0,   0, 
     48,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    100,   3,   0,   0,   0,   0, 
      0,   0, 176,   3,   0,   0, 
     64,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    100,   3,   0,   0,   0,   0, 
      0,   0, 186,   3,   0,   0, 
     80,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    100,   3,   0,   0,   0,   0, 
      0,   0, 102, 108, 105, 112, 
     98, 111, 111, 107,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 117, 118,  68, 105, 
    115, 116, 111, 114, 116, 105, 
    111, 110,  80,  97, 114,  97, 
    109, 101, 116, 101, 114,   0, 
     98, 108, 101, 110, 100,  84, 
    101, 120, 116, 117, 114, 101, 
     80,  97, 114,  97, 109, 101, 
    116, 101, 114,   0, 101, 109, 
    105, 115, 115, 105, 118, 101, 
     83,  99,  97, 108, 105, 110, 
    103,   0, 101, 100, 103, 101, 
     67, 111, 108, 111, 114,   0, 
    101, 100, 103, 101,  80,  97, 
    114,  97, 109, 101, 116, 101, 
    114,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  57,  46,  50,  57,  46, 
     57,  53,  50,  46,  51,  49, 
     49,  49,   0, 171, 171, 171, 
     73,  83,  71,  78,  20,   1, 
      0,   0,  10,   0,   0,   0, 
      8,   0,   0,   0, 248,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,   4,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,  15,   0,   0,  10,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   3,   0,   0,  10,   1, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
     12,  12,   0,   0,  10,   1, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
     15,   0,   0,   0,  10,   1, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
     15,   0,   0,   0,  10,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
     15,   0,   0,   0,  10,   1, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
     15,  15,   0,   0,  10,   1, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
     15,  15,   0,   0,  10,   1, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   8,   0,   0,   0, 
     15,  15,   0,   0,  83,  86, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0,  67,  79, 
     76,  79,  82,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  84,  97, 114, 
    103, 101, 116,   0, 171, 171, 
     83,  72,  68,  82, 236,   7, 
      0,   0,  64,   0,   0,   0, 
    251,   1,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   1,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   2,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   3,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   4,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   5,   0, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   1,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      2,   0,   0,   0,  85,  85, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   3,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   4,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      5,   0,   0,   0,  85,  85, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   1,   0, 
      0,   0,  98,  16,   0,   3, 
     50,  16,  16,   0,   2,   0, 
      0,   0,  98,  16,   0,   3, 
    194,  16,  16,   0,   2,   0, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   6,   0, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   7,   0, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   8,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      7,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      0,   0,   0,   0, 230,  26, 
     16,   0,   6,   0,   0,   0, 
     70, 126,  16,   0,   2,   0, 
      0,   0,   0,  96,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,  15,  50,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,  64,   0,   0,   0,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128, 191,   0,   0, 
    128, 191,   0,   0,   0,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  12,  66,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,  58, 128, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10, 162,   0,  16,   0, 
      0,   0,   0,   0,   6,   8, 
     16,   0,   0,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      6,  20,  16,   0,   2,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   1,   0, 
      0,   0, 214,   5,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70,  30, 
     16,   0,   1,   0,   0,   0, 
     49,   0,   0,   8,  34,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  31,   0,   4,   3, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  10, 
    162,   0,  16,   0,   0,   0, 
      0,   0,   6,   8,  16,   0, 
      0,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 166,  30, 
     16,   0,   8,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   2,   0,   0,   0, 
    214,   5,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     24,   0,   0,   8,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  50,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70,  30, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     50,   0,   0,   9, 242,   0, 
     16,   0,   2,   0,   0,   0, 
    166,  26,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     86,   5,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     21,   0,   0,   1,  50,   0, 
      0,  10,  50,   0,  16,   0, 
      0,   0,   0,   0, 134,   0, 
     16,   0,   0,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     70,  16,  16,   0,   6,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   1,   0,   0,   0, 
      0,  96,  16,   0,   1,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  52,   0, 
      0,   7,  66,   0,  16,   0, 
      0,   0,   0,   0,  58,  16, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  29,   0,   0,   7, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     13,   0,   4,   3,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   2,   0,   0,   0, 
    230,  26,  16,   0,   7,   0, 
      0,   0,  70, 126,  16,   0, 
      5,   0,   0,   0,   0,  96, 
     16,   0,   5,   0,   0,   0, 
     50,   0,   0,  15,  50,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   0,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  12,  66,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     50,   0,   0,  11,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   6,   8,  16,   0, 
      2,   0,   0,   0,  86, 133, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   6,  20, 
     16,   0,   8,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   3,   0,   0,   0, 
    230,  10,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      3,   0,   0,   0,   0,  96, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  10, 194,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   8,  16,   0,   2,   0, 
      0,   0,  86, 133,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   6,  20,  16,   0, 
      7,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0, 230,  10, 
     16,   0,   0,   0,   0,   0, 
     70, 126,  16,   0,   4,   0, 
      0,   0,   0,  96,  16,   0, 
      4,   0,   0,   0,  56,   0, 
      0,   7,  66,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   3,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  10,  66,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      3,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  50,   0,   0,   9, 
    114,   0,  16,   0,   4,   0, 
      0,   0, 166,  10,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,   9, 
    114,   0,  16,   0,   5,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    114,   0,  16,   0,   3,   0, 
      0,   0, 246,  15,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     24,   0,   0,  11, 242,   0, 
     16,   0,   6,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,  64,   0,   0, 
     64,  64,  56,   0,   0,   7, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   6,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   1,   0,   0,   0, 
    166,  10,  16,   0,   6,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     86,   5,  16,   0,   6,   0, 
      0,   0,  70,   2,  16,   0, 
      5,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   0,  16,   0,   6,   0, 
      0,   0,  70,   2,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   9, 114,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     86, 133,  32,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     50,   0,   0,  10,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  58,  16, 
     16, 128,  65,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,  66,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  11, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  70,   2,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  50,   0,   0,   9, 
    114,  32,  16,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  54,   0,   0,   5, 
    130,  32,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    116,   0,   0,   0,  51,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  15,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      5,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};
