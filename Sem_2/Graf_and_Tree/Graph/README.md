# Вариант задания
Реализовать алгоритмы для собственного, придуманного самим автором, варианта двунаправленного графа, имеющего не менее 6 вершин.
 
Алгоритмы:
1. Обход в ширину.
2. Обход в глубину.
3. Алгоритм Дейкстры.

Требования:

1. Пользовательский интерфейс на усмотрение разработчика с условием кроссплатформенности (поощряется использование Qt или иных фреймворков)

2. Визуализация графа с использованием любой доступной графической библиотеки (SFML, SDL, OpenGL и подобных)
# Код программы
## freeglut_std.h
```cpp
#ifndef  __FREEGLUT_STD_H__
#define  __FREEGLUT_STD_H__

/*
 * freeglut_std.h
 *
 * The GLUT-compatible part of the freeglut library include file
 *
 * Copyright (c) 1999-2000 Pawel W. Olszta. All Rights Reserved.
 * Written by Pawel W. Olszta, <olszta@sourceforge.net>
 * Creation date: Thu Dec 2 1999
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * PAWEL W. OLSZTA BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifdef __cplusplus
extern "C" {
#endif

    /*
     * Under windows, we have to differentiate between static and dynamic libraries
     */
#ifdef _WIN32
     /* #pragma may not be supported by some compilers.
      * Discussion by FreeGLUT developers suggests that
      * Visual C++ specific code involving pragmas may
      * need to move to a separate header.  24th Dec 2003
      */

      /* Define FREEGLUT_LIB_PRAGMAS to 1 to include library
       * pragmas or to 0 to exclude library pragmas.
       * The default behavior depends on the compiler/platform.
       */
#   ifndef FREEGLUT_LIB_PRAGMAS
#       if ( defined(_MSC_VER) || defined(__WATCOMC__) ) && !defined(_WIN32_WCE)
#           define FREEGLUT_LIB_PRAGMAS 1
#       else
#           define FREEGLUT_LIB_PRAGMAS 0
#       endif
#   endif

#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN 1
#  endif
#  ifndef NOMINMAX
#    define NOMINMAX
#  endif
#   include <windows.h>

       /* Windows static library */
#   ifdef FREEGLUT_STATIC

#error Static linking is not supported with this build. Please remove the FREEGLUT_STATIC preprocessor directive, or download the source code from http://freeglut.sf.net/ and build against that.

/* Windows shared library (DLL) */
#   else

#       define FGAPIENTRY __stdcall
#       if defined(FREEGLUT_EXPORTS)
#           define FGAPI __declspec(dllexport)
#       else
#           define FGAPI __declspec(dllimport)

            /* Link with Win32 shared freeglut lib */
#           if FREEGLUT_LIB_PRAGMAS
#             pragma comment (lib, "freeglut.lib")
#           endif

#       endif

#   endif

/* Drag in other Windows libraries as required by FreeGLUT */
#   if FREEGLUT_LIB_PRAGMAS
#       pragma comment (lib, "glu32.lib")    /* link OpenGL Utility lib     */
#       pragma comment (lib, "opengl32.lib") /* link Microsoft OpenGL lib   */
#       pragma comment (lib, "gdi32.lib")    /* link Windows GDI lib        */
#       pragma comment (lib, "winmm.lib")    /* link Windows MultiMedia lib */
#       pragma comment (lib, "user32.lib")   /* link Windows user lib       */
#   endif

#else

     /* Non-Windows definition of FGAPI and FGAPIENTRY  */
#        define FGAPI
#        define FGAPIENTRY

#endif

/*
 * The freeglut and GLUT API versions
 */
#define  FREEGLUT             1
#define  GLUT_API_VERSION     4
#define  GLUT_XLIB_IMPLEMENTATION 13
 /* Deprecated:
    cf. http://sourceforge.net/mailarchive/forum.php?thread_name=CABcAi1hw7cr4xtigckaGXB5X8wddLfMcbA_rZ3NAuwMrX_zmsw%40mail.gmail.com&forum_name=freeglut-developer */
#define  FREEGLUT_VERSION_2_0 1

    /*
     * Always include OpenGL and GLU headers
     */
     /* Note: FREEGLUT_GLES is only used to cleanly bootstrap headers
        inclusion here; use GLES constants directly
        (e.g. GL_ES_VERSION_2_0) for all other needs */
#ifdef FREEGLUT_GLES
#   include <EGL/egl.h>
#   include <GLES/gl.h>
#   include <GLES2/gl2.h>
#elif __APPLE__
#   include <OpenGL/gl.h>
#   include <OpenGL/glu.h>
#else
#   include <GL/gl.h>
#   include <GL/glu.h>
#endif

        /*
         * GLUT API macro definitions -- the special key codes:
         */
#define  GLUT_KEY_F1                        0x0001
#define  GLUT_KEY_F2                        0x0002
#define  GLUT_KEY_F3                        0x0003
#define  GLUT_KEY_F4                        0x0004
#define  GLUT_KEY_F5                        0x0005
#define  GLUT_KEY_F6                        0x0006
#define  GLUT_KEY_F7                        0x0007
#define  GLUT_KEY_F8                        0x0008
#define  GLUT_KEY_F9                        0x0009
#define  GLUT_KEY_F10                       0x000A
#define  GLUT_KEY_F11                       0x000B
#define  GLUT_KEY_F12                       0x000C
#define  GLUT_KEY_LEFT                      0x0064
#define  GLUT_KEY_UP                        0x0065
#define  GLUT_KEY_RIGHT                     0x0066
#define  GLUT_KEY_DOWN                      0x0067
#define  GLUT_KEY_PAGE_UP                   0x0068
#define  GLUT_KEY_PAGE_DOWN                 0x0069
#define  GLUT_KEY_HOME                      0x006A
#define  GLUT_KEY_END                       0x006B
#define  GLUT_KEY_INSERT                    0x006C

         /*
          * GLUT API macro definitions -- mouse state definitions
          */
#define  GLUT_LEFT_BUTTON                   0x0000
#define  GLUT_MIDDLE_BUTTON                 0x0001
#define  GLUT_RIGHT_BUTTON                  0x0002
#define  GLUT_DOWN                          0x0000
#define  GLUT_UP                            0x0001
#define  GLUT_LEFT                          0x0000
#define  GLUT_ENTERED                       0x0001

          /*
           * GLUT API macro definitions -- the display mode definitions
           */
#define  GLUT_RGB                           0x0000
#define  GLUT_RGBA                          0x0000
#define  GLUT_INDEX                         0x0001
#define  GLUT_SINGLE                        0x0000
#define  GLUT_DOUBLE                        0x0002
#define  GLUT_ACCUM                         0x0004
#define  GLUT_ALPHA                         0x0008
#define  GLUT_DEPTH                         0x0010
#define  GLUT_STENCIL                       0x0020
#define  GLUT_MULTISAMPLE                   0x0080
#define  GLUT_STEREO                        0x0100
#define  GLUT_LUMINANCE                     0x0200

           /*
            * GLUT API macro definitions -- windows and menu related definitions
            */
#define  GLUT_MENU_NOT_IN_USE               0x0000
#define  GLUT_MENU_IN_USE                   0x0001
#define  GLUT_NOT_VISIBLE                   0x0000
#define  GLUT_VISIBLE                       0x0001
#define  GLUT_HIDDEN                        0x0000
#define  GLUT_FULLY_RETAINED                0x0001
#define  GLUT_PARTIALLY_RETAINED            0x0002
#define  GLUT_FULLY_COVERED                 0x0003

            /*
             * GLUT API macro definitions -- fonts definitions
             *
             * Steve Baker suggested to make it binary compatible with GLUT:
             */
#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__WATCOMC__)
#   define  GLUT_STROKE_ROMAN               ((void *)0x0000)
#   define  GLUT_STROKE_MONO_ROMAN          ((void *)0x0001)
#   define  GLUT_BITMAP_9_BY_15             ((void *)0x0002)
#   define  GLUT_BITMAP_8_BY_13             ((void *)0x0003)
#   define  GLUT_BITMAP_TIMES_ROMAN_10      ((void *)0x0004)
#   define  GLUT_BITMAP_TIMES_ROMAN_24      ((void *)0x0005)
#   define  GLUT_BITMAP_HELVETICA_10        ((void *)0x0006)
#   define  GLUT_BITMAP_HELVETICA_12        ((void *)0x0007)
#   define  GLUT_BITMAP_HELVETICA_18        ((void *)0x0008)
#else
             /*
              * I don't really know if it's a good idea... But here it goes:
              */
    extern void* glutStrokeRoman;
    extern void* glutStrokeMonoRoman;
    extern void* glutBitmap9By15;
    extern void* glutBitmap8By13;
    extern void* glutBitmapTimesRoman10;
    extern void* glutBitmapTimesRoman24;
    extern void* glutBitmapHelvetica10;
    extern void* glutBitmapHelvetica12;
    extern void* glutBitmapHelvetica18;

    /*
     * Those pointers will be used by following definitions:
     */
#   define  GLUT_STROKE_ROMAN               ((void *) &glutStrokeRoman)
#   define  GLUT_STROKE_MONO_ROMAN          ((void *) &glutStrokeMonoRoman)
#   define  GLUT_BITMAP_9_BY_15             ((void *) &glutBitmap9By15)
#   define  GLUT_BITMAP_8_BY_13             ((void *) &glutBitmap8By13)
#   define  GLUT_BITMAP_TIMES_ROMAN_10      ((void *) &glutBitmapTimesRoman10)
#   define  GLUT_BITMAP_TIMES_ROMAN_24      ((void *) &glutBitmapTimesRoman24)
#   define  GLUT_BITMAP_HELVETICA_10        ((void *) &glutBitmapHelvetica10)
#   define  GLUT_BITMAP_HELVETICA_12        ((void *) &glutBitmapHelvetica12)
#   define  GLUT_BITMAP_HELVETICA_18        ((void *) &glutBitmapHelvetica18)
#endif

     /*
      * GLUT API macro definitions -- the glutGet parameters
      */
#define  GLUT_WINDOW_X                      0x0064
#define  GLUT_WINDOW_Y                      0x0065
#define  GLUT_WINDOW_WIDTH                  0x0066
#define  GLUT_WINDOW_HEIGHT                 0x0067
#define  GLUT_WINDOW_BUFFER_SIZE            0x0068
#define  GLUT_WINDOW_STENCIL_SIZE           0x0069
#define  GLUT_WINDOW_DEPTH_SIZE             0x006A
#define  GLUT_WINDOW_RED_SIZE               0x006B
#define  GLUT_WINDOW_GREEN_SIZE             0x006C
#define  GLUT_WINDOW_BLUE_SIZE              0x006D
#define  GLUT_WINDOW_ALPHA_SIZE             0x006E
#define  GLUT_WINDOW_ACCUM_RED_SIZE         0x006F
#define  GLUT_WINDOW_ACCUM_GREEN_SIZE       0x0070
#define  GLUT_WINDOW_ACCUM_BLUE_SIZE        0x0071
#define  GLUT_WINDOW_ACCUM_ALPHA_SIZE       0x0072
#define  GLUT_WINDOW_DOUBLEBUFFER           0x0073
#define  GLUT_WINDOW_RGBA                   0x0074
#define  GLUT_WINDOW_PARENT                 0x0075
#define  GLUT_WINDOW_NUM_CHILDREN           0x0076
#define  GLUT_WINDOW_COLORMAP_SIZE          0x0077
#define  GLUT_WINDOW_NUM_SAMPLES            0x0078
#define  GLUT_WINDOW_STEREO                 0x0079
#define  GLUT_WINDOW_CURSOR                 0x007A

#define  GLUT_SCREEN_WIDTH                  0x00C8
#define  GLUT_SCREEN_HEIGHT                 0x00C9
#define  GLUT_SCREEN_WIDTH_MM               0x00CA
#define  GLUT_SCREEN_HEIGHT_MM              0x00CB
#define  GLUT_MENU_NUM_ITEMS                0x012C
#define  GLUT_DISPLAY_MODE_POSSIBLE         0x0190
#define  GLUT_INIT_WINDOW_X                 0x01F4
#define  GLUT_INIT_WINDOW_Y                 0x01F5
#define  GLUT_INIT_WINDOW_WIDTH             0x01F6
#define  GLUT_INIT_WINDOW_HEIGHT            0x01F7
#define  GLUT_INIT_DISPLAY_MODE             0x01F8
#define  GLUT_ELAPSED_TIME                  0x02BC
#define  GLUT_WINDOW_FORMAT_ID              0x007B

      /*
       * GLUT API macro definitions -- the glutDeviceGet parameters
       */
#define  GLUT_HAS_KEYBOARD                  0x0258
#define  GLUT_HAS_MOUSE                     0x0259
#define  GLUT_HAS_SPACEBALL                 0x025A
#define  GLUT_HAS_DIAL_AND_BUTTON_BOX       0x025B
#define  GLUT_HAS_TABLET                    0x025C
#define  GLUT_NUM_MOUSE_BUTTONS             0x025D
#define  GLUT_NUM_SPACEBALL_BUTTONS         0x025E
#define  GLUT_NUM_BUTTON_BOX_BUTTONS        0x025F
#define  GLUT_NUM_DIALS                     0x0260
#define  GLUT_NUM_TABLET_BUTTONS            0x0261
#define  GLUT_DEVICE_IGNORE_KEY_REPEAT      0x0262
#define  GLUT_DEVICE_KEY_REPEAT             0x0263
#define  GLUT_HAS_JOYSTICK                  0x0264
#define  GLUT_OWNS_JOYSTICK                 0x0265
#define  GLUT_JOYSTICK_BUTTONS              0x0266
#define  GLUT_JOYSTICK_AXES                 0x0267
#define  GLUT_JOYSTICK_POLL_RATE            0x0268

       /*
        * GLUT API macro definitions -- the glutLayerGet parameters
        */
#define  GLUT_OVERLAY_POSSIBLE              0x0320
#define  GLUT_LAYER_IN_USE                  0x0321
#define  GLUT_HAS_OVERLAY                   0x0322
#define  GLUT_TRANSPARENT_INDEX             0x0323
#define  GLUT_NORMAL_DAMAGED                0x0324
#define  GLUT_OVERLAY_DAMAGED               0x0325

        /*
         * GLUT API macro definitions -- the glutVideoResizeGet parameters
         */
#define  GLUT_VIDEO_RESIZE_POSSIBLE         0x0384
#define  GLUT_VIDEO_RESIZE_IN_USE           0x0385
#define  GLUT_VIDEO_RESIZE_X_DELTA          0x0386
#define  GLUT_VIDEO_RESIZE_Y_DELTA          0x0387
#define  GLUT_VIDEO_RESIZE_WIDTH_DELTA      0x0388
#define  GLUT_VIDEO_RESIZE_HEIGHT_DELTA     0x0389
#define  GLUT_VIDEO_RESIZE_X                0x038A
#define  GLUT_VIDEO_RESIZE_Y                0x038B
#define  GLUT_VIDEO_RESIZE_WIDTH            0x038C
#define  GLUT_VIDEO_RESIZE_HEIGHT           0x038D

         /*
          * GLUT API macro definitions -- the glutUseLayer parameters
          */
#define  GLUT_NORMAL                        0x0000
#define  GLUT_OVERLAY                       0x0001

          /*
           * GLUT API macro definitions -- the glutGetModifiers parameters
           */
#define  GLUT_ACTIVE_SHIFT                  0x0001
#define  GLUT_ACTIVE_CTRL                   0x0002
#define  GLUT_ACTIVE_ALT                    0x0004

           /*
            * GLUT API macro definitions -- the glutSetCursor parameters
            */
#define  GLUT_CURSOR_RIGHT_ARROW            0x0000
#define  GLUT_CURSOR_LEFT_ARROW             0x0001
#define  GLUT_CURSOR_INFO                   0x0002
#define  GLUT_CURSOR_DESTROY                0x0003
#define  GLUT_CURSOR_HELP                   0x0004
#define  GLUT_CURSOR_CYCLE                  0x0005
#define  GLUT_CURSOR_SPRAY                  0x0006
#define  GLUT_CURSOR_WAIT                   0x0007
#define  GLUT_CURSOR_TEXT                   0x0008
#define  GLUT_CURSOR_CROSSHAIR              0x0009
#define  GLUT_CURSOR_UP_DOWN                0x000A
#define  GLUT_CURSOR_LEFT_RIGHT             0x000B
#define  GLUT_CURSOR_TOP_SIDE               0x000C
#define  GLUT_CURSOR_BOTTOM_SIDE            0x000D
#define  GLUT_CURSOR_LEFT_SIDE              0x000E
#define  GLUT_CURSOR_RIGHT_SIDE             0x000F
#define  GLUT_CURSOR_TOP_LEFT_CORNER        0x0010
#define  GLUT_CURSOR_TOP_RIGHT_CORNER       0x0011
#define  GLUT_CURSOR_BOTTOM_RIGHT_CORNER    0x0012
#define  GLUT_CURSOR_BOTTOM_LEFT_CORNER     0x0013
#define  GLUT_CURSOR_INHERIT                0x0064
#define  GLUT_CURSOR_NONE                   0x0065
#define  GLUT_CURSOR_FULL_CROSSHAIR         0x0066

            /*
             * GLUT API macro definitions -- RGB color component specification definitions
             */
#define  GLUT_RED                           0x0000
#define  GLUT_GREEN                         0x0001
#define  GLUT_BLUE                          0x0002

             /*
              * GLUT API macro definitions -- additional keyboard and joystick definitions
              */
#define  GLUT_KEY_REPEAT_OFF                0x0000
#define  GLUT_KEY_REPEAT_ON                 0x0001
#define  GLUT_KEY_REPEAT_DEFAULT            0x0002

#define  GLUT_JOYSTICK_BUTTON_A             0x0001
#define  GLUT_JOYSTICK_BUTTON_B             0x0002
#define  GLUT_JOYSTICK_BUTTON_C             0x0004
#define  GLUT_JOYSTICK_BUTTON_D             0x0008

              /*
               * GLUT API macro definitions -- game mode definitions
               */
#define  GLUT_GAME_MODE_ACTIVE              0x0000
#define  GLUT_GAME_MODE_POSSIBLE            0x0001
#define  GLUT_GAME_MODE_WIDTH               0x0002
#define  GLUT_GAME_MODE_HEIGHT              0x0003
#define  GLUT_GAME_MODE_PIXEL_DEPTH         0x0004
#define  GLUT_GAME_MODE_REFRESH_RATE        0x0005
#define  GLUT_GAME_MODE_DISPLAY_CHANGED     0x0006

               /*
                * Initialization functions, see fglut_init.c
                */
    FGAPI void    FGAPIENTRY glutInit(int* pargc, char** argv);
    FGAPI void    FGAPIENTRY glutInitWindowPosition(int x, int y);
    FGAPI void    FGAPIENTRY glutInitWindowSize(int width, int height);
    FGAPI void    FGAPIENTRY glutInitDisplayMode(unsigned int displayMode);
    FGAPI void    FGAPIENTRY glutInitDisplayString(const char* displayMode);

    /*
     * Process loop function, see fg_main.c
     */
    FGAPI void    FGAPIENTRY glutMainLoop(void);

    /*
     * Window management functions, see fg_window.c
     */
    FGAPI int     FGAPIENTRY glutCreateWindow(const char* title);
    FGAPI int     FGAPIENTRY glutCreateSubWindow(int window, int x, int y, int width, int height);
    FGAPI void    FGAPIENTRY glutDestroyWindow(int window);
    FGAPI void    FGAPIENTRY glutSetWindow(int window);
    FGAPI int     FGAPIENTRY glutGetWindow(void);
    FGAPI void    FGAPIENTRY glutSetWindowTitle(const char* title);
    FGAPI void    FGAPIENTRY glutSetIconTitle(const char* title);
    FGAPI void    FGAPIENTRY glutReshapeWindow(int width, int height);
    FGAPI void    FGAPIENTRY glutPositionWindow(int x, int y);
    FGAPI void    FGAPIENTRY glutShowWindow(void);
    FGAPI void    FGAPIENTRY glutHideWindow(void);
    FGAPI void    FGAPIENTRY glutIconifyWindow(void);
    FGAPI void    FGAPIENTRY glutPushWindow(void);
    FGAPI void    FGAPIENTRY glutPopWindow(void);
    FGAPI void    FGAPIENTRY glutFullScreen(void);

    /*
     * Display-related functions, see fg_display.c
     */
    FGAPI void    FGAPIENTRY glutPostWindowRedisplay(int window);
    FGAPI void    FGAPIENTRY glutPostRedisplay(void);
    FGAPI void    FGAPIENTRY glutSwapBuffers(void);

    /*
     * Mouse cursor functions, see fg_cursor.c
     */
    FGAPI void    FGAPIENTRY glutWarpPointer(int x, int y);
    FGAPI void    FGAPIENTRY glutSetCursor(int cursor);

    /*
     * Overlay stuff, see fg_overlay.c
     */
    FGAPI void    FGAPIENTRY glutEstablishOverlay(void);
    FGAPI void    FGAPIENTRY glutRemoveOverlay(void);
    FGAPI void    FGAPIENTRY glutUseLayer(GLenum layer);
    FGAPI void    FGAPIENTRY glutPostOverlayRedisplay(void);
    FGAPI void    FGAPIENTRY glutPostWindowOverlayRedisplay(int window);
    FGAPI void    FGAPIENTRY glutShowOverlay(void);
    FGAPI void    FGAPIENTRY glutHideOverlay(void);

    /*
     * Menu stuff, see fg_menu.c
     */
    FGAPI int     FGAPIENTRY glutCreateMenu(void (*callback)(int menu));
    FGAPI void    FGAPIENTRY glutDestroyMenu(int menu);
    FGAPI int     FGAPIENTRY glutGetMenu(void);
    FGAPI void    FGAPIENTRY glutSetMenu(int menu);
    FGAPI void    FGAPIENTRY glutAddMenuEntry(const char* label, int value);
    FGAPI void    FGAPIENTRY glutAddSubMenu(const char* label, int subMenu);
    FGAPI void    FGAPIENTRY glutChangeToMenuEntry(int item, const char* label, int value);
    FGAPI void    FGAPIENTRY glutChangeToSubMenu(int item, const char* label, int value);
    FGAPI void    FGAPIENTRY glutRemoveMenuItem(int item);
    FGAPI void    FGAPIENTRY glutAttachMenu(int button);
    FGAPI void    FGAPIENTRY glutDetachMenu(int button);

    /*
     * Global callback functions, see fg_callbacks.c
     */
    FGAPI void    FGAPIENTRY glutTimerFunc(unsigned int time, void (*callback)(int), int value);
    FGAPI void    FGAPIENTRY glutIdleFunc(void (*callback)(void));

    /*
     * Window-specific callback functions, see fg_callbacks.c
     */
    FGAPI void    FGAPIENTRY glutKeyboardFunc(void (*callback)(unsigned char, int, int));
    FGAPI void    FGAPIENTRY glutSpecialFunc(void (*callback)(int, int, int));
    FGAPI void    FGAPIENTRY glutReshapeFunc(void (*callback)(int, int));
    FGAPI void    FGAPIENTRY glutVisibilityFunc(void (*callback)(int));
    FGAPI void    FGAPIENTRY glutDisplayFunc(void (*callback)(void));
    FGAPI void    FGAPIENTRY glutMouseFunc(void (*callback)(int, int, int, int));
    FGAPI void    FGAPIENTRY glutMotionFunc(void (*callback)(int, int));
    FGAPI void    FGAPIENTRY glutPassiveMotionFunc(void (*callback)(int, int));
    FGAPI void    FGAPIENTRY glutEntryFunc(void (*callback)(int));

    FGAPI void    FGAPIENTRY glutKeyboardUpFunc(void (*callback)(unsigned char, int, int));
    FGAPI void    FGAPIENTRY glutSpecialUpFunc(void (*callback)(int, int, int));
    FGAPI void    FGAPIENTRY glutJoystickFunc(void (*callback)(unsigned int, int, int, int), int pollInterval);
    FGAPI void    FGAPIENTRY glutMenuStateFunc(void (*callback)(int));
    FGAPI void    FGAPIENTRY glutMenuStatusFunc(void (*callback)(int, int, int));
    FGAPI void    FGAPIENTRY glutOverlayDisplayFunc(void (*callback)(void));
    FGAPI void    FGAPIENTRY glutWindowStatusFunc(void (*callback)(int));

    FGAPI void    FGAPIENTRY glutSpaceballMotionFunc(void (*callback)(int, int, int));
    FGAPI void    FGAPIENTRY glutSpaceballRotateFunc(void (*callback)(int, int, int));
    FGAPI void    FGAPIENTRY glutSpaceballButtonFunc(void (*callback)(int, int));
    FGAPI void    FGAPIENTRY glutButtonBoxFunc(void (*callback)(int, int));
    FGAPI void    FGAPIENTRY glutDialsFunc(void (*callback)(int, int));
    FGAPI void    FGAPIENTRY glutTabletMotionFunc(void (*callback)(int, int));
    FGAPI void    FGAPIENTRY glutTabletButtonFunc(void (*callback)(int, int, int, int));

    /*
     * State setting and retrieval functions, see fg_state.c
     */
    FGAPI int     FGAPIENTRY glutGet(GLenum query);
    FGAPI int     FGAPIENTRY glutDeviceGet(GLenum query);
    FGAPI int     FGAPIENTRY glutGetModifiers(void);
    FGAPI int     FGAPIENTRY glutLayerGet(GLenum query);

    /*
     * Font stuff, see fg_font.c
     */
    FGAPI void    FGAPIENTRY glutBitmapCharacter(void* font, int character);
    FGAPI int     FGAPIENTRY glutBitmapWidth(void* font, int character);
    FGAPI void    FGAPIENTRY glutStrokeCharacter(void* font, int character);
    FGAPI int     FGAPIENTRY glutStrokeWidth(void* font, int character);
    FGAPI GLfloat FGAPIENTRY glutStrokeWidthf(void* font, int character); /* GLUT 3.8 */
    FGAPI int     FGAPIENTRY glutBitmapLength(void* font, const unsigned char* string);
    FGAPI int     FGAPIENTRY glutStrokeLength(void* font, const unsigned char* string);
    FGAPI GLfloat FGAPIENTRY glutStrokeLengthf(void* font, const unsigned char* string); /* GLUT 3.8 */

    /*
     * Geometry functions, see fg_geometry.c
     */

    FGAPI void    FGAPIENTRY glutWireCube(double size);
    FGAPI void    FGAPIENTRY glutSolidCube(double size);
    FGAPI void    FGAPIENTRY glutWireSphere(double radius, GLint slices, GLint stacks);
    FGAPI void    FGAPIENTRY glutSolidSphere(double radius, GLint slices, GLint stacks);
    FGAPI void    FGAPIENTRY glutWireCone(double base, double height, GLint slices, GLint stacks);
    FGAPI void    FGAPIENTRY glutSolidCone(double base, double height, GLint slices, GLint stacks);
    FGAPI void    FGAPIENTRY glutWireTorus(double innerRadius, double outerRadius, GLint sides, GLint rings);
    FGAPI void    FGAPIENTRY glutSolidTorus(double innerRadius, double outerRadius, GLint sides, GLint rings);
    FGAPI void    FGAPIENTRY glutWireDodecahedron(void);
    FGAPI void    FGAPIENTRY glutSolidDodecahedron(void);
    FGAPI void    FGAPIENTRY glutWireOctahedron(void);
    FGAPI void    FGAPIENTRY glutSolidOctahedron(void);
    FGAPI void    FGAPIENTRY glutWireTetrahedron(void);
    FGAPI void    FGAPIENTRY glutSolidTetrahedron(void);
    FGAPI void    FGAPIENTRY glutWireIcosahedron(void);
    FGAPI void    FGAPIENTRY glutSolidIcosahedron(void);

    /*
     * Teapot rendering functions, found in fg_teapot.c
     * NB: front facing polygons have clockwise winding, not counter clockwise
     */
    FGAPI void    FGAPIENTRY glutWireTeapot(double size);
    FGAPI void    FGAPIENTRY glutSolidTeapot(double size);

    /*
     * Game mode functions, see fg_gamemode.c
     */
    FGAPI void    FGAPIENTRY glutGameModeString(const char* string);
    FGAPI int     FGAPIENTRY glutEnterGameMode(void);
    FGAPI void    FGAPIENTRY glutLeaveGameMode(void);
    FGAPI int     FGAPIENTRY glutGameModeGet(GLenum query);

    /*
     * Video resize functions, see fg_videoresize.c
     */
    FGAPI int     FGAPIENTRY glutVideoResizeGet(GLenum query);
    FGAPI void    FGAPIENTRY glutSetupVideoResizing(void);
    FGAPI void    FGAPIENTRY glutStopVideoResizing(void);
    FGAPI void    FGAPIENTRY glutVideoResize(int x, int y, int width, int height);
    FGAPI void    FGAPIENTRY glutVideoPan(int x, int y, int width, int height);

    /*
     * Colormap functions, see fg_misc.c
     */
    FGAPI void    FGAPIENTRY glutSetColor(int color, GLfloat red, GLfloat green, GLfloat blue);
    FGAPI GLfloat FGAPIENTRY glutGetColor(int color, int component);
    FGAPI void    FGAPIENTRY glutCopyColormap(int window);

    /*
     * Misc keyboard and joystick functions, see fg_misc.c
     */
    FGAPI void    FGAPIENTRY glutIgnoreKeyRepeat(int ignore);
    FGAPI void    FGAPIENTRY glutSetKeyRepeat(int repeatMode);
    FGAPI void    FGAPIENTRY glutForceJoystickFunc(void);

    /*
     * Misc functions, see fg_misc.c
     */
    FGAPI int     FGAPIENTRY glutExtensionSupported(const char* extension);
    FGAPI void    FGAPIENTRY glutReportErrors(void);

    /* Comment from glut.h of classic GLUT:

       Win32 has an annoying issue where there are multiple C run-time
       libraries (CRTs).  If the executable is linked with a different CRT
       from the GLUT DLL, the GLUT DLL will not share the same CRT static
       data seen by the executable.  In particular, atexit callbacks registered
       in the executable will not be called if GLUT calls its (different)
       exit routine).  GLUT is typically built with the
       "/MD" option (the CRT with multithreading DLL support), but the Visual
       C++ linker default is "/ML" (the single threaded CRT).

       One workaround to this issue is requiring users to always link with
       the same CRT as GLUT is compiled with.  That requires users supply a
       non-standard option.  GLUT 3.7 has its own built-in workaround where
       the executable's "exit" function pointer is covertly passed to GLUT.
       GLUT then calls the executable's exit function pointer to ensure that
       any "atexit" calls registered by the application are called if GLUT
       needs to exit.

       Note that the __glut*WithExit routines should NEVER be called directly.
       To avoid the atexit workaround, #define GLUT_DISABLE_ATEXIT_HACK. */

       /* to get the prototype for exit() */
#include <stdlib.h>

#if defined(_WIN32) && !defined(GLUT_DISABLE_ATEXIT_HACK) && !defined(__WATCOMC__)
    FGAPI void FGAPIENTRY __glutInitWithExit(int* argcp, char** argv, void(__cdecl* exitfunc)(int));
    FGAPI int FGAPIENTRY __glutCreateWindowWithExit(const char* title, void(__cdecl* exitfunc)(int));
    FGAPI int FGAPIENTRY __glutCreateMenuWithExit(void (*func)(int), void(__cdecl* exitfunc)(int));
#ifndef FREEGLUT_BUILDING_LIB
#if defined(__GNUC__)
#define FGUNUSED __attribute__((unused))
#else
#define FGUNUSED
#endif
    static void FGAPIENTRY FGUNUSED glutInit_ATEXIT_HACK(int* argcp, char** argv) { __glutInitWithExit(argcp, argv, exit); }
#define glutInit glutInit_ATEXIT_HACK
    static int FGAPIENTRY FGUNUSED glutCreateWindow_ATEXIT_HACK(const char* title) { return __glutCreateWindowWithExit(title, exit); }
#define glutCreateWindow glutCreateWindow_ATEXIT_HACK
    static int FGAPIENTRY FGUNUSED glutCreateMenu_ATEXIT_HACK(void (*func)(int)) { return __glutCreateMenuWithExit(func, exit); }
#define glutCreateMenu glutCreateMenu_ATEXIT_HACK
#endif
#endif

#ifdef __cplusplus
}
#endif

/*** END OF FILE ***/

#endif /* __FREEGLUT_STD_H__ */
```
## freeglut_ext.h
```cpp
#ifndef  __FREEGLUT_EXT_H__
#define  __FREEGLUT_EXT_H__

/*
 * freeglut_ext.h
 *
 * The non-GLUT-compatible extensions to the freeglut library include file
 *
 * Copyright (c) 1999-2000 Pawel W. Olszta. All Rights Reserved.
 * Written by Pawel W. Olszta, <olszta@sourceforge.net>
 * Creation date: Thu Dec 2 1999
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * PAWEL W. OLSZTA BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifdef __cplusplus
    extern "C" {
#endif

/*
 * Additional GLUT Key definitions for the Special key function
 */
#define GLUT_KEY_NUM_LOCK           0x006D
#define GLUT_KEY_BEGIN              0x006E
#define GLUT_KEY_DELETE             0x006F
#define GLUT_KEY_SHIFT_L            0x0070
#define GLUT_KEY_SHIFT_R            0x0071
#define GLUT_KEY_CTRL_L             0x0072
#define GLUT_KEY_CTRL_R             0x0073
#define GLUT_KEY_ALT_L              0x0074
#define GLUT_KEY_ALT_R              0x0075

/*
 * GLUT API Extension macro definitions -- behaviour when the user clicks on an "x" to close a window
 */
#define GLUT_ACTION_EXIT                         0
#define GLUT_ACTION_GLUTMAINLOOP_RETURNS         1
#define GLUT_ACTION_CONTINUE_EXECUTION           2

/*
 * Create a new rendering context when the user opens a new window?
 */
#define GLUT_CREATE_NEW_CONTEXT                  0
#define GLUT_USE_CURRENT_CONTEXT                 1

/*
 * Direct/Indirect rendering context options (has meaning only in Unix/X11)
 */
#define GLUT_FORCE_INDIRECT_CONTEXT              0
#define GLUT_ALLOW_DIRECT_CONTEXT                1
#define GLUT_TRY_DIRECT_CONTEXT                  2
#define GLUT_FORCE_DIRECT_CONTEXT                3

/*
 * GLUT API Extension macro definitions -- the glutGet parameters
 */
#define  GLUT_INIT_STATE                    0x007C

#define  GLUT_ACTION_ON_WINDOW_CLOSE        0x01F9

#define  GLUT_WINDOW_BORDER_WIDTH           0x01FA
#define  GLUT_WINDOW_BORDER_HEIGHT          0x01FB
#define  GLUT_WINDOW_HEADER_HEIGHT          0x01FB  /* Docs say it should always have been GLUT_WINDOW_BORDER_HEIGHT, keep this for backward compatibility */

#define  GLUT_VERSION                       0x01FC

#define  GLUT_RENDERING_CONTEXT             0x01FD
#define  GLUT_DIRECT_RENDERING              0x01FE

#define  GLUT_FULL_SCREEN                   0x01FF

#define  GLUT_SKIP_STALE_MOTION_EVENTS      0x0204

#define  GLUT_GEOMETRY_VISUALIZE_NORMALS    0x0205

#define  GLUT_STROKE_FONT_DRAW_JOIN_DOTS    0x0206  /* Draw dots between line segments of stroke fonts? */

/*
 * New tokens for glutInitDisplayMode.
 * Only one GLUT_AUXn bit may be used at a time.
 * Value 0x0400 is defined in OpenGLUT.
 */
#define  GLUT_AUX                           0x1000

#define  GLUT_AUX1                          0x1000
#define  GLUT_AUX2                          0x2000
#define  GLUT_AUX3                          0x4000
#define  GLUT_AUX4                          0x8000

/*
 * Context-related flags, see fg_state.c
 * Set the requested OpenGL version
 */
#define  GLUT_INIT_MAJOR_VERSION            0x0200
#define  GLUT_INIT_MINOR_VERSION            0x0201
#define  GLUT_INIT_FLAGS                    0x0202
#define  GLUT_INIT_PROFILE                  0x0203

/*
 * Flags for glutInitContextFlags, see fg_init.c
 */
#define  GLUT_DEBUG                         0x0001
#define  GLUT_FORWARD_COMPATIBLE            0x0002


/*
 * Flags for glutInitContextProfile, see fg_init.c
 */
#define GLUT_CORE_PROFILE                   0x0001
#define	GLUT_COMPATIBILITY_PROFILE          0x0002

/*
 * Process loop function, see fg_main.c
 */
FGAPI void    FGAPIENTRY glutMainLoopEvent( void );
FGAPI void    FGAPIENTRY glutLeaveMainLoop( void );
FGAPI void    FGAPIENTRY glutExit         ( void );

/*
 * Window management functions, see fg_window.c
 */
FGAPI void    FGAPIENTRY glutFullScreenToggle( void );
FGAPI void    FGAPIENTRY glutLeaveFullScreen( void );

/*
 * Menu functions
 */
FGAPI void    FGAPIENTRY glutSetMenuFont( int menuID, void* font );

/*
 * Window-specific callback functions, see fg_callbacks.c
 */
FGAPI void    FGAPIENTRY glutMouseWheelFunc( void (* callback)( int, int, int, int ) );
FGAPI void    FGAPIENTRY glutPositionFunc( void (* callback)( int, int ) );
FGAPI void    FGAPIENTRY glutCloseFunc( void (* callback)( void ) );
FGAPI void    FGAPIENTRY glutWMCloseFunc( void (* callback)( void ) );
/* And also a destruction callback for menus */
FGAPI void    FGAPIENTRY glutMenuDestroyFunc( void (* callback)( void ) );

/*
 * State setting and retrieval functions, see fg_state.c
 */
FGAPI void    FGAPIENTRY glutSetOption ( GLenum option_flag, int value );
FGAPI int *   FGAPIENTRY glutGetModeValues(GLenum mode, int * size);
/* A.Donev: User-data manipulation */
FGAPI void*   FGAPIENTRY glutGetWindowData( void );
FGAPI void    FGAPIENTRY glutSetWindowData(void* data);
FGAPI void*   FGAPIENTRY glutGetMenuData( void );
FGAPI void    FGAPIENTRY glutSetMenuData(void* data);

/*
 * Font stuff, see fg_font.c
 */
FGAPI int     FGAPIENTRY glutBitmapHeight( void* font );
FGAPI GLfloat FGAPIENTRY glutStrokeHeight( void* font );
FGAPI void    FGAPIENTRY glutBitmapString( void* font, const unsigned char *string );
FGAPI void    FGAPIENTRY glutStrokeString( void* font, const unsigned char *string );

/*
 * Geometry functions, see fg_geometry.c
 */
FGAPI void    FGAPIENTRY glutWireRhombicDodecahedron( void );
FGAPI void    FGAPIENTRY glutSolidRhombicDodecahedron( void );
FGAPI void    FGAPIENTRY glutWireSierpinskiSponge ( int num_levels, double offset[3], double scale );
FGAPI void    FGAPIENTRY glutSolidSierpinskiSponge ( int num_levels, double offset[3], double scale );
FGAPI void    FGAPIENTRY glutWireCylinder( double radius, double height, GLint slices, GLint stacks);
FGAPI void    FGAPIENTRY glutSolidCylinder( double radius, double height, GLint slices, GLint stacks);

/*
 * Rest of functions for rendering Newell's teaset, found in fg_teapot.c
 * NB: front facing polygons have clockwise winding, not counter clockwise
 */
FGAPI void    FGAPIENTRY glutWireTeacup( double size );
FGAPI void    FGAPIENTRY glutSolidTeacup( double size );
FGAPI void    FGAPIENTRY glutWireTeaspoon( double size );
FGAPI void    FGAPIENTRY glutSolidTeaspoon( double size );

/*
 * Extension functions, see fg_ext.c
 */
typedef void (*GLUTproc)();
FGAPI GLUTproc FGAPIENTRY glutGetProcAddress( const char *procName );

/*
 * Multi-touch/multi-pointer extensions
 */

#define GLUT_HAS_MULTI 1

/* TODO: add device_id parameter,
   cf. http://sourceforge.net/mailarchive/forum.php?thread_name=20120518071314.GA28061%40perso.beuc.net&forum_name=freeglut-developer */
FGAPI void FGAPIENTRY glutMultiEntryFunc( void (* callback)( int, int ) );
FGAPI void FGAPIENTRY glutMultiButtonFunc( void (* callback)( int, int, int, int, int ) );
FGAPI void FGAPIENTRY glutMultiMotionFunc( void (* callback)( int, int, int ) );
FGAPI void FGAPIENTRY glutMultiPassiveFunc( void (* callback)( int, int, int ) );

/*
 * Joystick functions, see fg_joystick.c
 */
/* USE OF THESE FUNCTIONS IS DEPRECATED !!!!! */
/* If you have a serious need for these functions in your application, please either
 * contact the "freeglut" developer community at freeglut-developer@lists.sourceforge.net,
 * switch to the OpenGLUT library, or else port your joystick functionality over to PLIB's
 * "js" library.
 */
int     glutJoystickGetNumAxes( int ident );
int     glutJoystickGetNumButtons( int ident );
int     glutJoystickNotWorking( int ident );
float   glutJoystickGetDeadBand( int ident, int axis );
void    glutJoystickSetDeadBand( int ident, int axis, float db );
float   glutJoystickGetSaturation( int ident, int axis );
void    glutJoystickSetSaturation( int ident, int axis, float st );
void    glutJoystickSetMinRange( int ident, float *axes );
void    glutJoystickSetMaxRange( int ident, float *axes );
void    glutJoystickSetCenter( int ident, float *axes );
void    glutJoystickGetMinRange( int ident, float *axes );
void    glutJoystickGetMaxRange( int ident, float *axes );
void    glutJoystickGetCenter( int ident, float *axes );

/*
 * Initialization functions, see fg_init.c
 */
/* to get the typedef for va_list */
#include <stdarg.h>
FGAPI void    FGAPIENTRY glutInitContextVersion( int majorVersion, int minorVersion );
FGAPI void    FGAPIENTRY glutInitContextFlags( int flags );
FGAPI void    FGAPIENTRY glutInitContextProfile( int profile );
FGAPI void    FGAPIENTRY glutInitErrorFunc( void (* callback)( const char *fmt, va_list ap ) );
FGAPI void    FGAPIENTRY glutInitWarningFunc( void (* callback)( const char *fmt, va_list ap ) );

/* OpenGL >= 2.0 support */
FGAPI void    FGAPIENTRY glutSetVertexAttribCoord3(GLint attrib);
FGAPI void    FGAPIENTRY glutSetVertexAttribNormal(GLint attrib);
FGAPI void    FGAPIENTRY glutSetVertexAttribTexCoord2(GLint attrib);

/* Mobile platforms lifecycle */
FGAPI void    FGAPIENTRY glutInitContextFunc(void (* callback)());
FGAPI void    FGAPIENTRY glutAppStatusFunc(void (* callback)(int));
/* state flags that can be passed to callback set by glutAppStatusFunc */
#define GLUT_APPSTATUS_PAUSE                0x0001
#define GLUT_APPSTATUS_RESUME               0x0002

/*
 * GLUT API macro definitions -- the display mode definitions
 */
#define  GLUT_CAPTIONLESS                   0x0400
#define  GLUT_BORDERLESS                    0x0800
#define  GLUT_SRGB                          0x1000

#ifdef __cplusplus
    }
#endif

/*** END OF FILE ***/

#endif /* __FREEGLUT_EXT_H__ */
```
## freeglut.h
```cpp
#ifndef  __FREEGLUT_H__
#define  __FREEGLUT_H__

/*
 * 
 *
 * The freeglut library include file
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * PAWEL W. OLSZTA BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "freeglut_std.h"
#include "freeglut_ext.h"

 /*** END OF FILE ***/

#endif /* __FREEGLUT_H__ */
```
## glut.h
```cpp
#ifndef  __GLUT_H__
#define  __GLUT_H__

/*
 * glut.h
 *
 * The freeglut library include file
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * PAWEL W. OLSZTA BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "freeglut_std.h"

 /*** END OF FILE ***/

#endif /* __GLUT_H__ */
```
## graph.h
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "freeglut.h"
#include <string>
#include <thread>
using namespace std;

const int maxSize = 8;
class Graph
{
private:
    vector<int> vertList; //список вершин графа
    int adjMatrix[maxSize][maxSize]; //матрица смежности для представления ребер
public:
    Graph();
    bool isEmpty(); //проверка на пустоту графа
    bool isFull(); //проверка на заполненность
    int getVertText(int i); //получение номера вершины
    void getAdjMatrix(int(&matrix)[maxSize][maxSize]);
    int getAmountVerts(); //получение количества вершин
    int getVertPos(const int& vertex); //получение позиции вершины
    void insertVertex(const int& vertex); //добавление вершины
    void insertEdge(const int& vertex1, const int& vertex2, int weight); //добавление направленного ребра
    void insertEdgeWO(const int& vertex1, const int& vertex2, int weight); //добавление ненаправленного ребра
    void print(); //печать матрицы
    void eraseEdge(const int& vertex1, const int& vertex2); // удаление ребра
    void eraseVertex(const int& vertex); //удаление вершины
    void dijkstra(int startVertex); // дейкстра
    void BFS(int startVertex); // обход в ширину
    void DFS(int startVertex); // обход в глубину
    void dfsRec(vector<bool>& visited, int currVertex, const vector<int>& vertList, int adjMatrix[][maxSize]); //рекурсия для обхода в глубину
    void drawGraph();
};
void drawCircle(int x, int y, int R); //рисует круг на экране
void display(); //Функция отображения для графического интерфейса
void drawVertex(int n); //Рисует вершину графа
void setCoords(int i, int n); //Задает координаты вершины
void drawLine(int text, int x0, int y0, int x1, int y1, int start, int end, bool f); //Рисует линию между двумя вершинами графа
void drawText(int text, int x1, int y1, bool f); //Отображает текст на экране
void menu(); //Отображает меню
void makegraph(); //Создает и отображает граф на экране
```
## graph.cpp
```cpp
#include "graph.h"
#include "iostream"
struct vertCoord {
    int x, y; //координаты вершины
};
int WinW = 800; //ширина графического окна
int WinH = 800; //высота графического окна
vertCoord vertC[maxSize]; //массив координат вершин
Graph graph;

int R = 50; //радиус вершин при рисовании
using namespace std;

//Инициализирует матрицу смежности нулями
Graph::Graph() {
    for (int i = 0; i < maxSize; i++)
        for (int j = 0; j < maxSize; j++)
            adjMatrix[i][j] = 0;
}

//Проверяет, пуст ли граф, проверяя, есть ли вершины в списке вершин	
bool Graph::isEmpty() {
    return (vertList.size() == 0);
}

//Проверяет, заполнен ли граф, проверяя, достигло ли количество вершин максимального размера
bool Graph::isFull() {
    return (vertList.size() == maxSize);
}

//Возвращает номер вершины по ее индексу в списке вершин
int Graph::getVertText(int i) {
    return vertList[i];
}

//Копирует матрицу смежности во внешнюю матрицу, переданную по ссылке
void Graph::getAdjMatrix(int(&matrix)[maxSize][maxSize])
{
    for (int i = 0; i < maxSize; i++) {
        for (int j = 0; j < maxSize; j++) {
            matrix[i][j] = adjMatrix[i][j];
        }
    }
}

//Метод возвращает количество вершин в графе, т.е. размер вектора вершин. Если граф пуст, то метод вернет 0
int Graph::getAmountVerts() {
    return vertList.size();
}

//Ищет позицию вершины в списке вершин
int Graph::getVertPos(const int& vertex) {
    //Проходит по списку вершин и возвращает индекс вершины, соответствующей переданному значению вершины
    for (int i = 0; i < vertList.size(); i++)
        if (vertList[i] == vertex)
            return i;
    //Если вершина не найдена, возвращает - 1
    return -1;
}

//Добавляет новую вершину в граф
void Graph::insertVertex(const int& vertex) {
    //Проверяет, заполнен ли граф, и выводит сообщение, если он заполнен
    if (isFull()) {
        cout << "Граф уже заполнен. Невозможнодобавить новую вершину" << endl;
        return;
    }
    vertList.push_back(vertex); //Добавляет вершину в список вершин
}

//Добавляет направленное ребро в граф
void Graph::insertEdge(const int& vertex1, const int& vertex2, int weight) {
    //Проверяет, допустимо ли значение веса ребра и существуют ли обе вершины
    if (weight < 1) {
        cout << "Нельзя ввести значение меньше 1 " << endl;
        return;
    }
    if (getVertPos(vertex1) == -1 || getVertPos(vertex2) == -1) {
        cout << "Обеих вершин(или одной из них) нет в графе " << endl;
        return;
    }
    //Добавляет ребро в матрицу смежности, используя позиции вершин в списке вершин
    int vertPos1 = getVertPos(vertex1);
    int vertPos2 = getVertPos(vertex2);
    if (adjMatrix[vertPos1][vertPos2] != 0) {
        cout << "Ребро между этими вершинами уже существует " << endl;
        return;
    }
    adjMatrix[vertPos1][vertPos2] = weight;
}

//Добавляет ненаправленное ребро в граф	
void Graph::insertEdgeWO(const int& vertex1, const int& vertex2, int weight) {
    if (weight < 1) {
        cout << "Нельзя ввести значение меньше 1 " << endl;
        return;
    }
    if (getVertPos(vertex1) == -1 || getVertPos(vertex2) == -1) {
        cout << "Обеих вершин(или одной из них) нет в графе " << endl;
        return;
    }
    //Добавляет ребро в матрицу смежности	
    int vertPos1 = getVertPos(vertex1);
    int vertPos2 = getVertPos(vertex2);
    if (adjMatrix[vertPos1][vertPos2] != 0) {
        cout << "Ребро между этими вершинами уже существует " << endl;
        return;
    }
    adjMatrix[vertPos1][vertPos2] = weight;
    adjMatrix[vertPos2][vertPos1] = weight;
}

//Печатает матрицу смежности графа
void Graph::print() {
    //Проверяет, пуст ли граф, и выводит сообщение, если это так
    if (isEmpty()) {
        cout << "Граф пуст " << endl;
        return;
    }
    cout << "     ";
    //Печатает заголовки столбцов, соответствующие номерам вершин
    for (int i = 0; i < vertList.size(); i++)
        cout << vertList[i] << "  ";
    cout << endl;
    //Печатает каждую строку матрицы смежности, соответствующую вершине, с ее номером вершины в качестве заголовка строки
    for (int i = 0; i < vertList.size(); i++) {
        cout << vertList[i] << "|   ";
        for (int j = 0; j < vertList.size(); j++)
            cout << adjMatrix[i][j] << "  ";
        cout << endl;
    }
}
void Graph::eraseEdge(const int& vertex1, const int& vertex2) {
    if (getVertPos(vertex1) == -1 || getVertPos(vertex2) == -1) {
        cout << "Одной или обоих вершин не существует " << endl;
        return;
    }

    int vertPos1 = getVertPos(vertex1);
    int vertPos2 = getVertPos(vertex2);
    if (adjMatrix[vertPos1][vertPos2] == 0) {
        cout << " Ребра нет" << endl;
        return;
    }
    adjMatrix[vertPos1][vertPos2] = 0;
}
void Graph::eraseVertex(const int& vertex)
{
    auto it = find(vertList.begin(), vertList.end(), vertex);
    if (it == vertList.end()) {
        cout << "Вершина не найдена" << endl;
        return;
    }
    int index = distance(vertList.begin(), it);
    vertList.erase(it);
    for (int i = index; i < vertList.size(); i++) {
        for (int j = 0; j < vertList.size(); j++) {
            adjMatrix[i][j] = adjMatrix[i + 1][j];
            adjMatrix[j][i] = adjMatrix[j][i + 1];
        }
    }
    for (int i = 0; i < vertList.size(); i++) {
        adjMatrix[vertList.size()][i] = 0;
        adjMatrix[i][vertList.size()] = 0;
    }
}
void Graph::dijkstra(int startVertex)
{
    int n = vertList.size();
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    distance[startVertex] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, startVertex });
    while (!pq.empty()) {
        int currVertex = pq.top().second;
        pq.pop();
        if (visited[currVertex])
            continue;
        visited[currVertex] = true;
        for (int i = 0; i < n; i++) {
            if (adjMatrix[currVertex][i] != 0) {
                int nextVertex = i;
                int weight = adjMatrix[currVertex][i];
                if (!visited[nextVertex] && distance[currVertex] != INT_MAX && distance[currVertex] + weight < distance[nextVertex]) {
                    distance[nextVertex] = distance[currVertex] + weight;
                    pq.push({ distance[nextVertex], nextVertex });
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Самый короткий путь из " << vertList[startVertex] << " до " << vertList[i] << ": ";
        if (distance[i] == INT_MAX)
            cout << " пути нет ";
        else
            cout << distance[i];
        cout << endl;
    }
}
void Graph::BFS(int startVertex)
{
    if (isEmpty()) {
        cout << "Граф пуст" << endl;
        return;
    }
    int n = vertList.size();
    vector<bool> visited(n, false);
    queue<int> q;
    visited[startVertex] = true;
    q.push(startVertex);
    while (!q.empty()) {
        int currVertex = q.front();
        q.pop();
        cout << this->getVertText(currVertex) << " ";
        for (int i = 0; i < n; i++) {
            if (adjMatrix[currVertex][i] != 0 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}
void Graph::DFS(int startVertex) {
    if (isEmpty()) {
        cout << "Граф пуст" << endl;
        return;
    }
    int n = vertList.size();
    vector<bool> visited(n, false);
    cout << "Обход в глубину: ";
    dfsRec(visited, startVertex, vertList, adjMatrix);
    cout << endl;
}
void Graph::dfsRec(vector<bool>& visited, int currVertex, const vector<int>& vertList, int adjMatrix[][maxSize]) {
    visited[currVertex] = true;
    cout << this->getVertText(currVertex) << " ";
    for (int i = 0; i < vertList.size(); i++) {
        if (adjMatrix[currVertex][i] != 0 && !visited[i]) {
            dfsRec(visited, i, vertList, adjMatrix);
        }
    }
}
void Graph::drawGraph() {
    int n = getAmountVerts();
    for (int i = 0; i < n; i++) {
        setCoords(i, n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a = adjMatrix[i][j];
            if (a == 0)
                continue;
            bool isPath = false;
            drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y, j, i, isPath);
        }
    }
    drawVertex(n);
    glutPostRedisplay();
}
void makegraph()
{
    int numVertices, numEdges;
    int vertexName;
    // Ввод количества вершин
    cout << "Введите количество вершин графа: ";
    cin >> numVertices;

    // Добавление вершин	
    for (int i = 0; i < numVertices; i++) {
        cout << "Введите имя вершины " << i + 1 << ": ";
        cin >> vertexName;
        graph.insertVertex(vertexName);
    }

    // Ввод количества ребер	
    cout << "Введите количество ребер графа: ";
    cin >> numEdges;

    // Добавление ребер
    int startVertex, endVertex;
    int edgeWeight;
    for (int i = 0; i < numEdges; i++) {
        cout << "Введите начальную вершину ребра " << i + 1 << ": ";
        cin >> startVertex;
        cout << "Введите конечную вершину ребра " << i + 1 << ": ";
        cin >> endVertex;
        cout << "Введите вес ребра " << i + 1 << ": ";
        cin >> edgeWeight;
        graph.insertEdgeWO(startVertex, endVertex, edgeWeight);
    }

}
void menu()
{
    while (true)
    {
        cout << "1. Обход в ширину " << endl; //BFS
        cout << "2. Обход в глубину " << endl; //DFS
        cout << "3. Алгоритм Дейкстры  " << endl; // dijkstra
        cout << "5. Добавить вершину " << endl; //insertVertex
        cout << "6. Удалить вершину  " << endl;//eraseVertex
        cout << "7. Печать матрицы " << endl; //print
        cout << "8. Добавить направленное ребро " << endl; //insertEdge
        cout << "9. Удалить ребро " << endl; //eraseEdge
        int n, temp, temp1, temp2;
        bool f = true;
        cin >> n;
        switch (n)
        {
        case 1:
            graph.print();
            cout << " Введите стартовую вершину " << endl; cin >> temp2;
            temp = graph.getVertPos(temp2);
            if (temp != -1)
                graph.BFS(temp);
            break;
        case 2:
            graph.print();
            cout << " Введите стартовую вершину " << endl; cin >> temp2;
            temp = graph.getVertPos(temp2);
            if (temp != -1)
                graph.DFS(temp);
            break;
        case 3:
            graph.print();
            cout << " Введите стартовую вершину " << endl; cin >> temp2;
            temp = graph.getVertPos(temp2);
            if (temp != -1)
                graph.dijkstra(temp);
            break;
        case 5:
            graph.print();
            while (f)
            {
                cout << "Введите номер вершины " << endl; cin >> temp;
                if (graph.getVertPos(temp) != -1) cout << " уже есть вершина с таким номером " << endl;
                else f = false;
            }
            graph.insertVertex(temp);
            f = true;
            break;
        case 6:
            graph.print();
            cout << "Введите номер вершины " << endl; cin >> temp;
            graph.eraseVertex(temp);
            break;
        case 7:
            graph.print();
            break;
        case 8:
            graph.print();
            cout << "Введите первую вершину"; cin >> temp;
            cout << "Введите вторую вершину "; cin >> temp1;
            cout << "Введите вес ребра "; cin >> temp2;
            graph.insertEdge(temp, temp1, temp2);
            break;
        case 9:
            graph.print();
            cout << "Введите первую вершину "; cin >> temp;
            cout << "Введите вторую вершину "; cin >> temp1;
            graph.eraseEdge(temp, temp1);
            break;
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
}
void drawText(int text, int x1, int y1, bool f) {
    if (f) glColor3f(0.0f, 0.0f, 1.0f);//синий для веса ребра
    else glColor3f(0.0f, 0.0f, 0.0f);//черный для номера вершины
    GLvoid* font = GLUT_BITMAP_TIMES_ROMAN_24; // Выбор шрифта для отображения текста
    string s = to_string(text); // Преобразование числа в строку
    glRasterPos2i(x1 - 5, y1 - 5);// Установка позиции для рендеринга текста
    for (size_t j = 0; j < s.length(); j++) // Цикл для рендеринга каждого символа строки
        glutBitmapCharacter(font, s[j]); // Рендеринг отдельного символа строки
}
void drawLine(int text, int x0, int y0, int x1, int y1, int start, int end, bool f) {
    if (f) glColor3f(1.0, 0.0, 0.0);
    else glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); // Начало рисования линии
    glVertex2i(x0, y0); // Первая вершина линии
    glVertex2i(x1, y1); // Вторая вершина линии
    glEnd(); // Конец рисования линии
}
//функция вычисляет координаты вершин графа, расположенных по окружности
void setCoords(int i, int n) {
    int R_;
    int x0 = WinW / 2;
    int y0 = WinH / 2;
    R = 5 * (WinW / 13) / n;
    R_ = WinW / 2 - R - 10;
    float theta = 2.0f * 3.1415926f * i / n;
    int x1 = R_ * sin(theta) + x0;
    int y1 = R_ * cos(theta) + y0;
    vertC[i].x = x1;
    vertC[i].y = y1;
}
void drawVertex(int n) {
    // Рисование окружности для вершины
    for (int i = 0; i < n; i++) {
        drawCircle(vertC[i].x, vertC[i].y, R);
        glColor3f(0.0f, 0.0f, 0.0f);
        // Рисование номера вершины
        drawText(graph.getVertText(i), vertC[i].x, vertC[i].y, false);
    }
}
//функция отвечает за отображение графа на экране
void display() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WinW, 0, WinH);
    glViewport(0, 0, WinW, WinH);
    glClear(GL_COLOR_BUFFER_BIT);
    graph.drawGraph();
    glutSwapBuffers();
}
void drawCircle(int x, int y, int R) {
    glColor3f(1.0f, 1.0f, 1.0f);
    float x1, y1;
    glBegin(GL_POLYGON); // Начинаем рисование многоугольника (окружности)
    for (int i = 0; i < 360; i++) { // Итерируемся по углам от 0 до 360 градусов
        float theta = 2.0f * 3.1415926f * float(i) / float(360); // Вычисляем угол в радианах
        x1 = R * sin(theta) + x; // Вычисляем координату x текущей точки окружности
        y1 = R * cos(theta) + y; // Вычисляем координату y текущей точки окружности
        glVertex2f(x1, y1); // Устанавливаем точку в текущих координатах
    }
    glEnd(); //Завершаем рисование многоугольника (окружности)
    glColor3f(0.0f, 0.0f, 0.0f);
    float x2, y2;
    glBegin(GL_LINE_LOOP); // Начинаем рисование линии контура окружности
    for (int i = 0; i < 360; i++) { // Итерируемся по углам от 0 до 360 градусов
        float theta = 2.0f * 3.1415926f * float(i) / float(360); // Вычисляем угол в радианах
        x2 = R * sin(theta) + x; // Вычисляем координату x текущей точки контура окружности
        y2 = R * cos(theta) + y; // Вычисляем координату y текущей точки контура окружности
        glVertex2f(x2, y2); // Устанавливаем точку в текущих координатах
    }
    glEnd(); // Завершаем рисование линии контура окружности
}
```
## main.cpp
```cpp
#include "graph.h"

int main(int argc, char* argv[])
//argc (argument count) - количество аргументов командной строки
//argv (argument vector) - массив указателей на строки, содержащие аргументы командной строки.
{
    system("chcp 1251");
    makegraph(); //создание графа
    cout << endl;
    thread console(menu);// Запуск потока для работы с консолью
    // Ввод количества ребер графа в переменную amountVerts 
    glutInit(&argc, argv); //начальная инициализация окна
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    //установка режима отображения:
    // GLUT_DEPTH включает Z-буфер (буфер глубины)
    // GLUT_DOUBLE включает двойной экранный буфер
    // GLUT_RGBA включает четырехкомпонентный цвет (используется по умолчанию)
    glutInitWindowSize(800, 800); //размер окна
    glutCreateWindow("Графы"); //заголовок окна
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f); //цвет фона
    glutDisplayFunc(display); //функция которой мы передаем имя функции для отрисовки окна
    glutMainLoop(); //запускаем всё проинициализированное, проще говоря та же ф-я main
    console.join(); //Основной поток ожидает завершения потока console, созданного ранее.
    return 0;
}
```
# Блок-схема программы
<image src="graphf.png">
	
# Тесты
<image src="graph.png">
