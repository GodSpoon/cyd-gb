└── docs
    └── src
        ├── CHANGELOG.rst
        ├── _ext
            ├── link_roles.py
            └── lv_example.py
        ├── _static
            ├── css
            │   ├── brands.min.css
            │   ├── custom.css
            │   ├── fontawesome.min.css
            │   └── solid.min.css
            ├── fonts
            │   ├── fontawesome-webfont.woff
            │   └── fontawesome-webfont.woff2
            ├── images
            │   ├── align.png
            │   ├── anim-timeline.png
            │   ├── bidi.png
            │   ├── boxmodel.png
            │   ├── favicon.png
            │   ├── gh-header.webp
            │   ├── home_1.png
            │   ├── home_2.png
            │   ├── home_3.png
            │   ├── home_4.png
            │   ├── home_5.png
            │   ├── home_6.png
            │   ├── intro_data_flow.png
            │   ├── layers.png
            │   ├── logo-dark.svg
            │   ├── logo-light.svg
            │   ├── par_child1.png
            │   ├── par_child2.png
            │   ├── par_child3.png
            │   ├── perfetto_ui.png
            │   ├── renesas
            │   │   ├── debug_btn.png
            │   │   ├── debug_ra6.png
            │   │   ├── debug_ra8.png
            │   │   ├── debug_rx72.png
            │   │   ├── generate.png
            │   │   ├── generate_smc.png
            │   │   ├── glcdc.png
            │   │   └── toolchains.png
            │   ├── scale.png
            │   ├── scale_ticks_below.png
            │   ├── scale_ticks_on_top.png
            │   └── symbols.png
            ├── jquery.js
            └── js
            │   ├── custom.js
            │   └── include_html.js
        ├── _templates
            ├── partials
            │   └── icons.html
            └── sidebar
            │   ├── search.html
            │   └── version-selector.html
        ├── conf.py
        ├── contributing
            ├── coding_style.rst
            ├── dco.rst
            ├── index.rst
            ├── introduction.rst
            ├── pull_requests.rst
            └── ways_to_contribute.rst
        ├── details
            ├── auxiliary-modules
            │   ├── file_explorer.rst
            │   ├── font_manager.rst
            │   ├── fragment.rst
            │   ├── gridnav.rst
            │   ├── ime_pinyin.rst
            │   ├── imgfont.rst
            │   ├── index.rst
            │   ├── monkey.rst
            │   ├── obj_id.rst
            │   ├── obj_property.rst
            │   ├── observer
            │   │   ├── index.rst
            │   │   ├── observer.rst
            │   │   └── observer_examples.rst
            │   ├── snapshot.rst
            │   ├── test.rst
            │   └── xml
            │   │   ├── animations.rst
            │   │   ├── api.rst
            │   │   ├── component_library.rst
            │   │   ├── components.rst
            │   │   ├── consts.rst
            │   │   ├── events.rst
            │   │   ├── fonts.rst
            │   │   ├── images.rst
            │   │   ├── index.rst
            │   │   ├── intro.rst
            │   │   ├── preview.rst
            │   │   ├── project.rst
            │   │   ├── screens.rst
            │   │   ├── styles.rst
            │   │   ├── subjects.rst
            │   │   ├── syntax.rst
            │   │   ├── translations.rst
            │   │   ├── view.rst
            │   │   └── widgets.rst
            ├── common-widget-features
            │   ├── basics.rst
            │   ├── coordinates.rst
            │   ├── events.rst
            │   ├── index.rst
            │   ├── layers.rst
            │   ├── layouts
            │   │   ├── flex.rst
            │   │   ├── grid.rst
            │   │   └── index.rst
            │   ├── scrolling.rst
            │   └── styles
            │   │   ├── index.rst
            │   │   ├── style-properties.rst
            │   │   └── styles.rst
            ├── debugging
            │   ├── gdb_plugin.rst
            │   ├── index.rst
            │   ├── log.rst
            │   ├── profiler.rst
            │   └── vg_lite_tvg.rst
            ├── index.rst
            ├── integration
            │   ├── adding-lvgl-to-your-project
            │   │   ├── building_lvgl.rst
            │   │   ├── configuration.rst
            │   │   ├── connecting_lvgl.rst
            │   │   ├── getting_lvgl.rst
            │   │   ├── index.rst
            │   │   ├── other_platforms.rst
            │   │   ├── threading.rst
            │   │   └── timer_handler.rst
            │   ├── bindings
            │   │   ├── api_json.rst
            │   │   ├── cpp.rst
            │   │   ├── index.rst
            │   │   ├── javascript.rst
            │   │   ├── micropython.rst
            │   │   └── pikascript.rst
            │   ├── boards
            │   │   ├── index.rst
            │   │   ├── riverdi.rst
            │   │   ├── toradex.rst
            │   │   └── viewe.rst
            │   ├── building
            │   │   ├── cmake.rst
            │   │   ├── index.rst
            │   │   └── make.rst
            │   ├── chip
            │   │   ├── alif.rst
            │   │   ├── arm.rst
            │   │   ├── espressif.rst
            │   │   ├── index.rst
            │   │   ├── nxp.rst
            │   │   ├── renesas
            │   │   │   ├── built_in_drivers.rst
            │   │   │   ├── index.rst
            │   │   │   ├── ra_family.rst
            │   │   │   ├── rx_family.rst
            │   │   │   ├── rza_family.rst
            │   │   │   ├── rzg_family.rst
            │   │   │   └── supported_boards.rst
            │   │   └── stm32.rst
            │   ├── driver
            │   │   ├── X11.rst
            │   │   ├── display
            │   │   │   ├── fbdev.rst
            │   │   │   ├── ft81x.rst
            │   │   │   ├── gen_mipi.rst
            │   │   │   ├── ili9341.rst
            │   │   │   ├── index.rst
            │   │   │   ├── lcd_stm32_guide.rst
            │   │   │   ├── renesas_glcdc.rst
            │   │   │   ├── st7735.rst
            │   │   │   ├── st7789.rst
            │   │   │   ├── st7796.rst
            │   │   │   └── st_ltdc.rst
            │   │   ├── index.rst
            │   │   ├── libinput.rst
            │   │   ├── opengles.rst
            │   │   ├── sdl.rst
            │   │   ├── touchpad
            │   │   │   ├── evdev.rst
            │   │   │   ├── ft6x36.rst
            │   │   │   └── index.rst
            │   │   ├── uefi.rst
            │   │   ├── wayland.rst
            │   │   └── windows.rst
            │   ├── framework
            │   │   ├── arduino.rst
            │   │   ├── index.rst
            │   │   ├── platformio.rst
            │   │   └── tasmota-berry.rst
            │   ├── ide
            │   │   ├── index.rst
            │   │   ├── mdk.rst
            │   │   └── pc-simulator.rst
            │   ├── index.rst
            │   ├── os
            │   │   ├── buildroot
            │   │   │   ├── image_generation.rst
            │   │   │   ├── index.rst
            │   │   │   ├── lvgl_app.rst
            │   │   │   └── quick_setup.rst
            │   │   ├── freertos.rst
            │   │   ├── index.rst
            │   │   ├── mqx.rst
            │   │   ├── nuttx.rst
            │   │   ├── px5.rst
            │   │   ├── qnx.rst
            │   │   ├── rt-thread.rst
            │   │   ├── torizon_os.rst
            │   │   ├── yocto
            │   │   │   ├── core_components.rst
            │   │   │   ├── index.rst
            │   │   │   ├── lvgl_recipe.rst
            │   │   │   └── terms_and_variables.rst
            │   │   └── zephyr.rst
            │   └── renderers
            │   │   ├── arm2d.rst
            │   │   ├── index.rst
            │   │   ├── nema_gfx.rst
            │   │   ├── nxp_g2d.rst
            │   │   ├── nxp_pxp.rst
            │   │   ├── nxp_vglite_gpu.rst
            │   │   ├── sdl.rst
            │   │   ├── stm32_dma2d.rst
            │   │   ├── sw.rst
            │   │   └── vg_lite.rst
            ├── libs
            │   ├── arduino_esp_littlefs.rst
            │   ├── arduino_sd.rst
            │   ├── barcode.rst
            │   ├── bmp.rst
            │   ├── ffmpeg.rst
            │   ├── freetype.rst
            │   ├── fs.rst
            │   ├── gif.rst
            │   ├── index.rst
            │   ├── lfs.rst
            │   ├── libjpeg_turbo.rst
            │   ├── libpng.rst
            │   ├── lodepng.rst
            │   ├── qrcode.rst
            │   ├── rle-compress-statistics.png
            │   ├── rle.rst
            │   ├── rlottie.rst
            │   ├── svg.rst
            │   ├── tiny_ttf.rst
            │   └── tjpgd.rst
            ├── main-modules
            │   ├── animation.rst
            │   ├── color.rst
            │   ├── display
            │   │   ├── color_format.rst
            │   │   ├── display_events.rst
            │   │   ├── display_events_list.txt
            │   │   ├── extending_combining.rst
            │   │   ├── inactivity.rst
            │   │   ├── index.rst
            │   │   ├── overview.rst
            │   │   ├── redraw_area.rst
            │   │   ├── refreshing.rst
            │   │   ├── resolution.rst
            │   │   ├── rotation.rst
            │   │   ├── screen_layers.rst
            │   │   ├── setup.rst
            │   │   └── tiling.rst
            │   ├── draw
            │   │   ├── draw_api.rst
            │   │   ├── draw_descriptors.rst
            │   │   ├── draw_layers.rst
            │   │   ├── draw_pipeline.rst
            │   │   └── index.rst
            │   ├── font.rst
            │   ├── fs.rst
            │   ├── image.rst
            │   ├── indev.rst
            │   ├── index.rst
            │   └── timer.rst
            └── widgets
            │   ├── 3dtexture.rst
            │   ├── animimg.rst
            │   ├── arc.rst
            │   ├── arclabel.rst
            │   ├── bar.rst
            │   ├── base_widget.rst
            │   ├── button.rst
            │   ├── buttonmatrix.rst
            │   ├── calendar.rst
            │   ├── canvas.rst
            │   ├── chart.rst
            │   ├── checkbox.rst
            │   ├── dropdown.rst
            │   ├── image.rst
            │   ├── imagebutton.rst
            │   ├── index.rst
            │   ├── keyboard.rst
            │   ├── label.rst
            │   ├── led.rst
            │   ├── line.rst
            │   ├── list.rst
            │   ├── lottie.rst
            │   ├── menu.rst
            │   ├── msgbox.rst
            │   ├── new_widget.rst
            │   ├── roller.rst
            │   ├── scale.rst
            │   ├── slider.rst
            │   ├── spangroup.rst
            │   ├── spinbox.rst
            │   ├── spinner.rst
            │   ├── switch.rst
            │   ├── table.rst
            │   ├── tabview.rst
            │   ├── textarea.rst
            │   ├── tileview.rst
            │   └── win.rst
        ├── index.rst
        ├── intro
            ├── getting_started.rst
            ├── index.rst
            └── introduction.rst
        └── lvgl_version.py


/docs/src/_ext/link_roles.py:
--------------------------------------------------------------------------------
 1 | # based on http://protips.readthedocs.io/link-roles.html
 2 | 
 3 | #from __future__ import print_function, unicode_literals
 4 | 
 5 | import os
 6 | import re
 7 | import subprocess
 8 | from collections import namedtuple
 9 | 
10 | from docutils import nodes
11 | from sphinx.transforms.post_transforms import SphinxPostTransform
12 | 
13 | URL_BASE = {
14 |     "zh_CN": "https://lvgl.100ask.net/"
15 | }
16 | 
17 | class translation_link(nodes.Element):
18 |     """Node for "link_to_translation" role."""
19 | 
20 | 
21 | # Linking to translation is done at the "writing" stage to avoid issues with the info being cached between builders
22 | def link_to_translation(name, rawtext, text, lineno, inliner, options={}, content=[]):
23 |     node = translation_link()
24 |     node['expr'] = (rawtext, text, options)
25 |     return [node], []
26 | 
27 | 
28 | class TranslationLinkNodeTransform(SphinxPostTransform):
29 |     # Transform needs to happen early to ensure the new reference node is also transformed
30 |     default_priority = 0
31 | 
32 |     def run(self, **kwargs):
33 |         # Only output relative links if building HTML
34 |         for node in self.document.traverse(translation_link):
35 |             if 'html' in self.app.builder.name:
36 |                 rawtext, text, options = node['expr']
37 |                 (language, link_text) = text.split(':')
38 |                 env = self.document.settings.env
39 |                 docname = env.docname
40 |                 # doc_path = env.doc2path(docname, False)
41 |                 if "LVGL_URLPATH" not in os.environ:
42 |                     os.environ['LVGL_URLPATH'] = 'master'
43 |                 urlpath = os.getenv('LVGL_URLPATH')+'/'
44 |                 return_path = URL_BASE.get(language, "") + urlpath
45 | 
46 |                 url = '{}.html'.format(os.path.join(return_path, docname))
47 | 
48 |                 node.replace_self(nodes.reference(rawtext, link_text, refuri=url, **options))
49 |             else:
50 |                 node.replace_self([])
51 | 
52 | 
53 | def setup(app):
54 | 
55 |     # link to the current documentation file in specific language version
56 |     app.add_role('link_to_translation', link_to_translation)
57 |     app.add_node(translation_link)
58 |     app.add_post_transform(TranslationLinkNodeTransform)
59 | 
60 |     return {'parallel_read_safe': True, 'parallel_write_safe': True, 'version': '0.5'}
61 | 


--------------------------------------------------------------------------------
/docs/src/_static/css/solid.min.css:
--------------------------------------------------------------------------------
1 | /*!
2 |  * Font Awesome Free 6.0.0 by @fontawesome - https://fontawesome.com
3 |  * License - https://fontawesome.com/license/free (Icons: CC BY 4.0, Fonts: SIL OFL 1.1, Code: MIT License)
4 |  * Copyright 2022 Fonticons, Inc.
5 |  */
6 | :host,:root{--fa-font-solid:normal 900 1em/1 "Font Awesome 6 Free"}@font-face{font-family:"Font Awesome 6 Free";font-style:normal;font-weight:900;font-display:block;src:url(../webfonts/fa-solid-900.woff2) format("woff2"),url(../webfonts/fa-solid-900.ttf) format("truetype")}.fa-solid,.fas{font-family:"Font Awesome 6 Free";font-weight:900}


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/fonts/fontawesome-webfont.woff


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/fonts/fontawesome-webfont.woff2


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/align.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/anim-timeline.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/bidi.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/boxmodel.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/favicon.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/gh-header.webp


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/home_1.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/home_2.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/home_3.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/home_4.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/home_5.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/home_6.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/intro_data_flow.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/layers.png


--------------------------------------------------------------------------------
 1 | <svg width="84" height="32" viewBox="0 0 84 32" fill="none" xmlns="http://www.w3.org/2000/svg">
 2 | <path d="M72.105 24.7871V9.21293H75.3732V22.0722H82V24.7871H72.105Z" fill="white"/>
 3 | <path d="M66.3305 14.2471C66.2249 13.8771 66.0764 13.5501 65.8852 13.2662C65.694 12.9772 65.46 12.7338 65.1833 12.5361C64.9116 12.3333 64.5996 12.1787 64.2474 12.0722C63.9002 11.9658 63.5153 11.9125 63.0926 11.9125C62.3026 11.9125 61.6082 12.1103 61.0094 12.5057C60.4157 12.9011 59.9528 13.4766 59.6207 14.2319C59.2886 14.9823 59.1225 15.8999 59.1225 16.9848C59.1225 18.0697 59.286 18.9924 59.6131 19.7529C59.9402 20.5133 60.4031 21.0938 61.0019 21.4943C61.6007 21.8897 62.3076 22.0875 63.1228 22.0875C63.8624 22.0875 64.4939 21.9556 65.0172 21.692C65.5456 21.4233 65.9481 21.0456 66.2249 20.5589C66.5066 20.0722 66.6475 19.4968 66.6475 18.8327L67.3117 18.9316H63.3266V16.4525H69.7949V18.4144C69.7949 19.7833 69.5081 20.9594 68.9345 21.943C68.3609 22.9214 67.5709 23.6768 66.5645 24.2091C65.5582 24.7364 64.4059 25 63.1077 25C61.6585 25 60.3855 24.6781 59.2886 24.0342C58.1916 23.3853 57.3362 22.4651 56.7224 21.2738C56.1135 20.0773 55.8091 18.6578 55.8091 17.0152C55.8091 15.7529 55.9902 14.6274 56.3525 13.6388C56.7198 12.6451 57.2331 11.8035 57.8922 11.1141C58.5514 10.4246 59.3188 9.89987 60.1943 9.53992C61.0698 9.17997 62.0183 9 63.0397 9C63.9153 9 64.7304 9.12928 65.4852 9.38783C66.24 9.64132 66.9092 10.0013 67.4929 10.4677C68.0816 10.9341 68.5621 11.4892 68.9345 12.1331C69.3068 12.7719 69.5458 13.4766 69.6515 14.2471H66.3305Z" fill="white"/>
 4 | <path d="M44.2282 9.21293L47.9642 21.0456H48.1076L51.8513 9.21293H55.4742L50.1455 24.7871H45.9339L40.5977 9.21293H44.2282Z" fill="white"/>
 5 | <path d="M32 24.7871V9.21293H35.2681V22.0722H41.895V24.7871H32Z" fill="white"/>
 6 | <path fill-rule="evenodd" clip-rule="evenodd" d="M2.76924 5C1.23984 5 1.31567e-05 6.23982 9.79524e-06 7.76922L1.63168e-06 11.4615C1.63168e-06 11.9713 0.413277 12.3846 0.923079 12.3846H6.46154C7.48114 12.3846 8.30769 13.2112 8.30769 14.2308V19.7692C8.30769 20.279 8.72097 20.6923 9.23077 20.6923H14.7692C15.7888 20.6923 16.6154 21.5189 16.6154 22.5385V28.0769C16.6154 28.5867 17.0287 29 17.5385 29H21.2308C22.7602 29 24 27.7602 24 26.2308V7.76923C24 6.23983 22.7602 5 21.2308 5H2.76924ZM20.7692 9.61538C21.5339 9.61538 22.1538 8.99547 22.1538 8.23077C22.1538 7.46607 21.5339 6.84615 20.7692 6.84615C20.0045 6.84615 19.3846 7.46607 19.3846 8.23077C19.3846 8.99547 20.0045 9.61538 20.7692 9.61538Z" fill="white"/>
 7 | <path d="M0.00011268 14.6308C0.00011268 14.121 0.413388 13.7077 0.92319 13.7077H6.06165C6.57145 13.7077 6.98473 14.121 6.98473 14.6308V19.7692C6.98473 20.279 6.57145 20.6923 6.06165 20.6923H0.923189C0.413387 20.6923 0.00011268 20.279 0.00011268 19.7692V14.6308Z" fill="white"/>
 8 | <path d="M0 22.9385C0 22.4287 0.413276 22.0154 0.923077 22.0154H6.06154C6.57134 22.0154 6.98462 22.4287 6.98462 22.9385V28.0769C6.98462 28.5867 6.57134 29 6.06154 29H2.76923C1.23983 29 0 27.7602 0 26.2308V22.9385Z" fill="white"/>
 9 | <path d="M8.30771 22.9385C8.30771 22.4287 8.72098 22.0154 9.23078 22.0154H14.3692C14.879 22.0154 15.2923 22.4287 15.2923 22.9385V28.0769C15.2923 28.5867 14.879 29 14.3692 29H9.23078C8.72098 29 8.30771 28.5867 8.30771 28.0769V22.9385Z" fill="white"/>
10 | </svg>
11 | 


--------------------------------------------------------------------------------
 1 | <svg width="82" height="32" viewBox="0 0 82 32" fill="none" xmlns="http://www.w3.org/2000/svg">
 2 | <path d="M72.105 24.7871V9.21293H75.3732V22.0722H82V24.7871H72.105Z" fill="#343839"/>
 3 | <path d="M66.3305 14.2471C66.2249 13.8771 66.0764 13.5501 65.8852 13.2662C65.694 12.9772 65.46 12.7338 65.1833 12.5361C64.9116 12.3333 64.5996 12.1787 64.2474 12.0722C63.9002 11.9658 63.5153 11.9125 63.0926 11.9125C62.3026 11.9125 61.6082 12.1103 61.0094 12.5057C60.4157 12.9011 59.9528 13.4766 59.6207 14.2319C59.2886 14.9823 59.1225 15.8999 59.1225 16.9848C59.1225 18.0697 59.286 18.9924 59.6131 19.7529C59.9402 20.5133 60.4031 21.0938 61.0019 21.4943C61.6007 21.8897 62.3076 22.0875 63.1228 22.0875C63.8624 22.0875 64.4939 21.9556 65.0172 21.692C65.5456 21.4233 65.9481 21.0456 66.2249 20.5589C66.5066 20.0722 66.6475 19.4968 66.6475 18.8327L67.3117 18.9316H63.3266V16.4525H69.7949V18.4144C69.7949 19.7833 69.5081 20.9594 68.9345 21.943C68.3609 22.9214 67.5709 23.6768 66.5645 24.2091C65.5582 24.7364 64.4059 25 63.1077 25C61.6585 25 60.3855 24.6781 59.2886 24.0342C58.1916 23.3853 57.3362 22.4651 56.7224 21.2738C56.1135 20.0773 55.8091 18.6578 55.8091 17.0152C55.8091 15.7529 55.9902 14.6274 56.3525 13.6388C56.7198 12.6451 57.2331 11.8035 57.8922 11.1141C58.5514 10.4246 59.3188 9.89987 60.1943 9.53992C61.0698 9.17997 62.0183 9 63.0397 9C63.9153 9 64.7304 9.12928 65.4852 9.38783C66.24 9.64132 66.9092 10.0013 67.4929 10.4677C68.0816 10.9341 68.5621 11.4892 68.9345 12.1331C69.3068 12.7719 69.5458 13.4766 69.6515 14.2471H66.3305Z" fill="#343839"/>
 4 | <path d="M44.2282 9.21293L47.9642 21.0456H48.1076L51.8513 9.21293H55.4742L50.1455 24.7871H45.9339L40.5977 9.21293H44.2282Z" fill="#343839"/>
 5 | <path d="M32 24.7871V9.21293H35.2681V22.0722H41.895V24.7871H32Z" fill="#343839"/>
 6 | <path fill-rule="evenodd" clip-rule="evenodd" d="M2.76924 5C1.23984 5 1.31567e-05 6.23982 9.79524e-06 7.76922L1.63168e-06 11.4615C1.63168e-06 11.9713 0.413277 12.3846 0.923079 12.3846H6.46154C7.48114 12.3846 8.30769 13.2112 8.30769 14.2308V19.7692C8.30769 20.279 8.72097 20.6923 9.23077 20.6923H14.7692C15.7888 20.6923 16.6154 21.5189 16.6154 22.5385V28.0769C16.6154 28.5867 17.0287 29 17.5385 29H21.2308C22.7602 29 24 27.7602 24 26.2308V7.76923C24 6.23983 22.7602 5 21.2308 5H2.76924ZM20.7692 9.61538C21.5339 9.61538 22.1538 8.99547 22.1538 8.23077C22.1538 7.46607 21.5339 6.84615 20.7692 6.84615C20.0045 6.84615 19.3846 7.46607 19.3846 8.23077C19.3846 8.99547 20.0045 9.61538 20.7692 9.61538Z" fill="#343839"/>
 7 | <path d="M0.00011268 14.6308C0.00011268 14.121 0.413388 13.7077 0.92319 13.7077H6.06165C6.57145 13.7077 6.98473 14.121 6.98473 14.6308V19.7692C6.98473 20.279 6.57145 20.6923 6.06165 20.6923H0.923189C0.413387 20.6923 0.00011268 20.279 0.00011268 19.7692V14.6308Z" fill="#F35F20"/>
 8 | <path d="M0 22.9385C0 22.4287 0.413276 22.0154 0.923077 22.0154H6.06154C6.57134 22.0154 6.98462 22.4287 6.98462 22.9385V28.0769C6.98462 28.5867 6.57134 29 6.06154 29H2.76923C1.23983 29 0 27.7602 0 26.2308V22.9385Z" fill="#62D367"/>
 9 | <path d="M8.30771 22.9385C8.30771 22.4287 8.72098 22.0154 9.23078 22.0154H14.3692C14.879 22.0154 15.2923 22.4287 15.2923 22.9385V28.0769C15.2923 28.5867 14.879 29 14.3692 29H9.23078C8.72098 29 8.30771 28.5867 8.30771 28.0769V22.9385Z" fill="#3C65F8"/>
10 | </svg>
11 | 


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/par_child1.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/par_child2.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/par_child3.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/perfetto_ui.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/renesas/debug_btn.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/renesas/debug_ra6.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/renesas/debug_ra8.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/renesas/debug_rx72.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/renesas/generate.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/renesas/generate_smc.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/renesas/glcdc.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/renesas/toolchains.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/scale.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/scale_ticks_below.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/scale_ticks_on_top.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/_static/images/symbols.png


--------------------------------------------------------------------------------
/docs/src/_static/js/include_html.js:
--------------------------------------------------------------------------------
 1 | 
 2 | /*https://www.w3schools.com/howto/howto_html_include.asp*/
 3 | function includeHTML() {
 4 |   var z, i, elmnt, file, xhttp;
 5 |   /*loop through a collection of all HTML elements:*/
 6 |   z = document.getElementsByTagName("*");
 7 |   for (i = 0; i < z.length; i++) {
 8 |     elmnt = z[i];
 9 |     /*search for elements with a certain attribute:*/
10 |     file = elmnt.getAttribute("include-html");
11 |     if (file) {
12 |       /*make an HTTP request using the attribute value as the file name:*/
13 |       xhttp = new XMLHttpRequest();
14 |       xhttp.onreadystatechange = function() {
15 |         if (this.readyState == 4) {
16 |           if (this.status == 200) {elmnt.innerHTML = this.responseText;}
17 |           if (this.status == 404) {elmnt.innerHTML = "Page not found.";}
18 |           /*remove the attribute, and call this function once more:*/
19 |           elmnt.removeAttribute("w3-include-html");
20 |           includeHTML();
21 |         }
22 |       }
23 |       xhttp.open("GET", file, true);
24 |       xhttp.send();
25 |       /*exit the function:*/
26 |       return;
27 |     }
28 |   }
29 | };


--------------------------------------------------------------------------------
/docs/src/_templates/sidebar/search.html:
--------------------------------------------------------------------------------
1 | <form class="sidebar-search-container" method="get" action="{{ pathto('search') }}" role="search">
2 |   <input class="sidebar-search" placeholder="{{ _("Search Documentation") }}" name="q" aria-label="{{ _("Search" ) }}">
3 |   <input type="hidden" name="check_keywords" value="yes" />
4 |   <input type="hidden" name="area" value="default" />
5 | </form>
6 | <div id="searchbox"></div>
7 | 


--------------------------------------------------------------------------------
/docs/src/_templates/sidebar/version-selector.html:
--------------------------------------------------------------------------------
1 | <div class="version-selector">
2 |   <label for="version_dropdown">Select LVGL version</label>
3 |   <select name="version" id="version_dropdown"></select>
4 | </div>
5 | 


--------------------------------------------------------------------------------
/docs/src/contributing/dco.rst:
--------------------------------------------------------------------------------
 1 | .. _contributing_dco:
 2 | 
 3 | =======================================
 4 | Developer Certification of Origin (DCO)
 5 | =======================================
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | To ensure all licensing criteria are met for every repository of the
11 | LVGL project, we apply a process called DCO (Developer's Certificate of
12 | Origin).
13 | 
14 | The text of DCO can be read here: https://developercertificate.org/.
15 | 
16 | By contributing to any repositories of the LVGL project you agree that
17 | your contribution complies with the DCO.
18 | 
19 | If your contribution fulfills the requirements of the DCO, no further
20 | action is needed. If you are unsure feel free to ask us in a comment,
21 | e.g. in your submitted :ref:`Pull Request <contributing_pull_requests>`.
22 | 
23 | 
24 | 
25 | Accepted Licenses and Copyright Notices
26 | ***************************************
27 | 
28 | To make the DCO easier to digest, here are some practical guides about
29 | specific cases:
30 | 
31 | Your own work
32 | -------------
33 | 
34 | The simplest case is when the contribution is solely your own work. In
35 | this case you can just send a Pull Request without worrying about any
36 | licensing issues.
37 | 
38 | Using code from an online source
39 | --------------------------------
40 | 
41 | If the code you would like to add is based on an article, post or
42 | comment on a website (e.g. StackOverflow) the license and/or rules of
43 | that site should be followed.
44 | 
45 | For example in case of StackOverflow a notice like this can be used:
46 | 
47 | .. code-block::
48 | 
49 |    /* The original version of this code-snippet was published on StackOverflow.
50 |     * Post: http://stackoverflow.com/questions/12345
51 |     * Author: http://stackoverflow.com/users/12345/username
52 |     * The following parts of the snippet were changed:
53 |     * - Check this or that
54 |     * - Optimize performance here and there
55 |     */
56 |     ... code snippet here ...
57 | 
58 | Using MIT-licensed code
59 | -----------------------
60 | 
61 | As LVGL is MIT licensed, other MIT licensed code can be integrated
62 | without issues. The MIT license requires a copyright notice be added to
63 | the derived work. Any derivative work based on MIT licensed code must
64 | copy the original work's license file or text.
65 | 
66 | Use GPL-licensed code
67 | ---------------------
68 | 
69 | The GPL license is not compatible with the MIT license. Therefore, LVGL
70 | cannot accept GPL licensed code.
71 | 


--------------------------------------------------------------------------------
/docs/src/contributing/index.rst:
--------------------------------------------------------------------------------
 1 | .. _contributing:
 2 | 
 3 | ============
 4 | Contributing
 5 | ============
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 1
 9 | 
10 |     introduction
11 |     ways_to_contribute
12 |     pull_requests
13 |     dco
14 |     coding_style
15 | 


--------------------------------------------------------------------------------
/docs/src/contributing/introduction.rst:
--------------------------------------------------------------------------------
 1 | .. _contributing_intro:
 2 | 
 3 | ============
 4 | Introduction
 5 | ============
 6 | 
 7 | Join LVGL's community and leave your footprint in the library!
 8 | 
 9 | There are a lot of ways to contribute to LVGL even if you are new to the
10 | library or even new to programming.
11 | 
12 | It might be scary to make the first step but you have nothing to be
13 | afraid of. A friendly and helpful community is waiting for you. Get to
14 | know like-minded people and make something great together.
15 | 
16 | So let's find which contribution option fits you the best and helps you
17 | join the development of LVGL!
18 | 
19 | 


--------------------------------------------------------------------------------
/docs/src/contributing/ways_to_contribute.rst:
--------------------------------------------------------------------------------
 1 | .. _contributing_ways:
 2 | 
 3 | ==================
 4 | Ways to Contribute
 5 | ==================
 6 | 
 7 | - **Spread the Word**: Share your LVGL experience with friends or on social media to boost its visibility.
 8 | - **Star LVGL**   Give us a star on `GitHub <https://github.com/lvgl/lvgl>`__! It helps a lot to make LVGL more appealing for newcomers.
 9 | - **Report a Bug**: Open a `GitHub Issue <https://github.com/lvgl/lvgl/issues>`__ if something is not working.
10 | - **Join Our** `Forum <https://forum.lvgl.io/>`__ : Meet fellow developers and discuss questions.
11 | - **Tell Us Your Ideas**: If you feel something is missing from LVGL, we would love to hear about it in a `GitHub Issue <https://github.com/lvgl/lvgl/issues>`__
12 | - **Develop Features**: Help to design or develop a feature. See below.
13 | 
14 | Mid- and large-scale issues are discussed in `Feature Planning <https://github.com/lvgl/lvgl/issues/new?assignees=&labels=&projects=&template=feat-planning.yml>`__ issues.
15 | 
16 | An issue can be developed when all the questions in the issue template are answered and there are no objection from any core member.
17 | 
18 | We are using GitHub labels to show the state and attributes of the issues and Pull requests.
19 | If you are looking for contribution opportunities you can `Filter for these labels <https://github.com/lvgl/lvgl/labels>`__ :
20 | 
21 | - ``Simple``: Good choice to get started with an LVGL contribution
22 | - ``PR needed``: We investigated the issue but it still needs to be implemented
23 | - ``Review needed``: A Pull request is opened and it needs review/testing
24 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/fragment.rst:
--------------------------------------------------------------------------------
 1 | .. _fragment:
 2 | 
 3 | ========
 4 | Fragment
 5 | ========
 6 | 
 7 | Fragment is a concept copied from
 8 | `Android <https://developer.android.com/guide/fragments>`__.
 9 | 
10 | It represents a reusable portion of your app's UI. A fragment defines
11 | and manages its own layout, has its own lifecycle, and can handle its
12 | own events. Like Android's Fragment that must be hosted by an activity
13 | or another fragment, Fragment in LVGL needs to be hosted by a Widget,
14 | or another fragment. The fragment's view hierarchy becomes part of, or
15 | attaches to, the host's view hierarchy.
16 | 
17 | Such concept also has some similarities to `UiViewController on
18 | iOS <https://developer.apple.com/documentation/uikit/uiviewcontroller>`__.
19 | 
20 | Fragment Manager is a manager holding references to fragments attached
21 | to it, and has an internal stack to achieve forward and backwards navigation. You can use
22 | fragment manager to build a navigation stack, or a multi-pane application
23 | easily.
24 | 
25 | 
26 | 
27 | .. _fragment_usage:
28 | 
29 | Usage
30 | *****
31 | 
32 | Enable :c:macro:`LV_USE_FRAGMENT` in ``lv_conf.h``.
33 | 
34 | Create Fragment Class
35 | ---------------------
36 | 
37 | .. code-block:: c
38 | 
39 |    struct sample_fragment_t {
40 |        /* IMPORTANT: don't miss this part */
41 |        lv_fragment_t base;
42 |        /* States, object references and data fields for this fragment */
43 |        const char *title;
44 |    };
45 | 
46 |    const lv_fragment_class_t sample_cls = {
47 |            /* Initialize something needed */
48 |            .constructor_cb = sample_fragment_ctor,
49 |            /* Create view objects */
50 |            .create_obj_cb = sample_fragment_create_obj,
51 |            /* IMPORTANT: size of your fragment struct */
52 |            .instance_size = sizeof(struct sample_fragment_t),
53 |    };
54 | 
55 | Use ``lv_fragment_manager``
56 | ---------------------------
57 | 
58 | .. code-block:: c
59 | 
60 |    /* Create fragment instance, and Widgets will be added to container */
61 |    lv_fragment_manager_t *manager = lv_fragment_manager_create(container, NULL);
62 |    /* Replace current fragment with instance of sample_cls, and init_argument is user defined pointer */
63 |    lv_fragment_manager_replace(manager, &sample_cls, init_argument);
64 | 
65 | Fragment Based Navigation
66 | -------------------------
67 | 
68 | .. code-block:: c
69 | 
70 |    /* Add one instance into manager stack. View object of current fragment will be destroyed,
71 |     * but instances created in class constructor will be kept.
72 |     */
73 |    lv_fragment_manager_push(manager, &sample_cls, NULL);
74 | 
75 |    /* Remove the top most fragment from the stack, and bring back previous one. */
76 |    lv_fragment_manager_pop(manager);
77 | 
78 | 
79 | 
80 | .. _fragment_example:
81 | 
82 | Example
83 | *******
84 | 
85 | .. include:: ../../examples/others/fragment/index.rst
86 | 
87 | 
88 | 
89 | .. _fragment_api:
90 | 
91 | API
92 | ***
93 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/gridnav.rst:
--------------------------------------------------------------------------------
 1 | .. _gridnav:
 2 | 
 3 | ===============
 4 | Grid navigation
 5 | ===============
 6 | 
 7 | Grid navigation (gridnav for short) is a feature that moves focus among a set
 8 | of child Widgets via arrow-key presses.
 9 | 
10 | If the child Widgets are arranged into a grid-like layout then the up, down,
11 | left and right arrows move focus to the nearest sibling in the
12 | respective direction.
13 | 
14 | It doesn't matter how the children are positioned, as only the current x
15 | and y coordinates are considered. This means that gridnav works with
16 | manually positioned children, as well as :ref:`flex` and
17 | :ref:`grid` layouts.
18 | 
19 | Gridnav also works if the children are arranged into a single row or
20 | column. This is useful, for example, to simplify navigation among items in a
21 | :ref:`List Widget <lv_list>`.
22 | 
23 | Gridnav assumes that the Widget to which gridnav is added is part of a
24 | :ref:`group <indev_groups>`. This way, if the Widget with
25 | gridnav has focus, the arrow key presses are automatically forwarded to
26 | the Widget so that gridnav can process the arrow keys.
27 | 
28 | To move the focus to the next widget of the group use
29 | :cpp:enumerator:`LV_KEY_NEXT` or :cpp:enumerator:`LV_KEY_PREV`.
30 | Optionally you can also use :cpp:func:`lv_group_focus_next`
31 | or :cpp:func:`lv_group_focus_prev` or the ``TAB``
32 | key on keyboard as usual.
33 | 
34 | If the container is scrollable and the focused child is out of the view,
35 | gridnav will automatically scroll the child into view.
36 | 
37 | 
38 | 
39 | .. _gridnav_usage:
40 | 
41 | Usage
42 | *****
43 | 
44 | To add gridnav behavior to any Widget (e.g. one serving as a container for
45 | child Widgets that the end user will navigate among using arrow keys) use
46 | :cpp:expr:`lv_gridnav_add(container, flags)`.
47 | 
48 | The ``flags`` argument controls the navigation behavior:
49 | 
50 | - :cpp:enumerator:`LV_GRIDNAV_CTRL_NONE`: Default settings
51 | - :cpp:enumerator:`LV_GRIDNAV_CTRL_ROLLOVER`: If there is no next/previous Widget in a
52 |   direction, the focus goes to the Widget in the next/previous row (on
53 |   left/right keys) or first/last row (on up/down keys)
54 | - :cpp:enumerator:`LV_GRIDNAV_CTRL_SCROLL_FIRST`: If an arrow is pressed and the focused
55 |   Widget can be scrolled in that direction then it will be scrolled instead of
56 |   going to the next/previous Widget. If there is no more room for scrolling the
57 |   next/previous Widget will receive focus normally.
58 | - :cpp:enumerator:`LV_GRIDNAV_CTRL_HORIZONTAL_MOVE_ONLY`: Only use the left/right keys
59 |   for grid navigation. Up/down key events will be sent to the Widget that has focus.
60 | - :cpp:enumerator:`LV_GRIDNAV_CTRL_VERTICAL_MOVE_ONLY`: Only use the up/down keys
61 |   for grid navigation. Left/right key events will be sent to the Widget that has focus.
62 | 
63 | While the above behaviors can be combined by bit-wise OR-ing the above values together,
64 | :cpp:enumerator:`LV_GRIDNAV_CTRL_HORIZONTAL_MOVE_ONLY` and :cpp:enumerator:`LV_GRIDNAV_CTRL_VERTICAL_MOVE_ONLY`
65 | should not be used together.
66 | 
67 | :cpp:expr:`lv_gridnav_remove(container)` Removes gridnav behavior from a Widget.
68 | 
69 | 
70 | 
71 | Focusable Widgets
72 | *****************
73 | 
74 | A Widget needs to be clickable or click focusable
75 | (:cpp:enumerator:`LV_OBJ_FLAG_CLICKABLE` or :cpp:enumerator:`LV_OBJ_FLAG_CLICK_FOCUSABLE`) and not
76 | hidden (:cpp:enumerator:`LV_OBJ_FLAG_HIDDEN`) to receive focus via gridnav.
77 | 
78 | 
79 | 
80 | .. _gridnav_example:
81 | 
82 | Examples
83 | ********
84 | 
85 | .. include:: ../../examples/others/gridnav/index.rst
86 | 
87 | 
88 | 
89 | .. _gridnav_api:
90 | 
91 | API
92 | ***
93 | 
94 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/imgfont.rst:
--------------------------------------------------------------------------------
 1 | .. _lv_imgfont:
 2 | 
 3 | ==========
 4 | Image font
 5 | ==========
 6 | 
 7 | Draw image in **label** or **span** obj with :cpp:type:`lv_imgfont`. This is often used to
 8 | display Unicode emoji icons in text.
 9 | 
10 | Supported image formats: determined by enabled LVGL :ref:`image decoders <overview_image_decoder>`.
11 | 
12 | 
13 | 
14 | .. _lv_imgfont_usage:
15 | 
16 | Usage
17 | *****
18 | 
19 | Enable :c:macro:`LV_USE_IMGFONT` in ``lv_conf.h``.
20 | 
21 | To create a new *imgfont*:
22 | 
23 | .. code-block:: c
24 | 
25 |     static lv_font_t  * imgfont;
26 |     ...
27 |     imgfont = lv_imgfont_create(height, path_cb, user_data);
28 | 
29 | - ``height`` Font size.
30 | - ``path_cb`` A function to get the image path of a character.
31 |   Pass ``NULL`` if no image should be shown, but the character itself.
32 | - ``user_data`` Pointer to user data.
33 | 
34 | To use the *imgfont* in a label, reference it:
35 | :cpp:expr:`lv_obj_set_style_text_font(label, imgfont, LV_PART_MAIN)`
36 | 
37 | To destroy the *imgfont* that is no longer used, use :cpp:expr:`lv_imgfont_destroy(imgfont)`.
38 | 
39 | 
40 | 
41 | .. _lv_imgfont_example:
42 | 
43 | Example
44 | *******
45 | 
46 | .. include:: ../../examples/others/imgfont/index.rst
47 | 
48 | 
49 | 
50 | .. _lv_imgfont_api:
51 | 
52 | API
53 | ***
54 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/index.rst:
--------------------------------------------------------------------------------
 1 | .. _auxiliary_modules:
 2 | 
 3 | =================
 4 | Auxiliary Modules
 5 | =================
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     file_explorer
11 |     font_manager
12 |     fragment
13 |     gridnav
14 |     ime_pinyin
15 |     imgfont
16 |     monkey
17 |     obj_id
18 |     obj_property
19 |     observer/index
20 |     snapshot
21 |     test
22 |     xml/index
23 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/monkey.rst:
--------------------------------------------------------------------------------
 1 | .. _monkey:
 2 | 
 3 | ======
 4 | Monkey
 5 | ======
 6 | 
 7 | The Monkey module provides LVGL applications with a simple monkey test.  Monkey
 8 | Testing is a technique where the user tests the application or system by providing
 9 | random inputs and checking the behavior or seeing whether the aplication or system
10 | will crash.  This module provides this service as simulated random input to stress
11 | test an LVGL application.
12 | 
13 | 
14 | 
15 | .. _monkey_usage:
16 | 
17 | Usage
18 | *****
19 | 
20 | First, enable :c:macro:`LV_USE_MONKEY` in ``lv_conf.h``.
21 | 
22 | Next, declare a variable (it can be local) of type :c:type:`lv_monkey_config_t` to
23 | define the configuration structure, initialize it using
24 | :cpp:expr:`lv_monkey_config_init(cfg)` then set its ``type`` member to the desired
25 | type of :ref:`input device <indev>`, and set the ``min`` and ``max`` values for its
26 | ``period_range`` and ``input_range`` members to set the time ranges (in milliseconds)
27 | and input ranges the Monkey module will use to generate random input at random times.
28 | 
29 | Next, call :cpp:expr:`lv_monkey_create(cfg)` to create the Monkey.  It returns a
30 | pointer to the ``lv_monkey_t`` created.
31 | 
32 | Finally call :cpp:expr:`lv_monkey_set_enable(monkey, true)` to enable Monkey.
33 | 
34 | If you want to pause the monkey, call
35 | :cpp:expr:`lv_monkey_set_enable(monkey, false)`. To delete it, call
36 | :cpp:expr:`lv_monkey_delete(monkey)`.
37 | 
38 | Note that ``input_range`` has different meanings depending on the ``type`` input device:
39 | 
40 | - :cpp:enumerator:`LV_INDEV_TYPE_POINTER`: No effect, click randomly within the pixels of the screen resolution.
41 | - :cpp:enumerator:`LV_INDEV_TYPE_ENCODER`: The minimum and maximum values of ``enc_diff``.
42 | - :cpp:enumerator:`LV_INDEV_TYPE_BUTTON`: The minimum and maximum values of ``btn_id``.
43 |   Use :cpp:func:`lv_monkey_get_indev` to get the input device, and use
44 |   :cpp:func:`lv_indev_set_button_points` to map the key ID to the coordinates.
45 | - :cpp:enumerator:`LV_INDEV_TYPE_KEYPAD`: No effect, Send random :ref:`indev_keys`.
46 | 
47 | 
48 | 
49 | .. _monkey_example:
50 | 
51 | Example
52 | *******
53 | 
54 | .. include:: ../../examples/others/monkey/index.rst
55 | 
56 | 
57 | 
58 | .. _monkey_api:
59 | 
60 | API
61 | ***
62 | 
63 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/observer/index.rst:
--------------------------------------------------------------------------------
 1 | .. _observer:
 2 | 
 3 | ========
 4 | Observer
 5 | ========
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     observer
11 |     observer_examples
12 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/observer/observer_examples.rst:
--------------------------------------------------------------------------------
1 | .. _observer examples:
2 | 
3 | ========
4 | Examples
5 | ========
6 | 
7 | .. include:: ../../../examples/others/observer/index.rst
8 | 
9 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/snapshot.rst:
--------------------------------------------------------------------------------
 1 | .. _snapshot:
 2 | 
 3 | ========
 4 | Snapshot
 5 | ========
 6 | 
 7 | Snapshot provides an API to take a snapshot image for an LVGL Widget together
 8 | with its children.  The image will look exactly like the Widget on the display.
 9 | 
10 | 
11 | 
12 | .. _snapshot_usage:
13 | 
14 | Usage
15 | *****
16 | 
17 | Simply call function :cpp:expr:`lv_snapshot_take(widget, color_format)` to generate
18 | the image descriptor which can be used as an Image Widget's image source using
19 | :cpp:func:`lv_image_set_src`.
20 | 
21 | Note, only following color formats are supported at this time:
22 | 
23 | - :cpp:enumerator:`LV_COLOR_FORMAT_RGB565`
24 | - :cpp:enumerator:`LV_COLOR_FORMAT_RGB888`
25 | - :cpp:enumerator:`LV_COLOR_FORMAT_XRGB8888`
26 | - :cpp:enumerator:`LV_COLOR_FORMAT_ARGB8888`
27 | 
28 | Freeing the Image
29 | -----------------
30 | 
31 | The memory :cpp:func:`lv_snapshot_take` uses is dynamically allocated using
32 | :cpp:func:`lv_draw_buf_create`. Use :cpp:func:`lv_draw_buf_destroy` to free the
33 | memory it allocated.
34 | 
35 | The snapshot image which is the draw buffer returned by :cpp:func:`lv_snapshot_take`
36 | normally won't be added to the cache because it can be drawn directly. So you don't need
37 | to invalidate the cache by calling :cpp:func:`lv_image_cache_drop` before destroying
38 | the draw buffer.
39 | 
40 | The below code snippet demonstrates correct use of :cpp:func:`lv_snapshot_take`:
41 | 
42 | .. code-block:: c
43 | 
44 |    void update_snapshot(lv_obj_t * widget, lv_obj_t * img_snapshot)
45 |    {
46 |        lv_draw_buf_t* snapshot = (void*)lv_image_get_src(img_snapshot);
47 |        if(snapshot) {
48 |            lv_draw_buf_destroy(snapshot);
49 |        }
50 |        snapshot = lv_snapshot_take(widget, LV_COLOR_FORMAT_ARGB8888);
51 |        lv_image_set_src(img_snapshot, snapshot);
52 |    }
53 | 
54 | Using an Existing Buffer
55 | ------------------------
56 | 
57 | If the snapshot needs to be updated repeatedly, or if the caller provides the draw
58 | buffer, use :cpp:expr:`lv_snapshot_take_to_draw_buf(widget, color_format, draw_buf)`.
59 | In this case, the caller is responsible for creating and destroying the draw buffer.
60 | 
61 | If snapshot is generated successfully, the image descriptor is updated,
62 | the image data will be stored to the provided ``draw_buf``, and the function will
63 | return :cpp:enumerator:`LV_RESULT_OK`.
64 | 
65 | Note that snapshot may fail if the provided buffer is not large enough, which can
66 | happen if the Widget's size changes.  It's recommended to use
67 | :cpp:expr:`lv_snapshot_reshape_draw_buf(widget, draw_buf)` to first ensure the buffer
68 | is large enough, and if it fails, destroy the existing draw buffer and call
69 | `lv_snapshot_take` directly.
70 | 
71 | 
72 | 
73 | .. _snapshot_example:
74 | 
75 | Example
76 | *******
77 | 
78 | .. include:: ../../examples/others/snapshot/index.rst
79 | 
80 | 
81 | 
82 | .. _snapshot_api:
83 | 
84 | API
85 | ***
86 | 
87 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/animations.rst:
--------------------------------------------------------------------------------
1 | .. _xml_animations:
2 | 
3 | ==========
4 | Animations
5 | ==========
6 | 
7 | TODO
8 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/consts.rst:
--------------------------------------------------------------------------------
 1 | .. _xml_consts:
 2 | 
 3 | =========
 4 | Constants
 5 | =========
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | Constants can be defined to replace any value with a selected type or to be used as special values.
11 | 
12 | The supported types are:
13 | - ``color``
14 | - ``px``
15 | - ``percentage``
16 | - ``string``
17 | - ``opa``
18 | - ``bool``
19 | 
20 | 
21 | 
22 | Usage
23 | *****
24 | 
25 | .. code-block:: xml
26 | 
27 |     <consts>
28 |         <color name="color1" value="0xff0000" help="Primary color"/>
29 |         <px name="pad_xs" value="8" help="Small padding"/>
30 |     </consts>
31 | 
32 | Constants can be used in:
33 | 
34 | - Style properties
35 | - Widget and Component properties
36 | 
37 | And they can be used like this:
38 | 
39 | .. code-block:: xml
40 | 
41 |     <styles>
42 |         <style name="style1" bg_color="#color1"/>
43 |     </styles>
44 | 
45 | 
46 | 
47 | Variants
48 | ********
49 | 
50 | Constants support a ``<variant>`` attribute to change the constants at compile time. For example:
51 | 
52 | .. code-block:: xml
53 | 
54 |     <consts>
55 |         <px name="pad" value="8" help="General padding">
56 |             <variant name="size" case="small" value="4"/>
57 |             <variant name="size" case="large" value="12"/>
58 |         </px>
59 |     </consts>
60 | 
61 | from which the following C code can be exported:
62 | 
63 | .. code-block:: c
64 | 
65 |     #if SIZE == SMALL
66 |         #define PAD 4
67 |     #elif SIZE == LARGE
68 |         #define PAD 12
69 |     #else
70 |         #define PAD 8
71 |     #endif
72 | 
73 | Where ``SMALL`` and ``LARGE`` are just preprocessor defines with incremental values.
74 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/events.rst:
--------------------------------------------------------------------------------
 1 | .. _xml_events:
 2 | 
 3 | ======
 4 | Events
 5 | ======
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | ``<lv_event>`` tags can be added as a child of any Widget to react to user inputs or other value changes.
11 | 
12 | Right now, only a single event type is supported to call user-defined callbacks.
13 | 
14 | 
15 | 
16 | Usage
17 | *****
18 | 
19 | 
20 | Call function
21 | -------------
22 | 
23 | User-defined functions can be called like this:
24 | 
25 | .. code-block:: xml
26 | 
27 |     <view>
28 |         <lv_button width="200" height="100">
29 |             <lv_event-call_function callback="my_callback_1" trigger="clicked" user_data="some_text"/>
30 |             <lv_label text="Hello"/>
31 |         </lv_button>
32 |     </view>
33 | 
34 | When the XML is loaded at runtime, the callback name needs to be mapped to a function by using:
35 | :cpp:expr:`lv_xml_register_event_cb("my_callback_1", an_event_handler)`.
36 | 
37 | The callback should have the standard LVGL event callback signature:
38 | ``void an_event_handler(lv_event_t * e);``
39 | 
40 | In the exported C code, it is assumed that there is a function with the exact name
41 | specified as the callback name.  For example, ``callback="my_callback_1"`` will be
42 | exported as:
43 | 
44 | .. code-block:: c
45 | 
46 |     void my_callback_1(lv_event_t * e); /* At the beginning of the exported file */
47 | 
48 |     lv_obj_add_event_cb(obj, my_callback_1, LV_EVENT_CLICKED, "some_text");
49 | 
50 | For triggers, all LVGL event types are supported with straightforward mapping:
51 | 
52 | .. What is a trigger?
53 | 
54 | - :cpp:enumerator:`LV_EVENT_ALL`: ``"all"``
55 | - :cpp:enumerator:`LV_EVENT_CLICKED`: ``"clicked"``
56 | - :cpp:enumerator:`LV_EVENT_PRESSED`: ``"pressed"``
57 | - etc.
58 | 
59 | The ``user_data`` is optional. If omitted, ``NULL`` will be passed.
60 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/images.rst:
--------------------------------------------------------------------------------
 1 | .. _xml_images:
 2 | 
 3 | ======
 4 | Images
 5 | ======
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | .. |nbsp|   unicode:: U+000A0 .. NO-BREAK SPACE
11 |     :trim:
12 | 
13 | An ``<images>`` section can be added to ``globals.xml`` files.  If present, it
14 | describes how to map images with names.
15 | 
16 | (Later, it might also be possible in Components and Widgets to define local images to
17 | keep the global space cleaner.)
18 | 
19 | Currently ``<file>`` is the only supported child element, and ``<convert>`` is not
20 | yet implemented.
21 | 
22 | 
23 | 
24 | Usage
25 | *****
26 | 
27 | .. code-block:: xml
28 | 
29 |     <images>
30 |         <file name="avatar" src_path="avatar1.png">
31 |             <convert path="raw/avatar.svg" width="100px" color_format="L8"/>
32 |         </file>
33 | 
34 |         <data name="logo" src_path="logo1.png" color-format="rgb565" memory="RAM2">
35 |             <convert path="https://foo.com/image.png" width="50%" height="80%"
36 |             color_format="RGB565"/>
37 |         </data>
38 |     </images>
39 | 
40 | - ``<file>`` means that the image source is used as a file path:
41 | - ``<data>`` means that the image is converted to a C array on export.
42 | 
43 | In both cases in the exported C code global ``const void * <image_name>`` variables are created and in the
44 | initialization function of the Component Library (e.g. ``my_lib_init_gen()``) either the path or
45 | the pointer to the converted :cpp:type:`lv_image_dsc_t` pointers are assigned to that variable.
46 | 
47 | In :cpp:expr:`lv_image_set_src(image, image_name)` ``image_name`` is used
48 | instead of the path or :cpp:type:`lv_image_dsc_t` pointer.
49 | 
50 | 
51 | For simplicity, in the UI |nbsp| Editor preview, images are always loaded as files.
52 | 
53 | If the UI is created from XML at runtime and a ``globals.xml`` is parsed, the ``<data>`` tags are skipped
54 | because it is assumed that the user manually created the mapping.  This is because the XML parser cannot
55 | automatically map an image like:
56 | 
57 | .. code-block:: c
58 | 
59 |    lv_image_dsc_t my_logo;
60 | 
61 | to
62 | 
63 | .. code-block:: xml
64 | 
65 |    <data name="my_logo"/>
66 | 
67 | 
68 | Constants
69 | ---------
70 | 
71 | Constants can be used with images as well.
72 | 
73 | .. code-block:: xml
74 | 
75 |     <consts>
76 |         <int name="icon_size" value="32">
77 |             <variant name="size" case="small" value="16"/>
78 |         </int>
79 |     </consts>
80 | 
81 |     <images>
82 |         <data name="icon_apply" src_path="apply.png">
83 |             <convert path="raw/apply.png" width="#icon_size"/>
84 |         </data>
85 |     </images>
86 | 
87 | 
88 | 
89 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/index.rst:
--------------------------------------------------------------------------------
 1 | .. _xml_component:
 2 | 
 3 | ====================
 4 | XML - Declarative UI
 5 | ====================
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 1
 9 | 
10 |     intro
11 |     component_library
12 |     project
13 |     syntax
14 | 
15 |     components
16 |     screens
17 |     widgets
18 | 
19 |     preview
20 |     api
21 |     styles
22 |     consts
23 |     view
24 |     fonts
25 |     images
26 |     events
27 |     subjects
28 |     animations
29 | 
30 |     translations
31 | 
32 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/preview.rst:
--------------------------------------------------------------------------------
 1 | .. _xml_preview:
 2 | 
 3 | =======
 4 | Preview
 5 | =======
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | .. |nbsp|   unicode:: U+000A0 .. NO-BREAK SPACE
11 |     :trim:
12 | 
13 | In ``<component>`` and ``<widget>``, it is possible to define ``<preview>`` tags.
14 | These are **not** exported to code and are **not** loaded from XML.
15 | 
16 | They are used only by the UI |nbsp| Editor to describe the context of the Component.
17 | For example, you might want to:
18 | 
19 | - Change the background of the Editor's preview to dark.
20 | - Center the Component.
21 | - Set margins.
22 | - Change the size of the preview.
23 | 
24 | 
25 | 
26 | Usage
27 | *****
28 | 
29 | You can think of a ``<preview>`` tag as an ``lv_obj`` where the following properties can be used:
30 | 
31 | - ``width``, ``height``
32 | - Any local style properties, for example, ``style_bg_color="0x333"``
33 | - ``flex`` and ``flex_flow``
34 | 
35 | It is also possible to define multiple previews, and in the UI |nbsp| Editor, you can
36 | select one of them.
37 | 
38 | 
39 | 
40 | Example
41 | *******
42 | 
43 | .. code-block:: xml
44 | 
45 |     <component>
46 |         <previews>
47 |             <preview name="small_dark" width="content" height="100" style_bg_color="0x333" style_pad_all="32"/>
48 |             <preview name="centered" width="200" height="100" flex="row center"/>
49 |             <preview name="large_light" width="1980" height="1080" style_bg_color="0xeeeeee"/>
50 |         </previews>
51 | 
52 |         <view>
53 |             ...
54 |         </view>
55 | 
56 |     </component>
57 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/project.rst:
--------------------------------------------------------------------------------
 1 | .. _xml_project:
 2 | 
 3 | =======
 4 | Project
 5 | =======
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | .. |nbsp|   unicode:: U+000A0 .. NO-BREAK SPACE
11 |     :trim:
12 | 
13 | A single ``project.xml`` file should be created for each project where the following
14 | content is specified:
15 | 
16 | :<folders>: Specifies the path to Component Libraries. LVGL's base Widgets are
17 |             always loaded automatically.
18 | :<targets>: Describes various hardware configurations, allowing the UI |nbsp| Editor
19 |             to check if the UI is out of resources and to select different previews
20 |             for each Screen according to the specified displays.
21 | 
22 | 
23 | 
24 | Example
25 | *******
26 | 
27 | .. code-block:: xml
28 | 
29 |     <project>
30 |         <folders>
31 |             <folder path="../widget_lib1"/>
32 |             <folder path="/home/user/work/ui_libs/modern"/>
33 |             <folder path="https://github.com/user/repo"/>
34 |         </folders>
35 | 
36 |         <targets>
37 |             <renesas-RA8D1-EK gpu="true"/>
38 | 
39 |             <target name="small">
40 |                 <display width="320" height="240" color_format="RGB565"/>
41 |                 <memory name="int_ram" size="128K"/>
42 |                 <memory name="ext_ram" size="2M"/>
43 |                 <memory name="int_flash" size="512K"/>
44 |                 <memory name="ext_flash" size="32M"/>
45 |             </target>
46 | 
47 |             <target name="large">
48 |                 <display width="1024" height="768" color_format="XRGB8888"/>
49 |                 <memory name="int_ram" size="128K"/>
50 |                 <memory name="ext_ram" size="2M"/>
51 |                 <memory name="int_flash" size="512K"/>
52 |                 <memory name="ext_flash" size="32M"/>
53 |             </target>
54 |         </targets>
55 |     </project>
56 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/screens.rst:
--------------------------------------------------------------------------------
 1 | .. _xml_screens:
 2 | 
 3 | =======
 4 | Screens
 5 | =======
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | .. |nbsp|   unicode:: U+000A0 .. NO-BREAK SPACE
11 |     :trim:
12 | 
13 | Screens work very similarly to Components. Both can be:
14 | 
15 | - Loaded from XML
16 | - Contain Widgets and Components as children
17 | - Have ``<styles>``
18 | - Have ``<consts>``
19 | - Have a ``<view>``
20 | 
21 | However, Screens **cannot** have an ``<api>``.
22 | 
23 | 
24 | 
25 | Usage
26 | *****
27 | 
28 | Each XML file describes a :ref:`Screen <screens>`.  The name of the XML file will
29 | also be the name of the Screen.
30 | 
31 | In the ``project.xml`` file, multiple ``<display>`` elements can be defined. In the
32 | UI |nbsp| Editor, when a Screen is being developed, the user can select from all the
33 | defined displays in the Preview, and the Screen will be shown with the given
34 | resolution and color depth.
35 | 
36 | This is useful for verifying responsive designs.
37 | 
38 | 
39 | 
40 | Example
41 | *******
42 | 
43 | .. code-block:: xml
44 | 
45 |     <screen>
46 |         <consts>
47 |             <string name="title" value="Main menu"/>
48 |         </consts>
49 | 
50 |         <styles>
51 |             <style name="dark" bg_color="0x333"/>
52 |         </styles>
53 | 
54 |         <view>
55 |             <header label="#title"/>
56 |             <selector_container styles="dark">
57 |                 <button text="Weather" icon="cloudy"/>
58 |                 <button text="Messages" icon="envelope"/>
59 |                 <button text="Settings" icon="cogwheel"/>
60 |                 <button text="About" icon="questionmark"/>
61 |             </selector_container>
62 |         </view>
63 |     </screen>
64 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/styles.rst:
--------------------------------------------------------------------------------
  1 | .. _xml_styles:
  2 | 
  3 | ======
  4 | Styles
  5 | ======
  6 | 
  7 | Overview
  8 | ********
  9 | 
 10 | In XML files, both style sheets (:cpp:expr:`lv_style_t`) and local styles can be used.
 11 | 
 12 | Style variants are also supported to change style properties at runtime.
 13 | 
 14 | 
 15 | 
 16 | Style Sheets
 17 | ************
 18 | 
 19 | In the ``<styles>`` section, styles and their properties can be defined like this:
 20 | 
 21 | .. code-block:: xml
 22 | 
 23 |     <style name="red"
 24 |         help="What is this style about?"
 25 |         border_width="2px"
 26 |         border_color="0xff0000"/>
 27 | 
 28 | Styles can be referenced like this in the ``<view>``:
 29 | 
 30 | .. code-block:: xml
 31 | 
 32 |     <view>
 33 |         <slider styles="main red:indicator red:knob:focused"/>
 34 |     </view>
 35 | 
 36 | As shown in the example, parts and states are appended after a ``:`` to the style's name.
 37 | 
 38 | 
 39 | 
 40 | Local Styles
 41 | ************
 42 | 
 43 | Local styles can be used directly in a Widget, for example:
 44 | 
 45 | .. code-block:: xml
 46 | 
 47 |     <lv_label style_bg_opa="200" style_bg_opa:disabled="100"/>
 48 | 
 49 | 
 50 | 
 51 | Gradients
 52 | *********
 53 | 
 54 | Before the ``<styles>`` tag, the ``<gradients>`` tag can be used to describe various
 55 | gradients, which can later be referenced in styles.
 56 | 
 57 | When a gradient is created, it can be referenced by its name, like:
 58 | 
 59 | .. code-block:: xml
 60 | 
 61 |     <style bg_grad="grad1"/>
 62 | 
 63 | or
 64 | 
 65 | .. code-block:: xml
 66 | 
 67 |     <lv_button style_bg_grad="grad1"/>
 68 | 
 69 | 
 70 | Horizontal or Vertical Gradient
 71 | -------------------------------
 72 | 
 73 | To define a simple ``<horizontal>`` or ``<vertical>`` gradients:
 74 | 
 75 | .. code-block:: xml
 76 | 
 77 |     <gradients>
 78 |         <horizontal name="grad1">
 79 |             <stop color="#ff0000" offset="20%" opa="40%"/>
 80 |             <stop color="#00ff00" offset="128" opa="100%"/>
 81 |         </horizontal>
 82 |     </gradients>
 83 | 
 84 | 
 85 | Linear Gradient
 86 | ---------------
 87 | 
 88 | To define a skewed gradient from two points:
 89 | 
 90 | .. code-block:: xml
 91 | 
 92 |     <gradients>
 93 |         <linear name="grad1" start="50 50" end="100 80">
 94 |             <stop color="#ff0000" offset="20%" opa="100%"/>
 95 |             <stop color="#00ff00" offset="240" opa="100%"/>
 96 |         </linear>
 97 |     </gradients>
 98 | 
 99 | 
100 | Radial Gradient
101 | ---------------
102 | 
103 | To define a radial gradient:
104 | 
105 | .. code-block:: xml
106 | 
107 |     <gradients>
108 |         <radial name="grad1" center="100 50%" edge="200 50" focal_center="50 80%" focal_edge="55 80%">
109 |             <stop color="#ff0000" opa="100%"/>
110 |             <stop color="#00ff00" opa="100%"/>
111 |         </radial>
112 |     </gradients>
113 | 
114 | 
115 | Conical Gradient
116 | ----------------
117 | 
118 | To define a conical gradient:
119 | 
120 | .. code-block:: xml
121 | 
122 |     <gradients>
123 |         <conical name="grad1" center="80 50%" angle="45 270">
124 |             <stop color="#ff0000" opa="100%"/>
125 |             <stop color="#00ff00" opa="100%"/>
126 |         </conical>
127 |     </gradients>
128 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/subjects.rst:
--------------------------------------------------------------------------------
 1 | .. _xml_subjects:
 2 | 
 3 | ========
 4 | Subjects
 5 | ========
 6 | 
 7 | To connect values of the Widget internally or to external data, :ref:`Subjects
 8 | <observer_subject>` can be used. For example, an internally connected value could be
 9 | a slider's value mapped to a label. Externally connected data could be the current
10 | number of users shown on a label.
11 | 
12 | To handle internal connections, local Subjects can be created like this:
13 | 
14 | .. code-block::  xml
15 | 
16 |     <subjects>
17 |         <int name="a" value="20"/>
18 |         <string name="b" value="Hello"/>
19 |         <group name="a_and_b" value="a b"/>
20 |     </subjects>
21 | 
22 | These Subjects can be used in Widget APIs like:
23 | 
24 | .. code-block::  xml
25 | 
26 |     <view>
27 |         <label bind_text="a 'Progress: %d'"/>
28 |     </view>
29 | 
30 | When generating code, the Subjects are saved in the Widget's data and are used like this:
31 | 
32 | .. code-block::  c
33 | 
34 |     lv_subject_init_int(&my_widget->subject_a, 20);
35 |     lv_subject_init_string(&my_widget->subject_b, "Hello");
36 | 
37 |     my_widget->subject_a_and_b_list = lv_malloc(sizeof(lv_subject_t *) * 2);
38 |     my_widget->subject_a_and_b_list[0] = &my_widget->subject_a;
39 |     my_widget->subject_a_and_b_list[1] = &my_widget->subject_b;
40 |     lv_subject_init_group(&my_widget->subject_a_and_b, my_widget->subject_a_and_b_list);
41 | 
42 | If the connection is more complex and not supported out of the box, it can be handled from code.
43 | 
44 | External Subjects are defined in the API of the Widget:
45 | 
46 | .. code-block::  xml
47 | 
48 |     <api>
49 |         <prop name="bind_value" help="">
50 |             <param name="subject" type="subject" help=""/>
51 |             <param name="max_value" type="int" help="Just another parameter, e.g., to limit the value"/>
52 |         </prop>
53 |     </api>
54 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/translations.rst:
--------------------------------------------------------------------------------
1 | .. _xml_translations:
2 | 
3 | ============
4 | Translations
5 | ============
6 | 
7 | TODO
8 | 


--------------------------------------------------------------------------------
/docs/src/details/auxiliary-modules/xml/view.rst:
--------------------------------------------------------------------------------
1 | .. _xml_view:
2 | 
3 | =========
4 | View
5 | =========
6 | 
7 | TODO


--------------------------------------------------------------------------------
/docs/src/details/common-widget-features/index.rst:
--------------------------------------------------------------------------------
 1 | .. _common_widget_features:
 2 | 
 3 | ======================
 4 | Common Widget Features
 5 | ======================
 6 | 
 7 | The following details apply to all types of Widgets.
 8 | 
 9 | .. toctree::
10 |     :maxdepth:  3
11 | 
12 |     basics
13 |     coordinates
14 |     layers
15 |     styles/index
16 |     events
17 |     layouts/index
18 |     scrolling
19 | 


--------------------------------------------------------------------------------
/docs/src/details/common-widget-features/layers.rst:
--------------------------------------------------------------------------------
 1 | .. _layers:
 2 | 
 3 | ======
 4 | Layers
 5 | ======
 6 | 
 7 | When the term "layer" is used in LVGL documentation, it may refer to one of several
 8 | things:
 9 | 
10 | 1.  for Widgets, the :ref:`layers_creation` creates a natural layering of Widgets;
11 | 2.  in the context of pixel rendering (drawing), there are :ref:`draw_layers`;
12 | 3.  permanent :ref:`display_screen_layers` are part of each :ref:`display` object.
13 | 
14 | #1 is covered below.  #2 and #3 are covered in :ref:`draw_layers` and
15 | :ref:`display_screen_layers` respectively.
16 | 
17 | 
18 | 
19 | .. _layers_creation:
20 | 
21 | Order of Creation
22 | *****************
23 | 
24 | By default, LVGL draws new Widgets on top of old Widgets.
25 | 
26 | For example, assume we add a button to a parent Widget named button1 and
27 | then another button named button2. Then button1 (along with its child
28 | Widget(s)) will be in the background and can be covered by button2 and
29 | its children.
30 | 
31 | .. image:: /_static/images/layers.png
32 | 
33 | .. code-block:: c
34 | 
35 |    /* Create a screen */
36 |    lv_obj_t * scr = lv_obj_create(NULL);
37 |    lv_screen_load(scr);          /* Load the screen */
38 | 
39 |    /* Create 2 buttons */
40 |    lv_obj_t * btn1 = lv_button_create(scr);     /* Create the first button on the screen */
41 |    lv_obj_set_pos(btn1, 60, 40);                      /* Set the position of the first button */
42 | 
43 |    lv_obj_t * btn2 = lv_button_create(scr);     /* Create the second button on the screen */
44 |    lv_obj_set_pos(btn2, 180, 80);                     /* Set the position of the second button */
45 | 
46 |    /* Add labels to the buttons */
47 |    lv_obj_t * label1 = lv_label_create(btn1);   /* Create a label on the first button */
48 |    lv_label_set_text(label1, "Button 1");             /* Set the text of the label */
49 | 
50 |    lv_obj_t * label2 = lv_label_create(btn2);   /* Create a label on the second button */
51 |    lv_label_set_text(label2, "Button 2");             /* Set the text of the label */
52 | 
53 |    /* Delete the second label */
54 |    lv_obj_delete(label2);
55 | 
56 | 
57 | .. _layers_order:
58 | 
59 | Changing Order
60 | --------------
61 | 
62 | There are four explicit ways to bring a Widget to the foreground:
63 | 
64 | - Use :cpp:expr:`lv_obj_move_foreground(widget)` to bring a Widget to the foreground.
65 |   Similarly, use :cpp:expr:`lv_obj_move_background(widget)` to move it to the background.
66 | - Use :cpp:expr:`lv_obj_move_to_index(widget, idx)` to move a Widget to a given index in the order of children.
67 | 
68 |   - ``0``: background
69 |   - ``child_num - 1``: foreground
70 |   - ``< 0``: count from the top, to move forward (up): :cpp:expr:`lv_obj_move_to_index(widget, lv_obj_get_index(widget) - 1)`
71 | 
72 | - Use :cpp:expr:`lv_obj_swap(widget1, widget2)` to swap the relative layer position of two Widgets.
73 | - When :cpp:expr:`lv_obj_set_parent(widget, new_parent)` is used, ``widget`` will be on the foreground of ``new_parent``.
74 | 
75 | 
76 | 
77 | 
78 | .. _layers_api:
79 | 
80 | API
81 | ***
82 | 
83 | .. API equals:
84 |     lv_obj_move_foreground
85 |     lv_obj_move_to_index
86 |     lv_obj_swap
87 |     lv_obj_set_parent
88 | 


--------------------------------------------------------------------------------
/docs/src/details/common-widget-features/layouts/index.rst:
--------------------------------------------------------------------------------
 1 | .. _layouts:
 2 | 
 3 | =======
 4 | Layouts
 5 | =======
 6 | 
 7 | 
 8 | .. toctree::
 9 |     :maxdepth: 2
10 | 
11 |     flex
12 |     grid
13 | 


--------------------------------------------------------------------------------
/docs/src/details/common-widget-features/styles/index.rst:
--------------------------------------------------------------------------------
 1 | .. _styles:
 2 | 
 3 | ======
 4 | Styles
 5 | ======
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     styles
11 |     style-properties
12 | 


--------------------------------------------------------------------------------
/docs/src/details/debugging/gdb_plugin.rst:
--------------------------------------------------------------------------------
 1 | .. _gdb_plugin:
 2 | 
 3 | ===========
 4 | GDB Plug-In
 5 | ===========
 6 | 
 7 | Debugging LVGL with GDB
 8 | -----------------------
 9 | 
10 | To facilitate debugging LVGL with GDB, a GDB plugin is provided. This plugin
11 | can be found in the ``lvgl/scripts/gdb`` directory. The GDB plugin can be used
12 | with any target where GDB is available. For example, you can use it to debug a
13 | device connected to a PC via JLink, which provides a GDB server. Additionally,
14 | if your device crashes and you have a core dump, you can use GDB to analyze the
15 | core dump. To load the LVGL GDB plugin within GDB's command line, type the
16 | following command:
17 | 
18 | ``source lvgl/scripts/gdb/gdbinit.py``
19 | 
20 | 
21 | Example of usage:
22 | 
23 | .. code:: bash
24 | 
25 |     (gdb) source lvgl/scripts/gdb/gdbinit.py
26 | 
27 |     (gdb) dump obj -L 2
28 |     obj@0x60700000dd10 (0,0,799,599)
29 |     tabview@0x608000204ca0 (0,0,799,599)
30 |         obj@0x607000025da0 (0,0,799,69)
31 |         obj@0x607000025e80 (0,70,799,599)
32 |         obj@0x60700002bd70 (743,543,791,591)
33 |         btn@0x60700002c7f0 (747,547,787,587)
34 |     keyboard@0x60d0000f7040 (0,300,799,599)
35 |     dropdown-list@0x608000205420 (0,0,129,129)
36 |         label@0x60d0000f7ba0 (22,22,56,39)
37 |     (gdb)
38 | 
39 | The plugin provides the following commands.
40 | 
41 | - ``dump obj``: Dump the object tree.
42 | - ``info style``: Show the object's style.
43 | - ``info draw_unit``: Display all current drawing unit information.
44 | 
45 | 
46 | Dump obj tree
47 | -------------
48 | 
49 | ``dump obj``: Dump the object tree.
50 | 
51 | ``dump obj -L 2``: Dump the object tree with a depth of 2.
52 | 
53 | ``dump obj -a 0x60700000dd10``: Dump the object tree starting from the specified address.
54 | 
55 | 
56 | Show obj's style
57 | ----------------
58 | 
59 | This command can dump the object's local style, since style value is a union, it's displayed in all possible formats.
60 | 
61 | ``info style address_of_obj``: Show the object's style.
62 | 
63 | 
64 | Example:
65 | 
66 | .. code:: bash
67 | 
68 |     (gdb) info style 0x60700000dd10
69 |       32 = {num = 90, ptr = 0x5a, color = {blue = 90 'Z', green = 0 '\000', red = 0 '\000'}}
70 |       158 = {num = 32767, ptr = 0x7fff, color = {blue = 255 '\377', green = 127 '\177', red = 0 '\000'}}
71 |     (gdb) p lv_global->disp_default->act_scr
72 |     $4 = (lv_obj_t *) 0x60700000dd10
73 |     (gdb) info style $4
74 |       32 = {num = 90, ptr = 0x5a, color = {blue = 90 'Z', green = 0 '\000', red = 0 '\000'}}
75 |       158 = {num = 32767, ptr = 0x7fff, color = {blue = 255 '\377', green = 127 '\177', red = 0 '\000'}}
76 |     (gdb)
77 | 
78 | Connect to Debugger
79 | -------------------
80 | 
81 | This command provides the ability to connect and debug GDB Python Script using IDE.
82 | 
83 | Connect to ``PyCharm`` / ``VSCode`` / ``Eclipse(not support yet)``
84 | 
85 | ``debugger -t pycharm``
86 | 
87 | ``debugger -t vscode``
88 | 
89 | ``debugger -t eclipse``
90 | 
91 | How to use it specifically, search ``pydevd_pycharm`` / ``debugpy`` for details.
92 | 


--------------------------------------------------------------------------------
/docs/src/details/debugging/index.rst:
--------------------------------------------------------------------------------
 1 | .. _debugging:
 2 | 
 3 | =========
 4 | Debugging
 5 | =========
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     gdb_plugin
11 |     log
12 |     profiler
13 |     vg_lite_tvg
14 | 


--------------------------------------------------------------------------------
/docs/src/details/debugging/log.rst:
--------------------------------------------------------------------------------
 1 | .. _logging:
 2 | 
 3 | =======
 4 | Logging
 5 | =======
 6 | 
 7 | LVGL has a built-in *Log* module to inform the user about what is
 8 | happening in the library.
 9 | 
10 | 
11 | Log Level
12 | *********
13 | 
14 | To enable logging, set :c:macro:`LV_USE_LOG` in ``lv_conf.h`` and set
15 | :c:macro:`LV_LOG_LEVEL` to one of the following values:
16 | 
17 | - :c:macro:`LV_LOG_LEVEL_TRACE`: A lot of logs to give detailed information
18 | - :c:macro:`LV_LOG_LEVEL_INFO`: Log important events
19 | - :c:macro:`LV_LOG_LEVEL_WARN`: Log if something unwanted happened but didn't cause a problem
20 | - :c:macro:`LV_LOG_LEVEL_ERROR`: Only critical issues, where the system may fail
21 | - :c:macro:`LV_LOG_LEVEL_USER`: Only user messages
22 | - :c:macro:`LV_LOG_LEVEL_NONE`: Do not log anything
23 | 
24 | The events which have a higher level than the set log level will be logged
25 | as well. E.g. if you :c:macro:`LV_LOG_LEVEL_WARN`, errors will be also logged.
26 | 
27 | 
28 | Printing Logs
29 | *************
30 | 
31 | Logging with printf
32 | -------------------
33 | 
34 | If your system supports ``printf``, you just need to enable
35 | :c:macro:`LV_LOG_PRINTF` in ``lv_conf.h`` to send the logs with ``printf``.
36 | 
37 | Custom log function
38 | -------------------
39 | 
40 | If you can't use ``printf`` or want to use a custom function to log, you
41 | can register a "logger" callback with :cpp:func:`lv_log_register_print_cb`.
42 | 
43 | For example:
44 | 
45 | .. code-block:: c
46 | 
47 |    void my_log_cb(lv_log_level_t level, const char * buf)
48 |    {
49 |      serial_send(buf, strlen(buf));
50 |    }
51 | 
52 |    ...
53 | 
54 | 
55 |    lv_log_register_print_cb(my_log_cb);
56 | 
57 | 
58 | Add Logs
59 | ********
60 | 
61 | You can also use the log module via the
62 | ``LV_LOG_TRACE/INFO/WARN/ERROR/USER(text)`` or ``LV_LOG(text)``
63 | functions. Here:
64 | 
65 | -  ``LV_LOG_TRACE/INFO/WARN/ERROR/USER(text)`` append the following information to your ``text``
66 | -  Log Level
67 | -  \__FILE\_\_
68 | -  \__LINE\_\_
69 | -  \__func\_\_
70 | -  ``LV_LOG(text)`` is similar to ``LV_LOG_USER`` but has no extra information attached.
71 | 
72 | API
73 | ***
74 | 


--------------------------------------------------------------------------------
/docs/src/details/debugging/vg_lite_tvg.rst:
--------------------------------------------------------------------------------
 1 | .. _vg_lite_tvg:
 2 | 
 3 | =================
 4 | VG-Lite Simulator
 5 | =================
 6 | 
 7 | LVGL integrates a VG-Lite simulator based on ThorVG.
 8 | Its purpose is to simplify the debugging of VG-Lite adaptation and reduce the time of debugging and locating problems on hardware devices.
 9 | 
10 | It has been integrated into the CI automated compilation and testing process to ensure that the VG-Lite rendering backend can be fully tested after each PR modification.
11 | 
12 | How It Works
13 | ************
14 | 
15 | Sort out the APIs in the ``vg_lite.h`` header file provided by the vendor, re-implement the APIs using `ThorVG <https://github.com/thorvg/thorvg>`_,
16 | and simulate the same rendering images as the real hardware on the simulator.
17 | 
18 | Configuration
19 | *************
20 | 
21 | 1. Enable VG-Lite rendering backend, see :ref:`vg_lite`.
22 | 
23 | 2. Enable ThorVG and turn on the configuration :c:macro:`LV_USE_THORVG_INTERNAL` or :c:macro:`LV_USE_THORVG_EXTERNAL`.
24 |    It is recommended to use the internal ThorVG library to ensure uniform rendering results.
25 | 
26 | 3. Enable :c:macro:`LV_USE_VG_LITE_THORVG` and set :c:macro:`LV_DRAW_BUF_ALIGN` to 64. The rest of the options can remain default.
27 |    Make sure :c:macro:`LV_VG_LITE_USE_GPU_INIT` is enabled, because the thorvg drawing context needs to be initialized before it can be used.
28 | 


--------------------------------------------------------------------------------
/docs/src/details/index.rst:
--------------------------------------------------------------------------------
 1 | .. _reference:
 2 | 
 3 | =======
 4 | Details
 5 | =======
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     ../examples
11 |     integration/index
12 |     common-widget-features/index
13 |     widgets/index
14 |     main-modules/index
15 |     auxiliary-modules/index
16 |     libs/index
17 |     debugging/index
18 |     ../contributing/index
19 |     ../CHANGELOG
20 |     ../API/index
21 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/adding-lvgl-to-your-project/building_lvgl.rst:
--------------------------------------------------------------------------------
 1 | .. _building_lvgl:
 2 | 
 3 | =============
 4 | Building LVGL
 5 | =============
 6 | 
 7 | 
 8 | Make and CMake
 9 | **************
10 | 
11 | LVGL also supports ``make`` and ``CMake`` build systems out of the box.
12 | To add LVGL to your Makefile based build system add these lines to your
13 | main Makefile:
14 | 
15 | .. code-block:: make
16 | 
17 |     LVGL_DIR_NAME ?= lvgl     #The name of the lvgl folder (change this if you have renamed it)
18 |     LVGL_DIR ?= ${shell pwd}  #The path where the lvgl folder is
19 |     include $(LVGL_DIR)/$(LVGL_DIR_NAME)/lvgl.mk
20 | 
21 | For integration with CMake take a look this section of the
22 | :ref:`Documentation <integrating_lvgl_cmake>`.
23 | 
24 | 
25 | Managed builds
26 | **************
27 | TODO
28 | 
29 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/adding-lvgl-to-your-project/getting_lvgl.rst:
--------------------------------------------------------------------------------
 1 | .. _getting_lvgl:
 2 | 
 3 | ============
 4 | Getting LVGL
 5 | ============
 6 | 
 7 | LVGL is available on GitHub: https://github.com/lvgl/lvgl.
 8 | 
 9 | You can clone it or
10 | `Download <https://github.com/lvgl/lvgl/archive/refs/heads/master.zip>`__
11 | the latest version of the library from GitHub.
12 | 
13 | The graphics library itself is the ``lvgl`` directory.  It contains several
14 | directories but to use LVGL you only need the ``.c`` and ``.h`` files under
15 | the ``src`` directory, plus ``lvgl/lvgl.h``, and ``lvgl/lv_version.h``.
16 | 
17 | 
18 | Demos and Examples
19 | ------------------
20 | 
21 | The ``lvgl`` directory also contains an ``examples`` and a ``demos``
22 | directory.  If your project needs examples and/or demos, add the these
23 | directories to your project.  If ``make`` or :ref:`build_cmake` handle the
24 | examples and demos directories, no extra action is required.
25 | 
26 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/adding-lvgl-to-your-project/index.rst:
--------------------------------------------------------------------------------
 1 | .. _adding_lvgl_to_your_project:
 2 | 
 3 | ===========================
 4 | Adding LVGL to Your Project
 5 | ===========================
 6 | 
 7 | 
 8 | .. toctree::
 9 |     :maxdepth: 2
10 | 
11 |     getting_lvgl
12 |     building_lvgl
13 |     configuration
14 |     connecting_lvgl
15 |     timer_handler
16 |     threading
17 |     other_platforms
18 | 
19 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/adding-lvgl-to-your-project/other_platforms.rst:
--------------------------------------------------------------------------------
 1 | .. _other_platforms:
 2 | 
 3 | =========================
 4 | Other Platforms and Tools
 5 | =========================
 6 | 
 7 | See :ref:`Integration <integration_index>` to see how to use LVGL on different
 8 | platforms.  There, you will find many platform-specific descriptions e.g. for ESP32,
 9 | Arduino, NXP, RT-Thread, NuttX, etc.
10 | 
11 | 
12 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/bindings/cpp.rst:
--------------------------------------------------------------------------------
1 | ===
2 | Cpp
3 | ===
4 | 
5 | In progress: https://github.com/lvgl/lv_binding_cpp
6 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/bindings/index.rst:
--------------------------------------------------------------------------------
 1 | ========
 2 | Bindings
 3 | ========
 4 | 
 5 | 
 6 | .. toctree::
 7 |    :maxdepth: 2
 8 | 
 9 |    api_json
10 |    cpp
11 |    javascript
12 |    micropython
13 |    pikascript
14 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/boards/index.rst:
--------------------------------------------------------------------------------
 1 | ======
 2 | Boards
 3 | ======
 4 | 
 5 | .. toctree::
 6 |     :maxdepth: 2
 7 | 
 8 |     toradex
 9 |     riverdi
10 |     viewe
11 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/boards/riverdi.rst:
--------------------------------------------------------------------------------
 1 | =======
 2 | Riverdi
 3 | =======
 4 | 
 5 | `Riverdi <https://riverdi.com/>`__ specializes in making high quality
 6 | displays and the boards that carry them. They offer solutions that
 7 | range from simple display panels to intelligent displays, and
 8 | everything in between.
 9 | 
10 | - STM32 Embedded Displays
11 | - Single Board Computer Displays
12 | - EVE Intelligent Displays
13 | - HDMI Displays
14 | - Evaluation Boards
15 | - RGB, LVDS, MIPI DSI LCD Displays
16 | 
17 | 
18 | STM32 Embedded Displays
19 | ***********************
20 | 
21 | The STM32 Embedded Displays have an STM32 MCU onboard which makes
22 | it possible to embed an entire application into the device. LVGL
23 | is well-suited to these boards.
24 | 
25 | lv_port_riverdi_stm32u5
26 | -----------------------
27 | 
28 | `lv_port_riverdi_stm32u5 <https://github.com/lvgl/lv_port_riverdi_stm32u5>`_
29 | is a port repo of LVGL which supports all 5-inch Riverdi STM32
30 | Embedded Displays.
31 | 
32 | - `RVT50HQSNWC00-B <https://riverdi.com/product/5-inch-lcd-display-capacitive-touch-panel-optical-bonding-uxtouch-stm32u5-rvt50hqsnwc00-b>`_
33 | - `RVT50HQSNWC00 <https://riverdi.com/product/5-inch-lcd-display-capacitive-touch-panel-air-bonding-uxtouch-stm32u5-rvt50hqsnwc00>`_
34 | - `RVT50HQSFWCA0 <https://riverdi.com/product/5-inch-lcd-display-capacitive-touch-panel-air-bonding-atouch-frame-stm32u5-rvt50hqsfwca0>`_
35 | - `RVT50HQSNWCA0 <https://riverdi.com/product/5-inch-lcd-display-capacitive-touch-panel-air-bonding-atouch-stm32u5-rvt50hqsnwca0>`_
36 | - `RVT50HQSFWN00 <https://riverdi.com/product/5-inch-lcd-display-stm32u5-frame-rvt50hqsfwn00>`_
37 | - `RVT50HQSNWN00 <https://riverdi.com/product/5-inch-lcd-display-stm32u5-rvt50hqsnwn00>`_
38 | 
39 | It natively supports the embedded NeoChrom GPU thanks to LVGL's support
40 | for :ref:`Nema GFX <nema_gfx>`. NemaVG --- an extension to Nema's
41 | base support --- is implemented by this MCU.
42 | 
43 | The MCU has an LCD driver peripheral which LVGL uses to update the
44 | display. See the :ref:`LTDC <stm32 ltdc driver>` driver docs
45 | for more info and how to customize its use.
46 | 
47 | 
48 | Single-Board Computer Displays
49 | ******************************
50 | 
51 | The Single-Board Computer Displays are ready to use with
52 | :ref:`Toradex <toradex>` Dahlia and Mallow carrier boards. In fact,
53 | those carrier boards are compatible with all 34-pin Riverdi
54 | MIPI-DSI displays.
55 | 
56 | 
57 | Other Products
58 | **************
59 | 
60 | The **EVE Intelligent Displays** feature a Bridgetek EVE graphics
61 | controller IC so that the display can be controlled using
62 | high-level drawing commands over a lower-bandwidth interface than
63 | RGB, MIPI, etc.
64 | 
65 | The **HDMI Displays** sport an HDMI interface for streamlined
66 | integration with PCs or SBCs. These displays are still low-profile
67 | so they can be embedded into custom fixtures with ease.
68 | 
69 | The **Evaluation Boards** are affordable carrier boards for getting
70 | Riverdi display panels up and running before designing or buying a
71 | carrier board for a production application.
72 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/boards/viewe.rst:
--------------------------------------------------------------------------------
 1 | =====
 2 | Viewe
 3 | =====
 4 | 
 5 | `Viewe <https://viewedisplay.com/>`__ specializes in comprehensive display solutions 
 6 | for more than 10 Years with remarkable capability of software and hardware R&D, 
 7 | factory manufacturing and sales service. We not only offer one stop 
 8 | `bare display and touch solutions <https://viewedisplay.com/display-solutions/>`_ 
 9 | but also `embedded smart displays <https://viewedisplay.com/smart-solutions/>`_ 
10 | with standard productions and tailored customization to develop your concepts 
11 | to reality.
12 | 
13 | Products Portfolio:
14 | *******************
15 | 
16 | - Embedded Smart Displays
17 |     - `IOT_AIOT Smart Display <https://viewedisplay.com/iot_aiot-smart-display/>`_
18 |     - `Uart Smart Display <https://viewedisplay.com/uart-smart-display/>`_
19 |     - `HDMI Display_Raspberry Pi Display <https://viewedisplay.com/hdmi-display-raspberry-pi-display/>`_
20 |     - Arduino Display
21 | 
22 | TFT | OLED Display
23 | 
24 |     - `Sunlight Readable Display <https://viewedisplay.com/sunlight-readable-display/>`_
25 |     - `AMOLED Displays <https://viewedisplay.com/amoled-display-list/>`_
26 |     - `Transflective TFT Displays <https://viewedisplay.com/transflective-tft-display/>`_
27 |     - `Standard TFT Displays <https://viewedisplay.com/standard-display/>`_
28 |     - `Bar Display/Stretched TFT Display <https://viewedisplay.com/bar-display-stretched-display/>`_
29 |     - `Square TFT Display <https://viewedisplay.com/square-display/>`_
30 |     - `Round TFT Display <https://viewedisplay.com/round-display/>`_
31 | 
32 | 
33 | IOT AIOT Smart Displays
34 | ***********************
35 | 
36 | The Viewe IOT AIOT Smart Displays are a series of displays that use ESP32
37 | microcontrollers with integrated multi-modal interactions of GUI /voice/camera, ML/AI
38 | edge computing, and seamless connectivity. UART/RS232/RS485/CAN Interfaces and
39 | redundant IO interfaces are included to facilitate extended usage. LVGL/Arduino/ESP-IDF 
40 | is well-suited to these boards.
41 | 
42 | lv_port_viewe_7_espidf
43 | ----------------------
44 | 
45 | `lv_port_viewe_7_espidf <https://github.com/lvgl/lv_port_viewe_7_espidf>`_
46 | is a port repo of LVGL which supports Viewe ESP32 S3 Smart Display 7.0 inch. 
47 | It is based on ESP-IDF and uses the ESP32-S3 microcontroller.
48 | 
49 | - `Viewe ESP32 S3 Smart Display <https://viewedisplay.com/product/esp32-7-inch-800x480-rgb-ips-tft-display-touch-screen-arduino-lvgl-uart/>`_
50 | 
51 | UART Smart Displays
52 | *******************
53 | 
54 | The Viewe UART Smart Displays are a series of displays that use ESP32 and STM32
55 | microcontrollers with UART/RS232/RS485/CAN Interface and have IO interface for
56 | connecting to peripherals. LVGL is well-suited to these boards.
57 | 
58 | lv_port_viewe_7_espidf
59 | ----------------------
60 | 
61 | `lv_port_viewe_7_espidf <https://github.com/lvgl/lv_port_viewe_7_espidf>`_
62 | is a port repo of LVGL which supports Viewe ESP32 S3 Smart Display 7.0 inch. 
63 | It is based on ESP-IDF and uses the ESP32-S3 microcontroller.
64 | 
65 | - `Viewe ESP32 S3 Smart Display <https://viewedisplay.com/product/esp32-7-inch-800x480-rgb-ips-tft-display-touch-screen-arduino-lvgl-uart/>`_
66 | 
67 | 
68 | 
69 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/building/index.rst:
--------------------------------------------------------------------------------
 1 | =============
 2 | Build Systems
 3 | =============
 4 | 
 5 | 
 6 | .. toctree::
 7 |    :maxdepth: 2
 8 | 
 9 |    make
10 |    cmake
11 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/building/make.rst:
--------------------------------------------------------------------------------
1 | .. _build_make:
2 | 
3 | ====
4 | make
5 | ====
6 | 
7 | LVGL can be easily integrated into any Makefile project by adding ``include lvgl/lvgl.mk`` to the main ``Makefile``.
8 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/chip/index.rst:
--------------------------------------------------------------------------------
 1 | ============
 2 | Chip vendors
 3 | ============
 4 | 
 5 | .. toctree::
 6 |     :maxdepth: 2
 7 | 
 8 |     alif
 9 |     arm
10 |     espressif
11 |     nxp
12 |     renesas/index
13 |     stm32
14 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/chip/renesas/built_in_drivers.rst:
--------------------------------------------------------------------------------
 1 | ================
 2 | Built-in Drivers
 3 | ================
 4 | 
 5 | `Renesas <https://renesas.com/>`__ is an official partner of LVGL. Therefore, LVGL contains built-in support for
 6 | `Dave2D <https://www.renesas.com/document/mas/tes-dave2d-driver-documentation>`__ (the GPU of Renesas) and we also maintain
 7 | ready-to-use Renesas projects.
 8 | 
 9 | 
10 | Dave2D
11 | ******
12 | 
13 | Dave2D is capable of accelerating most of the drawing operations of LVGL:
14 | 
15 | - Rectangle drawing, even with gradients
16 | - Image drawing, scaling, and rotation
17 | - Letter drawing
18 | - Triangle drawing
19 | - Line drawing
20 | 
21 | 
22 | As Dave2D works in the background, the CPU is free for other tasks. In practice, during rendering, Dave2D can reduce the CPU usage by
23 | half or to one-third, depending on the application.
24 | 
25 | 
26 | GLCDC
27 | *****
28 | 
29 | GLCDC is a multi-stage graphics output peripheral available in several Renesas MCUs. It is able to drive LCD panels via a highly
30 | configurable RGB interface.
31 | 
32 | More info can be found at the :ref:`driver's page<renesas_glcdc>`.
33 | 
34 | 
35 | MPU Drivers
36 | ***********
37 | 
38 | Renesas MPUs (i.e., the RZ/G family) can use LVGL MPU drivers.
39 | 
40 | Wayland
41 | -------
42 | 
43 | Supported on boards with a Wayland desktop AKA a Wayland compositor.
44 | 
45 | fbdev
46 | -----
47 | 
48 | Almost always available.
49 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/chip/renesas/index.rst:
--------------------------------------------------------------------------------
 1 | .. _renesas:
 2 | 
 3 | =======
 4 | Renesas
 5 | =======
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     built_in_drivers
11 |     ra_family
12 |     rx_family
13 |     rzg_family
14 |     rza_family
15 |     supported_boards
16 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/chip/renesas/ra_family.rst:
--------------------------------------------------------------------------------
 1 | =========
 2 | RA Family
 3 | =========
 4 | 
 5 | .. |sup2|   unicode:: U+000B2 .. SUPERSCRIPT TWO
 6 | 
 7 | .. |img_debug_btn| image:: /_static/images/renesas/debug_btn.png
 8 |    :alt: Debug button
 9 | 
10 | Supported boards in the RA Family:
11 | 
12 | - **EK-RA8D1**
13 | - **EK-RA6M3G**
14 | 
15 | Run the Project
16 | ***************
17 | 
18 | - The official IDE of Renesas is called e\ |sup2| studio. As it's Eclipse-based, it runs on Windows, Linux, and Mac as well.
19 |   The RA family requires the latest version with FSP 5.3. It can be downloaded `here <https://www.renesas.com/us/en/software-tool/flexible-software-package-fsp>`__.
20 | - JLink is used for debugging, it can be downloaded `here <https://www.segger.com/downloads/jlink/>`__.
21 | - Clone the ready-to-use repository for your selected board:
22 | 
23 |     .. code-block:: shell
24 | 
25 |         git clone https://github.com/lvgl/lv_port_renesas_ek-ra8d1.git --recurse-submodules
26 | 
27 | 
28 |   Downloading the `.zip` from GitHub doesn't work as it doesn't download the submodules.
29 | - Open e\ |sup2| studio, go to ``File`` -> ``Import project`` and select ``General`` / ``Existing projects into workspace``
30 | - Browse the cloned folder and press ``Finish``.
31 | - Double click on ``configuration.xml``. This will activate the `Configuration Window`.
32 | 
33 |   Renesas' Flexible Software Package (FSP) includes BSP and HAL layer support extended with multiple RTOS variants and other middleware stacks.
34 |   The components will be available via code generation, including the entry point of *"main.c"*.
35 | 
36 |   Press ``Generate Project Content`` in the top right corner.
37 | 
38 |   .. image:: /_static/images/renesas/generate.png
39 |      :alt: Code generation with FSP
40 | 
41 | - Build the project by pressing ``Ctrl`` + ``Alt`` + ``B``
42 | - Click the Debug button (|img_debug_btn|). If prompted with `Debug Configurations`, on the `Debugger` tab select the ``J-Link ARM`` as `Debug hardware` and the proper IC as `Target Device`:
43 | 
44 |   - ``R7FA8D1BH`` for EK-RA8D1
45 | 
46 |     .. image:: /_static/images/renesas/debug_ra8.png
47 |        :alt: Debugger parameters for RA8
48 | 
49 |   - ``R7FA6M3AH`` for EK-RA6M3G
50 | 
51 |     .. image:: /_static/images/renesas/debug_ra6.png
52 |        :alt: Debugger parameters for RA6
53 | 
54 | .. note::
55 |    On EK-RA8D1 boards, the ``SW1`` DIP switch (middle of the board) 7 should be ON, all others are OFF.
56 | 
57 | 
58 | Modify the project
59 | ******************
60 | 
61 | 
62 | Open a demo
63 | -----------
64 | 
65 | The entry point of the main task is contained in ``src/LVGL_thread_entry.c``.
66 | 
67 | You can disable the LVGL demos (or just comment them out) and call some ``lv_example_...()`` functions, or add your custom code.
68 | 
69 | 
70 | Configuration
71 | -------------
72 | 
73 | ``src/lv_conf.h`` contains the most important settings for LVGL. Namely:
74 | 
75 | - :c:macro:`LV_COLOR_DEPTH` to set LVGL's default color depth
76 | - :c:macro:`LV_MEM_SIZE` to set the maximum RAM available for LVGL
77 | - :c:macro:`LV_USE_DAVE2D` to enable the GPU
78 | 
79 | 
80 | Hardware and software components can be modified in a visual way using the `Configuration Window`.
81 | 
82 | 
83 | Support
84 | *******
85 | 
86 | In case of any problems or questions open an issue in the corresponding repository.
87 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/chip/renesas/rza_family.rst:
--------------------------------------------------------------------------------
 1 | ===========
 2 | RZ/A Family
 3 | ===========
 4 | 
 5 | Supported boards in the RZ/A Family:
 6 | 
 7 | - **RZ/A3M**
 8 | 
 9 | Run the Project
10 | ***************
11 | 
12 | - The RZ/A boards are MPUs with a focus on baremetal and RTOS applications. Projects are built for them using e2 Studio IDE, available for Windows, Mac, and Linux.
13 | - Clone the ready-to-use repository for your board:
14 | 
15 |     .. code-block:: shell
16 | 
17 |         git clone https://github.com/lvgl/lv_port_renesas-ek-rz_a3m --recurse-submodules
18 | 
19 | 
20 |   Downloading the `.zip` from GitHub doesn't work as it doesn't download the submodules.
21 | - Follow the instructions in the project README.md to
22 |   build and flash the project to the board.
23 | 
24 | Modify the project
25 | ******************
26 | 
27 | 
28 | Open a demo
29 | -----------
30 | 
31 | The entry point is contained in ``src/LVGL_thread_entry.c``.
32 | 
33 | You can disable the LVGL demos (``lv_demo_benchmark()``) (or just comment them out)
34 | and call some ``lv_example_...()`` functions, or add your custom code.
35 | 
36 | 
37 | Configuration
38 | -------------
39 | 
40 | Edit ``lv_conf.h`` to configure LVGL.
41 | 
42 | It will automatically run any demo that is enabled in ``lv_conf.h``. You can see ``lv_conf.defaults`` for a summary of the configs which have been changed from the defaults.
43 | 
44 | 
45 | Support
46 | *******
47 | 
48 | In case of any problems or questions open an issue in the corresponding repository.
49 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/chip/renesas/rzg_family.rst:
--------------------------------------------------------------------------------
 1 | ===========
 2 | RZ/G Family
 3 | ===========
 4 | 
 5 | Supported boards in the RZ/G Family:
 6 | 
 7 | - **RZ/G2L-EVKIT**
 8 | - **RZ/G2UL-EVKIT**
 9 | 
10 | Run the Project
11 | ***************
12 | 
13 | - The RZ/G boards are MPUs with support for running Linux. Projects are built for them using a cross-compiler
14 |   CLI toolchain SDK in a Linux PC environment (WSL, Docker, etc. can be used on Windows).
15 | - The G2L has a Wayland desktop and the project appears as a Wayland window. The G2UL does not have
16 |   a desktop so the project is fullscreen and uses the ``fbdev`` driver.
17 | - The SDK currently uses LVGL v8.3 so this project uses this version to mirror the SDK version,
18 |   even though LVGL is statically linked. You may try using newer versions of LVGL.
19 | - Clone the ready-to-use repository for your selected board:
20 | 
21 |     .. code-block:: shell
22 | 
23 |         git clone https://github.com/lvgl/lv_port_renesas_rz-g2l-evkit --recurse-submodules
24 | 
25 | 
26 |   Downloading the `.zip` from GitHub doesn't work as it doesn't download the submodules.
27 | - Follow the instructions in the project README.md to obtain the SD Card image and toolchain installer,
28 |   build, and upload the project to the board.
29 | - Stop any automatically started demos (on G2UL run ``systemctl stop demo-launcher`` in the terminal).
30 | - Run the project
31 | 
32 |     .. code-block:: shell
33 | 
34 |         ./lvgl_demo_benchmark
35 | 
36 | 
37 | Modify the project
38 | ******************
39 | 
40 | 
41 | Open a demo
42 | -----------
43 | 
44 | The entry point is contained in ``src/main.c``.
45 | 
46 | You can disable the LVGL demos (``lv_demo_benchmark()``) (or just comment them out)
47 | and call some ``lv_example_...()`` functions, or add your custom code.
48 | 
49 | 
50 | Configuration
51 | -------------
52 | 
53 | Edit ``lv_conf.h`` and ``lv_drv_conf.h`` to configure LVGL. The board image
54 | contains LVGL and lv_drivers as dynamically linkable libraries. This project builds LVGL statically
55 | for customizability and to port the LVGL v9 benchmark LVGL v8.3.
56 | 
57 | 
58 | Support
59 | *******
60 | 
61 | In case of any problems or questions open an issue in the corresponding repository.
62 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/display/fbdev.rst:
--------------------------------------------------------------------------------
 1 | ========================
 2 | Linux Framebuffer Driver
 3 | ========================
 4 | 
 5 | Overview
 6 | --------
 7 | 
 8 | The Linux framebuffer (fbdev) is a linux subsystem used to display graphics. It is a hardware-independent API that gives user space software
 9 | access to the framebuffer (the part of a computer's video memory containing a current video frame) using only the Linux kernel's own basic
10 | facilities and its device file system interface, avoiding the need for libraries that implement video drivers in user space. 
11 | 
12 | Prerequisites
13 | -------------
14 | 
15 | Your system has a framebuffer device configured (usually under ``/dev/fb0``).
16 | 
17 | Configuring the driver
18 | ----------------------
19 | 
20 | Enable the framebuffer driver support in lv_conf.h, by cmake compiler define or by KConfig. Additionally you may configure the rendering
21 | mode.
22 | 
23 | .. code-block:: c
24 | 
25 | 	#define LV_USE_LINUX_FBDEV           1
26 | 	#define LV_LINUX_FBDEV_RENDER_MODE   LV_DISPLAY_RENDER_MODE_PARTIAL
27 | 
28 | Usage
29 | -----
30 | 
31 | To set up a framebuffer-based display, first create a display with ``lv_linux_fbdev_create``. Afterwards set the framebuffer device
32 | node on the display (usually this is ``/dev/fb0``).
33 | 
34 | .. code-block:: c
35 | 
36 | 	lv_display_t *disp = lv_linux_fbdev_create();
37 | 	lv_linux_fbdev_set_file(disp, "/dev/fb0");
38 | 
39 | If your screen stays black or only draws partially, you can try enabling direct rendering via ``LV_DISPLAY_RENDER_MODE_DIRECT``. Additionally,
40 | you can activate a force refresh mode with ``lv_linux_fbdev_set_force_refresh(true)``. This usually has a performance impact though and shouldn't
41 | be enabled unless really needed.
42 | 
43 | Hide the cursor
44 | ---------------
45 | 
46 | You may encounter a blinking cursor on the screen. The method to hide it 
47 | varies depending on the platform. For instance, here is how it can be done 
48 | on a Raspberry Pi:
49 | 
50 |   1. Edit ``/boot/cmdline.txt`` file.
51 |   2. Add ``vt.global_cursor_default=0``.
52 | 
53 | Common mistakes
54 | ---------------
55 | 
56 | Default resolution issue
57 | ^^^^^^^^^^^^^^^^^^^^^^^^
58 | 
59 | When the Linux kernel initializes, it sets up subsystems like the framebuffer 
60 | (fbdev) to manage display output. If an HDMI display is connected, the kernel 
61 | detects it and allocates a portion of RAM as the framebuffer, which holds the 
62 | pixel data for rendering images.
63 | 
64 | However, a common issue arises when the display is not powered on during the 
65 | boot process. If the board is powered on before the screen, the kernel may 
66 | incorrectly configure the framebuffer resolution. As a result, both the visible 
67 | and virtual resolutions can be incorrect, leading to display problems.
68 | 
69 | This issue often occurs with HDMI connections where the display is powered up 
70 | after the system has already booted.
71 | 
72 | The following command outputs the current settings of the specified framebuffer 
73 | device, such as resolution, pixel depth, and timings.
74 | 
75 | .. code-block::	
76 | 	
77 | 	fbset -fb /dev/fb0 
78 | 
79 | To prevent display-related issues, it is recommended to ensure all devices, 
80 | including the HDMI display, are connected and powered on before powering up 
81 | the board.
82 | 
83 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/display/ili9341.rst:
--------------------------------------------------------------------------------
 1 | =============================
 2 | ILI9341 LCD Controller driver
 3 | =============================
 4 | 
 5 | Overview
 6 | --------
 7 | 
 8 | The `ILI9341 <https://www.buydisplay.com/download/ic/ILI9341.pdf>`__ is a 262,144-color single-chip SOC driver for a-TFT liquid crystal display with resolution of 240RGBx320
 9 | dots, comprising a 720-channel source driver, a 320-channel gate driver, 172,800 bytes GRAM for graphic
10 | display data of 240RGBx320 dots, and power supply circuit.
11 | ILI9341 supports parallel 8-/9-/16-/18-bit data bus MCU interface, 6-/16-/18-bit data bus RGB interface and
12 | 3-/4-line serial peripheral interface (SPI).
13 | 
14 | The ILI9341 LCD controller `driver <https://github.com/lvgl/lvgl/src/drivers/display/ili9341>`__ is a platform-agnostic driver, based on the `generic MIPI driver <https://github.com/lvgl/lvgl/doc/integration/drivers/display/gen_mipi.rst>`__.
15 | It implements display initialization, supports display rotation and implements the display flush callback. The user needs to implement only two platform-specific functions to send
16 | a command or pixel data to the controller via SPI or parallel bus. Typically these are implemented by calling the appropriate SDK library functions on the given platform.
17 | 
18 | Prerequisites
19 | -------------
20 | 
21 | There are no prerequisites.
22 | 
23 | Configuring the driver
24 | ----------------------
25 | 
26 | Enable the ILI9341 driver support in lv_conf.h, by cmake compiler define or by KConfig
27 | 
28 | .. code-block:: c
29 | 
30 | 	#define LV_USE_ILI9341  1
31 | 
32 | Usage
33 | -----
34 | 
35 | You need to implement two platform-dependent functions:
36 | 
37 | .. code-block:: c
38 | 
39 | 	/* Send short command to the LCD. This function shall wait until the transaction finishes. */
40 | 	int32_t my_lcd_send_cmd(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, const uint8_t *param, size_t param_size)
41 | 	{
42 | 		...
43 | 	}
44 | 
45 | 	/* Send large array of pixel data to the LCD. If necessary, this function has to do the byte-swapping. This function can do the transfer in the background. */
46 | 	int32_t my_lcd_send_color(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, uint8_t *param, size_t param_size)
47 | 	{
48 | 		...
49 | 	}
50 | 
51 | To create an ILI9341-based display use the function
52 | 
53 | .. code-block:: c
54 | 
55 | 	/**
56 | 	 * Create an LCD display with ILI9341 driver
57 | 	 * @param hor_res       horizontal resolution
58 | 	 * @param ver_res       vertical resolution
59 | 	 * @param flags         default configuration settings (mirror, RGB ordering, etc.)
60 | 	 * @param send_cmd      platform-dependent function to send a command to the LCD controller (usually uses polling transfer)
61 | 	 * @param send_color    platform-dependent function to send pixel data to the LCD controller (usually uses DMA transfer: must implement a 'ready' callback)
62 | 	 * @return              pointer to the created display
63 | 	 */
64 | 	lv_display_t * lv_ili9341_create(uint32_t hor_res, uint32_t ver_res, lv_lcd_flag_t flags,
65 | 									lv_ili9341_send_cmd_cb_t send_cmd_cb, lv_ili9341_send_color_cb_t send_color_cb);
66 | 
67 | 
68 | For additional details and a working example see the `generic MIPI driver documentation <https://github.com/lvgl/lvgl/doc/integration/drivers/display/gen_mipi.rst>`__.
69 | 
70 | .. note::
71 | 
72 | 	You can find a step-by-step guide and the actual implementation of the callbacks on an STM32F746 using STM32CubeIDE and the ST HAL libraries here: :ref:`lcd_stm32_guide`
73 | 	
74 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/display/index.rst:
--------------------------------------------------------------------------------
 1 | =======
 2 | Display
 3 | =======
 4 | 
 5 | .. toctree::
 6 |     :maxdepth: 2
 7 | 
 8 |     fbdev
 9 |     ft81x
10 |     gen_mipi
11 |     ili9341
12 |     lcd_stm32_guide
13 |     renesas_glcdc
14 |     st_ltdc
15 |     st7735
16 |     st7789
17 |     st7796
18 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/display/st7735.rst:
--------------------------------------------------------------------------------
 1 | ============================
 2 | ST7735 LCD Controller driver
 3 | ============================
 4 | 
 5 | Overview
 6 | --------
 7 | 
 8 | The `ST7735S <https://www.buydisplay.com/download/ic/ST7735S.pdf>`__ is a single-chip controller/driver for 262K-color, graphic type TFT-LCD. It consists of 396
 9 | source line and 162 gate line driving circuits. This chip is capable of connecting directly to an external
10 | microprocessor, and accepts Serial Peripheral Interface (SPI), 8-bit/9-bit/16-bit/18-bit parallel interface.
11 | Display data can be stored in the on-chip display data RAM of 132 x 162 x 18 bits. It can perform display data
12 | RAM read/write operation with no external operation clock to minimize power consumption. In addition,
13 | because of the integrated power supply circuits necessary to drive liquid crystal, it is possible to make a
14 | display system with fewer components.
15 | 
16 | The ST7735 LCD controller `driver <https://github.com/lvgl/lvgl/src/drivers/display/st7735>`__ is a platform-agnostic driver, based on the `generic MIPI driver <https://github.com/lvgl/lvgl/doc/integration/drivers/display/gen_mipi.rst>`__.
17 | It implements display initialization, supports display rotation and implements the display flush callback. The user needs to implement only two platform-specific functions to send
18 | a command or pixel data to the controller via SPI or parallel bus. Typically these are implemented by calling the appropriate SDK library functions on the given platform.
19 | 
20 | Prerequisites
21 | -------------
22 | 
23 | There are no prerequisites.
24 | 
25 | Configuring the driver
26 | ----------------------
27 | 
28 | Enable the ST7735 driver support in lv_conf.h, by cmake compiler define or by KConfig
29 | 
30 | .. code-block:: c
31 | 
32 | 	#define LV_USE_ST7735  1
33 | 
34 | Usage
35 | -----
36 | 
37 | You need to implement two platform-dependent functions:
38 | 
39 | .. code-block:: c
40 | 
41 | 	/* Send short command to the LCD. This function shall wait until the transaction finishes. */
42 | 	int32_t my_lcd_send_cmd(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, const uint8_t *param, size_t param_size)
43 | 	{
44 | 		...
45 | 	}
46 | 
47 | 	/* Send large array of pixel data to the LCD. If necessary, this function has to do the byte-swapping. This function can do the transfer in the background. */
48 | 	int32_t my_lcd_send_color(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, uint8_t *param, size_t param_size)
49 | 	{
50 | 		...
51 | 	}
52 | 
53 | To create an ST7735-based display use the function
54 | 
55 | .. code-block:: c
56 | 
57 | 	/**
58 | 	 * Create an LCD display with ST7735 driver
59 | 	 * @param hor_res       horizontal resolution
60 | 	 * @param ver_res       vertical resolution
61 | 	 * @param flags         default configuration settings (mirror, RGB ordering, etc.)
62 | 	 * @param send_cmd      platform-dependent function to send a command to the LCD controller (usually uses polling transfer)
63 | 	 * @param send_color    platform-dependent function to send pixel data to the LCD controller (usually uses DMA transfer: must implement a 'ready' callback)
64 | 	 * @return              pointer to the created display
65 | 	 */
66 | 	lv_display_t * lv_st7735_create(uint32_t hor_res, uint32_t ver_res, lv_lcd_flag_t flags,
67 | 									lv_st7735_send_cmd_cb_t send_cmd_cb, lv_st7735_send_color_cb_t send_color_cb);
68 | 
69 | 
70 | For additional details and a working example see the `generic MIPI driver documentation <https://github.com/lvgl/lvgl/doc/integration/drivers/display/gen_mipi.rst>`__.
71 | 
72 | .. note::
73 | 
74 | 	You can find a step-by-step guide and the actual implementation of the callbacks on an STM32F746 using STM32CubeIDE and the ST HAL libraries here: :ref:`lcd_stm32_guide`
75 | 	
76 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/display/st7789.rst:
--------------------------------------------------------------------------------
 1 | ============================
 2 | ST7789 LCD Controller driver
 3 | ============================
 4 | 
 5 | Overview
 6 | --------
 7 | 
 8 | The `ST7789 <https://www.buydisplay.com/download/ic/ST7789.pdf>`__ is a single-chip controller/driver for 262K-color, graphic type TFT-LCD. It consists of 720
 9 | source line and 320 gate line driving circuits. This chip is capable of connecting directly to an external
10 | microprocessor, and accepts, 8-bits/9-bits/16-bits/18-bits parallel interface. Display data can be stored in the
11 | on-chip display data RAM of 240x320x18 bits. It can perform display data RAM read/write operation with no
12 | external operation clock to minimize power consumption. In addition, because of the integrated power supply
13 | circuit necessary to drive liquid crystal; it is possible to make a display system with the fewest components.
14 | 
15 | The ST7789 LCD controller `driver <https://github.com/lvgl/lvgl/src/drivers/display/st7789>`__ is a platform-agnostic driver, based on the `generic MIPI driver <https://github.com/lvgl/lvgl/doc/integration/drivers/display/gen_mipi.rst>`__.
16 | It implements display initialization, supports display rotation and implements the display flush callback. The user needs to implement only two platform-specific functions to send
17 | a command or pixel data to the controller via SPI or parallel bus. Typically these are implemented by calling the appropriate SDK library functions on the given platform.
18 | 
19 | Prerequisites
20 | -------------
21 | 
22 | There are no prerequisites.
23 | 
24 | Configuring the driver
25 | ----------------------
26 | 
27 | Enable the ST7789 driver support in lv_conf.h, by cmake compiler define or by KConfig
28 | 
29 | .. code-block:: c
30 | 
31 | 	#define LV_USE_ST7789  1
32 | 
33 | Usage
34 | -----
35 | 
36 | You need to implement two platform-dependent functions:
37 | 
38 | .. code-block:: c
39 | 
40 | 	/* Send short command to the LCD. This function shall wait until the transaction finishes. */
41 | 	int32_t my_lcd_send_cmd(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, const uint8_t *param, size_t param_size)
42 | 	{
43 | 		...
44 | 	}
45 | 
46 | 	/* Send large array of pixel data to the LCD. If necessary, this function has to do the byte-swapping. This function can do the transfer in the background. */
47 | 	int32_t my_lcd_send_color(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, uint8_t *param, size_t param_size)
48 | 	{
49 | 		...
50 | 	}
51 | 
52 | To create an ST7789-based display use the function
53 | 
54 | .. code-block:: c
55 | 
56 | 	/**
57 | 	 * Create an LCD display with ST7789 driver
58 | 	 * @param hor_res       horizontal resolution
59 | 	 * @param ver_res       vertical resolution
60 | 	 * @param flags         default configuration settings (mirror, RGB ordering, etc.)
61 | 	 * @param send_cmd      platform-dependent function to send a command to the LCD controller (usually uses polling transfer)
62 | 	 * @param send_color    platform-dependent function to send pixel data to the LCD controller (usually uses DMA transfer: must implement a 'ready' callback)
63 | 	 * @return              pointer to the created display
64 | 	 */
65 | 	lv_display_t * lv_st7789_create(uint32_t hor_res, uint32_t ver_res, lv_lcd_flag_t flags,
66 | 									lv_st7789_send_cmd_cb_t send_cmd_cb, lv_st7789_send_color_cb_t send_color_cb);
67 | 
68 | 
69 | For additional details and a working example see the `generic MIPI driver documentation <https://github.com/lvgl/lvgl/doc/integration/drivers/display/gen_mipi.rst>`__.
70 | 
71 | .. note::
72 | 
73 | 	You can find a step-by-step guide and the actual implementation of the callbacks on an STM32F746 using STM32CubeIDE and the ST HAL libraries here: :ref:`lcd_stm32_guide`
74 | 	
75 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/display/st7796.rst:
--------------------------------------------------------------------------------
 1 | ============================
 2 | ST7796 LCD Controller driver
 3 | ============================
 4 | 
 5 | Overview
 6 | --------
 7 | 
 8 | The `ST7796S <https://www.buydisplay.com/download/ic/ST7796S.pdf>`__ is a single-chip controller/driver for 262K-color, graphic type TFT-LCD. It consists of 960
 9 | source lines and 480 gate lines driving circuits. The ST7796S is capable of connecting directly to an external
10 | microprocessor, and accepts 8-bit/9-bit/16-bit/18-bit parallel interface, SPI, and the ST7796S also provides
11 | MIPI interface. Display data can be stored in the on-chip display data RAM of 320x480x18 bits. It can perform
12 | display data RAM read-/write-operation with no external clock to minimize power consumption. In addition,
13 | because of the integrated power supply circuit necessary to drive liquid crystal; it is possible to make a display
14 | system with fewest components.
15 | 
16 | The ST7796 LCD controller `driver <https://github.com/lvgl/lvgl/src/drivers/display/st7796>`__ is a platform-agnostic driver, based on the `generic MIPI driver <https://github.com/lvgl/lvgl/doc/integration/drivers/display/gen_mipi.rst>`__.
17 | It implements display initialization, supports display rotation and implements the display flush callback. The user needs to implement only two platform-specific functions to send
18 | a command or pixel data to the controller via SPI or parallel bus. Typically these are implemented by calling the appropriate SDK library functions on the given platform.
19 | 
20 | Prerequisites
21 | -------------
22 | 
23 | There are no prerequisites.
24 | 
25 | Configuring the driver
26 | ----------------------
27 | 
28 | Enable the ST7796 driver support in lv_conf.h, by cmake compiler define or by KConfig
29 | 
30 | .. code-block:: c
31 | 
32 | 	#define LV_USE_ST7796  1
33 | 
34 | Usage
35 | -----
36 | 
37 | You need to implement two platform-dependent functions:
38 | 
39 | .. code-block:: c
40 | 
41 | 	/* Send short command to the LCD. This function shall wait until the transaction finishes. */
42 | 	int32_t my_lcd_send_cmd(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, const uint8_t *param, size_t param_size)
43 | 	{
44 | 		...
45 | 	}
46 | 
47 | 	/* Send large array of pixel data to the LCD. If necessary, this function has to do the byte-swapping. This function can do the transfer in the background. */
48 | 	int32_t my_lcd_send_color(lv_display_t *disp, const uint8_t *cmd, size_t cmd_size, uint8_t *param, size_t param_size)
49 | 	{
50 | 		...
51 | 	}
52 | 
53 | To create an ST7796-based display use the function
54 | 
55 | .. code-block:: c
56 | 
57 | 	/**
58 | 	 * Create an LCD display with ST7796 driver
59 | 	 * @param hor_res       horizontal resolution
60 | 	 * @param ver_res       vertical resolution
61 | 	 * @param flags         default configuration settings (mirror, RGB ordering, etc.)
62 | 	 * @param send_cmd      platform-dependent function to send a command to the LCD controller (usually uses polling transfer)
63 | 	 * @param send_color    platform-dependent function to send pixel data to the LCD controller (usually uses DMA transfer: must implement a 'ready' callback)
64 | 	 * @return              pointer to the created display
65 | 	 */
66 | 	lv_display_t * lv_st7796_create(uint32_t hor_res, uint32_t ver_res, lv_lcd_flag_t flags,
67 | 									lv_st7796_send_cmd_cb_t send_cmd_cb, lv_st7796_send_color_cb_t send_color_cb);
68 | 
69 | 
70 | For additional details and a working example see the `generic MIPI driver documentation <https://github.com/lvgl/lvgl/doc/integration/drivers/display/gen_mipi.rst>`__.
71 | 
72 | .. note::
73 | 
74 | 	You can find a step-by-step guide and the actual implementation of the callbacks on an STM32F746 using STM32CubeIDE and the ST HAL libraries here: :ref:`lcd_stm32_guide`
75 | 	
76 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/index.rst:
--------------------------------------------------------------------------------
 1 | .. _drivers:
 2 | 
 3 | =======
 4 | Drivers
 5 | =======
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     display/index
11 |     libinput
12 |     opengles
13 |     touchpad/index
14 |     wayland
15 |     windows
16 |     X11
17 |     uefi
18 |     sdl
19 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/libinput.rst:
--------------------------------------------------------------------------------
 1 | ===============
 2 | Libinput Driver
 3 | ===============
 4 | 
 5 | Overview
 6 | --------
 7 | 
 8 | Libinput is an input stack for processes that need to provide events from commonly used input devices. That includes mice, keyboards, touchpads,
 9 | touchscreens and graphics tablets. Libinput handles device-specific quirks and provides an easy-to-use API to receive events from devices.
10 | 
11 | Prerequisites
12 | -------------
13 | 
14 | You have the development version of libinput installed (usually ``libinput-dev``). If your input device requires quirks, make sure they are
15 | installed as well (usually in ``/usr/share/libinput/*.quirks``). To test if your device is set up correctly for use with libinput, you can
16 | run ``libinput list-devices``.
17 | 
18 | .. code-block:: console
19 | 
20 |     $ sudo libinput list-devices
21 |     ...
22 |     Device:           ETPS/2 Elantech Touchpad
23 |     Kernel:           /dev/input/event5
24 |     Group:            10
25 |     Seat:             seat0, default
26 |     Size:             102x74mm
27 |     Capabilities:     pointer gesture
28 |     Tap-to-click:     disabled
29 |     Tap-and-drag:     enabled
30 |     ...
31 | 
32 | If your device doesn't show up, you may have to configure udev and the appropriate udev rules to connect it.
33 | 
34 | Additionally, if you want full keyboard support, including letters and modifiers, you'll need the development version of libxkbcommon
35 | installed (usually ``libxkbcommon-dev``).
36 | 
37 | Configuring the driver
38 | ----------------------
39 | 
40 | Enable the libinput driver support in lv_conf.h, by cmake compiler define or by KConfig.
41 | 
42 | .. code-block:: c
43 | 
44 |     #define LV_USE_LIBINPUT    1
45 | 
46 | Full keyboard support needs to be enabled separately.
47 | 
48 | .. code-block:: c
49 | 
50 |     #define LV_LIBINPUT_XKB            1
51 |     #define LV_LIBINPUT_XKB_KEY_MAP    { .rules = NULL, .model = "pc101", .layout = "us", .variant = NULL, .options = NULL }
52 |     
53 | To find the right key map values, you may use the ``setxkbmap -query`` command.
54 | 
55 | Usage
56 | -----
57 | 
58 | To set up an input device via the libinput driver, all you need to do is call ``lv_libinput_create`` with the respective device type
59 | (``LV_INDEV_TYPE_POINTER`` or ``LV_INDEV_TYPE_KEYPAD``) and device node path (e.g. ``/dev/input/event5``).
60 | 
61 | .. code-block:: c
62 | 
63 |     lv_indev_t *indev = lv_libinput_create(LV_INDEV_TYPE_POINTER, "/dev/input/event5");
64 | 
65 | Note that touchscreens are treated as (absolute) pointer devices by the libinput driver and require ``LV_INDEV_TYPE_POINTER``.
66 | 
67 | Depending on your system, the device node paths might not be stable across reboots. If this is the case, you can use ``lv_libinput_find_dev``
68 | to find the first device that has a specific capability.
69 | 
70 | .. code-block:: c
71 | 
72 |     char *path = lv_libinput_find_dev(LV_LIBINPUT_CAPABILITY_TOUCH, true);
73 | 
74 | The second argument controls whether or not all devices are rescanned. If you have many devices connected this can get quite slow.
75 | Therefore, you should only specify ``true`` on the first call when calling this method multiple times in a row. If you want to find
76 | all devices that have a specific capability, use ``lv_libinput_find_devs``.
77 | 
78 | If you want to connect a keyboard device to a textarea, create a dedicated input group and set it on both the indev and textarea.
79 | 
80 | .. code-block:: c
81 | 
82 |     lv_obj_t *textarea = lv_textarea_create(...);
83 |     ...
84 |     lv_group_t *keyboard_input_group = lv_group_create();
85 |     lv_indev_set_group(indev, keyboard_input_group);
86 |     lv_group_add_obj(keyboard_input_group, textarea);
87 | 
88 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/sdl.rst:
--------------------------------------------------------------------------------
  1 | .. _sdl_driver:
  2 | 
  3 | ===============================
  4 | SDL Driver
  5 | ===============================
  6 | 
  7 | Overview
  8 | --------
  9 | 
 10 | | SDL (Simple DirectMedia Layer) provides a cross-platform way to handle graphics, input, and multimedia, making it an excellent choice for running LVGL applications on a PC.
 11 | 
 12 | 
 13 | Prerequisites
 14 | -------------
 15 | 
 16 | Install SDL according to your platform.
 17 |     Linux ``sudo apt install libsdl2-dev``
 18 |     MacOS ``brew install sdl2``
 19 |     Windows https://github.com/libsdl-org/SDL/releases
 20 | 
 21 | 
 22 | Configure SDL Driver
 23 | -----------------------
 24 | 
 25 | 1. Required linked libraries: -lSDL2
 26 | 2. Enable SDL driver support in lv_conf.h, CMake compiler definitions or KConfig.
 27 |     .. code-block:: c
 28 | 
 29 |         #define LV_USE_SDL  1
 30 |         #define LV_SDL_INCLUDE_PATH <SDL2/SDL.h>
 31 |         #define SDL_HOR_RES 400
 32 |         #define SDL_VER_RES 400
 33 | 
 34 | Basic Usage
 35 | -----------
 36 | 
 37 | .. code-block:: c
 38 | 
 39 |     #include <unistd.h>
 40 |     #define SDL_MAIN_HANDLED        /*To fix SDL's "undefined reference to WinMain" issue*/
 41 |     #include <SDL2/SDL.h>
 42 |     #include "drivers/sdl/lv_sdl_mouse.h"
 43 |     #include "drivers/sdl/lv_sdl_mousewheel.h"
 44 |     #include "drivers/sdl/lv_sdl_keyboard.h"
 45 | 
 46 |     static lv_display_t *lvDisplay;
 47 |     static lv_indev_t *lvMouse;
 48 |     static lv_indev_t *lvMouseWheel;
 49 |     static lv_indev_t *lvKeyboard;
 50 | 
 51 |     #if LV_USE_LOG != 0
 52 |     static void lv_log_print_g_cb(lv_log_level_t level, const char * buf)
 53 |     {
 54 |         LV_UNUSED(level);
 55 |         LV_UNUSED(buf);
 56 |     }
 57 |     #endif
 58 | 
 59 |     int main()
 60 |     {
 61 |         /* initialize lvgl */
 62 |         lv_init();
 63 | 
 64 |         // Workaround for sdl2 `-m32` crash
 65 |         // https://bugs.launchpad.net/ubuntu/+source/libsdl2/+bug/1775067/comments/7
 66 |         #ifndef WIN32
 67 |             setenv("DBUS_FATAL_WARNINGS", "0", 1);
 68 |         #endif
 69 | 
 70 |         /* Register the log print callback */
 71 |         #if LV_USE_LOG != 0
 72 |         lv_log_register_print_cb(lv_log_print_g_cb);
 73 |         #endif
 74 | 
 75 |         /* Add a display
 76 |         * Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
 77 | 
 78 |         lvDisplay = lv_sdl_window_create(SDL_HOR_RES, SDL_VER_RES);
 79 |         lvMouse = lv_sdl_mouse_create();
 80 |         lvMouseWheel = lv_sdl_mousewheel_create();
 81 |         lvKeyboard = lv_sdl_keyboard_create();
 82 | 
 83 |         /* create Widgets on the screen */
 84 |         lv_demo_widgets();
 85 | 
 86 | 
 87 |         Uint32 lastTick = SDL_GetTicks();
 88 |         while(1) {
 89 |             SDL_Delay(5);
 90 |             Uint32 current = SDL_GetTicks();
 91 |             lv_tick_inc(current - lastTick); // Update the tick timer. Tick is new for LVGL 9
 92 |             lastTick = current;
 93 |             lv_timer_handler(); // Update the UI-
 94 |         }
 95 | 
 96 |         return 0;
 97 |     }
 98 | 
 99 | Using an IDE
100 | ------------
101 | 
102 | LVGL with SDL has been ported to various IDEs.
103 | 
104 | - `Eclipse with SDL driver <https://github.com/lvgl/lv_sim_eclipse_sdl>`__: Recommended on Linux and Mac, supports CMake as well
105 | - `VSCode with SDL driver <https://github.com/lvgl/lv_port_pc_vscode>`__: Recommended on Linux (SDL) and Mac (SDL)
106 | - `Generic Linux <https://github.com/lvgl/lv_port_linux>`__: CMake based project where you can easily switch between fbdev, DRM, and SDL.
107 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/touchpad/ft6x36.rst:
--------------------------------------------------------------------------------
1 | ======
2 | FT6X36
3 | ======
4 | 
5 | TODO


--------------------------------------------------------------------------------
/docs/src/details/integration/driver/touchpad/index.rst:
--------------------------------------------------------------------------------
 1 | ========
 2 | Touchpad
 3 | ========
 4 | 
 5 | .. toctree::
 6 |     :maxdepth: 2
 7 | 
 8 |     evdev
 9 |     ft6x36
10 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/framework/index.rst:
--------------------------------------------------------------------------------
 1 | ==========
 2 | Frameworks
 3 | ==========
 4 | 
 5 | .. toctree::
 6 |     :maxdepth: 2
 7 | 
 8 |     arduino
 9 |     platformio
10 |     tasmota-berry
11 | 
12 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/framework/platformio.rst:
--------------------------------------------------------------------------------
1 | ==========
2 | PlatformIO
3 | ==========
4 | 
5 | TODO
6 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/ide/index.rst:
--------------------------------------------------------------------------------
 1 | ====
 2 | IDEs
 3 | ====
 4 | 
 5 | .. toctree::
 6 |     :maxdepth: 2
 7 | 
 8 |     mdk
 9 |     pc-simulator
10 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/ide/mdk.rst:
--------------------------------------------------------------------------------
1 | ===
2 | MDK
3 | ===
4 | 
5 | TODO
6 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/ide/pc-simulator.rst:
--------------------------------------------------------------------------------
 1 | .. _simulator:
 2 | 
 3 | ===============
 4 | Simulator on PC
 5 | ===============
 6 | 
 7 | You can try out LVGL **using only your PC** (i.e. without any
 8 | development boards). LVGL will run on a simulator environment on the PC
 9 | where anyone can write and experiment with real LVGL applications.
10 | 
11 | Using the simulator on a PC has the following advantages:
12 | 
13 | - Hardware independent: Write code, run it on the PC and see the result on a monitor.
14 | - Cross-platform: Any Windows, Linux or macOS system can run the PC simulator.
15 | - Portability: The written code is portable, which means you can simply copy it when migrating to embedded hardware.
16 | - Easy Validation: The simulator is also very useful to report bugs because it
17 |   provides a common platform for every user.
18 | - Better developer experience: On PC Debuggers are usually faster and better, you can log to files,
19 |   add a lot of ``printf`` s, do profiling, and so on.
20 | 
21 | 
22 | Select an IDE
23 | -------------
24 | 
25 | The simulator is ported to various IDEs (Integrated Development Environments).
26 | Choose your favorite IDE, read its README on GitHub, download the project, and load it to the IDE.
27 | 
28 | - `Eclipse with SDL driver <https://github.com/lvgl/lv_sim_eclipse_sdl>`__: Recommended on Linux and Mac, supports CMake as well
29 | - `VisualStudio <https://github.com/lvgl/lv_port_pc_visual_studio>`__: Recommended on Windows
30 | - `VSCode with SDL driver <https://github.com/lvgl/lv_port_pc_vscode>`__: Recommended on Linux (SDL) and Mac (SDL)
31 | - `CodeBlocks <https://github.com/lvgl/lv_sim_codeblocks_win>`__: Recommended on Windows
32 | - `PlatformIO with SDL driver <https://github.com/lvgl/lv_platformio>`__: Recommended on Linux and Mac but has an STM32 environment as well
33 | - `Generic Linux <https://github.com/lvgl/lv_port_linux>`__: CMake based project where you can easily switch between fbdev, DRM, and SDL.
34 | - `MDK with FastModel <https://github.com/lvgl/lv_port_an547_cm55_sim>`__: For Windows
35 | 
36 | External project not maintained by the LVGL organization:
37 | 
38 | - `QT Creator <https://github.com/Varanda-Labs/lvgl-qt-sim>`__: Cross platform
39 | 
40 | Built-in drivers
41 | ----------------
42 | 
43 | LVGL comes with several :ref:`built-in drivers <drivers>`.
44 | 
45 | Even if a simulator project comes with e.g. SDL, you can easily replace it by enabling
46 | another driver in ``lv_conf.h`` and calling its ``create`` function.
47 | 
48 | For example to use the Linux frame buffer device instead of SDL just enable ``LV_USE_LINUX_FBDEV``
49 | and call
50 | 
51 | .. code-block:: c
52 | 
53 |    lv_display_t *display = lv_linux_fbdev_create();
54 |    lv_linux_fbdev_set_file(display, "/dev/fb0")
55 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/index.rst:
--------------------------------------------------------------------------------
 1 | .. _integration_index:
 2 | 
 3 | =======================
 4 | Integration and Drivers
 5 | =======================
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     adding-lvgl-to-your-project/index
11 |     bindings/index
12 |     building/index
13 |     chip/index
14 |     driver/index
15 |     renderers/index
16 |     framework/index
17 |     ide/index
18 |     os/index
19 |     boards/index
20 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/os/buildroot/index.rst:
--------------------------------------------------------------------------------
 1 | 
 2 | .. rst-class:: center
 3 | 
 4 | Buildroot
 5 | #########
 6 | 
 7 | Buildroot is a set of Makefiles and patches that simplifies and automates the 
 8 | process of building a complete and bootable Linux environment for an embedded 
 9 | system, while using cross-compilation to allow building for multiple target 
10 | platforms on a single Linux-based development system.
11 | 
12 | 
13 | .. toctree::
14 |    :titlesonly:
15 |    :maxdepth: 1
16 | 
17 |    quick_setup
18 |    image_generation
19 |    lvgl_app
20 | 
21 |    


--------------------------------------------------------------------------------
/docs/src/details/integration/os/buildroot/quick_setup.rst:
--------------------------------------------------------------------------------
 1 | Quick Setup 
 2 | ###########
 3 | 
 4 | A Git repository is available that includes everything needed to test the 
 5 | Buildroot setup without following the guide. It is intended for testing 
 6 | purposes and can be used if you are already familiar with Buildroot concepts 
 7 | and architecture.
 8 | 
 9 | Get the repository
10 | 
11 | .. code-block:: bash
12 | 
13 |     git clone --recurse-submodules https://github.com/lvgl/lv_buildroot.git
14 | 
15 | Build the image
16 | 
17 | .. code-block:: bash 
18 | 
19 |     ./build.sh 
20 | 
21 | At this point, you have an image that can be flashed on an SD and used.
22 | 
23 | Now build the SDK and install it
24 | 
25 | .. code-block:: bash
26 | 
27 |     cd output
28 |     make sdk
29 |     mkdir -p ~/sdk
30 |     tar -xzf images/aarch64-buildroot-linux-gnu_sdk-buildroot.tar.gz -C ~/sdk
31 | 
32 | The SDK is installed. Compile the application.
33 | 
34 | .. code-block:: bash
35 | 
36 |     cd ../application/lv_benchmark 
37 |     source ../setup-build-env.sh
38 |     cmake -B build -S .
39 |     make -j $(nproc) -C build
40 |     cd ../..
41 | 
42 | Install the binary in the rootfs_overlay
43 | 
44 | .. code-block:: bash
45 | 
46 |     cp application/lv_benchmark/bin/lvgl-app resources/board/rootfs_overlay/usr/bin/
47 | 
48 | Regenerate the image with the rootfs overlay updated.
49 | 
50 | .. code-block:: bash
51 | 
52 |     cd output
53 |     make
54 | 
55 | Go to :ref:`flash_the_image` to test the system.
56 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/os/freertos.rst:
--------------------------------------------------------------------------------
1 | ========
2 | FreeRTOS
3 | ========
4 | 
5 | TODO
6 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/os/index.rst:
--------------------------------------------------------------------------------
 1 | ======
 2 | (RT)OS
 3 | ======
 4 | 
 5 | .. toctree:: :maxdepth: 2
 6 | 
 7 |     freertos
 8 |     mqx
 9 |     nuttx
10 |     px5
11 |     qnx
12 |     rt-thread
13 |     yocto/index
14 |     buildroot/index
15 |     zephyr
16 |     torizon_os
17 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/os/mqx.rst:
--------------------------------------------------------------------------------
 1 | .. _mqx:
 2 | 
 3 | ========
 4 | MQX RTOS
 5 | ========
 6 | 
 7 | See `MQX RTOS's homepage <https://www.nxp.com/design/design-center/software/embedded-software/mqx-software-solutions/mqx-real-time-operating-system-rtos:MQXRTOS>`__
 8 | 
 9 | 
10 | TODO
11 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/os/px5.rst:
--------------------------------------------------------------------------------
1 | ========
2 | PX5 RTOS
3 | ========
4 | 
5 | See `PX5 RTOS's homepage <https://px5rtos.com/>`__
6 | 
7 | 
8 | TODO
9 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/os/yocto/index.rst:
--------------------------------------------------------------------------------
 1 | .. _yocto:
 2 | 
 3 | =====
 4 | Yocto
 5 | =====
 6 | 
 7 | The Yocto Project (YP) is an open source collaboration project that helps
 8 | developers create custom Linux-based systems regardless of the hardware
 9 | architecture.
10 | 
11 | The project provides a flexible set of tools and a space where embedded
12 | developers worldwide can share technologies, software stacks, configurations,
13 | and best practices that can be used to create tailored Linux images for
14 | embedded and IOT devices, or anywhere a customized Linux OS is needed.
15 | 
16 | This section objective is to ease to process of understanding the basic
17 | concepts of Yocto and to help beginners to start with Yocto.
18 | 
19 | 
20 | .. toctree::
21 |    :titlesonly:
22 |    :maxdepth: 1
23 | 
24 |    core_components
25 |    lvgl_recipe
26 |    terms_and_variables
27 | 
28 | 
29 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/renderers/arm2d.rst:
--------------------------------------------------------------------------------
 1 | .. _arm2d:
 2 | 
 3 | ==========
 4 | Arm-2D GPU
 5 | ==========
 6 | 
 7 | Arm-2D is not a GPU but **an abstraction layer for 2D GPUs dedicated to
 8 | Microcontrollers**. It supports all Cortex-M processors ranging from
 9 | Cortex-M0 to the latest Cortex-M85.
10 | 
11 | Arm-2D accelerates LVGL9 with two modes: **Synchronous Mode** and
12 | **Asynchronous Mode**.
13 | 
14 | - When **Helium** and **ACI (Arm Custom Instruction)** are available, it is recommend
15 |   to use **Synchronous Mode** to accelerate LVGL.
16 | - When Arm-2D backed 2D-GPUs are available, for example, **DMAC-350 based 2D
17 |   GPUs**, it is recommend to use **Asynchronous Mode** to accelerate LVGL.
18 | 
19 | Arm-2D is an open-source project on GitHub. For more, please refer to:
20 | https://github.com/ARM-software/Arm-2D.
21 | 
22 | 
23 | How to Use
24 | **********
25 | 
26 | In general:
27 | 
28 | - you can set the macro :c:macro:`LV_USE_DRAW_ARM2D_SYNC` to ``1`` and
29 |   :c:macro:`LV_DRAW_SW_ASM` to ``LV_DRAW_SW_ASM_HELIUM`` in ``lv_conf.h`` to
30 |   enable Arm-2D synchronous acceleration for LVGL.
31 | - You can set
32 |   the macro :c:macro:`LV_USE_DRAW_ARM2D_ASYNC` to ``1`` in ``lv_conf.h`` to enable
33 |   Arm-2D Asynchronous acceleration for LVGL.
34 | 
35 | If you are using
36 | `CMSIS-Pack <https://github.com/lvgl/lvgl/tree/master/env_support/cmsis-pack>`__
37 | to deploy the LVGL. You don't have to define the macro
38 | :c:macro:`LV_USE_DRAW_ARM2D_SYNC` manually, instead the lv_conf_cmsis.h will
39 | check the environment and set the :c:macro:`LV_USE_DRAW_ARM2D_SYNC` accordingly.
40 | 
41 | Design Considerations
42 | *********************
43 | 
44 | As mentioned before, Arm-2D is an abstraction layer for 2D GPU; hence if
45 | there is no accelerator or dedicated instruction set (such as Helium or
46 | ACI) available for Arm-2D, it provides negligible performance boost for
47 | LVGL (sometimes worse) for regular Cortex-M processors.
48 | 
49 | **We highly recommend you enable Arm-2D acceleration for LVGL** when:
50 | 
51 | -  The target processors are **Cortex-M55**, **Cortex-M52** and **Cortex-M85**
52 | -  The target processors support
53 |    `Helium <https://developer.arm.com/documentation/102102/0103/?lang=en>`__.
54 | -  The device vendor provides an arm-2d compliant driver for their
55 |    proprietary 2D accelerators and/or ACI (Arm Customized Instruction).
56 | -  The target device contains
57 |    `DMAC-350 <https://community.arm.com/arm-community-blogs/b/internet-of-things-blog/posts/arm-corelink-dma-350-next-generation-direct-memory-access-for-endpoint-ai>`__
58 | 
59 | Examples
60 | ********
61 | 
62 | -  `A Cortex-M55 (supports Helium) based MDK Project, PC emulation is
63 |    available. <https://github.com/lvgl/lv_port_an547_cm55_sim>`__
64 | 
65 | API
66 | ***
67 | 
68 | :ref:`lv_draw_sw_arm2d_h`
69 | 
70 | :ref:`lv_blend_arm2d_h`
71 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/renderers/index.rst:
--------------------------------------------------------------------------------
 1 | ==================
 2 | Renderers and GPUs
 3 | ==================
 4 | 
 5 | .. toctree::
 6 |     :maxdepth: 2
 7 | 
 8 |     sw
 9 |     arm2d
10 |     nema_gfx
11 |     nxp_pxp
12 |     nxp_vglite_gpu
13 |     nxp_g2d
14 |     sdl
15 |     stm32_dma2d
16 |     vg_lite
17 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/renderers/nxp_g2d.rst:
--------------------------------------------------------------------------------
1 | ===========
2 | NXP G2D GPU
3 | ===========
4 | 
5 | API
6 | ***
7 | 
8 | :ref:`lv_draw_g2d_h`
9 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/renderers/nxp_pxp.rst:
--------------------------------------------------------------------------------
 1 | ===========
 2 | NXP PXP GPU
 3 | ===========
 4 | 
 5 | API
 6 | ***
 7 | 
 8 | :ref:`lv_draw_pxp_h`
 9 | 
10 | :ref:`lv_pxp_cfg_h`
11 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/renderers/nxp_vglite_gpu.rst:
--------------------------------------------------------------------------------
1 | ==============
2 | NXP VGLite GPU
3 | ==============
4 | 
5 | API
6 | ***
7 | 
8 | :ref:`lv_draw_vglite_h`
9 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/renderers/sdl.rst:
--------------------------------------------------------------------------------
 1 | ============
 2 | SDL Renderer
 3 | ============
 4 | 
 5 | API
 6 | ***
 7 | 
 8 | :ref:`lv_draw_sdl_h`
 9 | 
10 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/renderers/stm32_dma2d.rst:
--------------------------------------------------------------------------------
 1 | ===============
 2 | STM32 DMA2D GPU
 3 | ===============
 4 | 
 5 | API
 6 | ***
 7 | 
 8 | :ref:`lv_draw_dma2d_h`
 9 | 
10 | 


--------------------------------------------------------------------------------
/docs/src/details/integration/renderers/sw.rst:
--------------------------------------------------------------------------------
1 | =================
2 | Software Renderer
3 | =================
4 | 
5 | API
6 | ***
7 | 
8 | .. API startswith:  lv_draw_sw
9 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/arduino_esp_littlefs.rst:
--------------------------------------------------------------------------------
 1 | .. _arduino_esp_littlefs:
 2 | 
 3 | ====================
 4 | Arduino ESP littlefs
 5 | ====================
 6 | 
 7 | LittleFS is a little fail-safe filesystem designed for microcontrollers and integrated in the Arduino framework
 8 | when used with ESP32 and ESP8266.
 9 | 
10 | For a detailed introduction, see:
11 | 
12 | - https://github.com/esp8266/Arduino
13 | - https://github.com/espressif/arduino-esp32
14 | 
15 | 
16 | Usage
17 | *****
18 | 
19 | Enable :c:macro:`LV_USE_FS_ARDUINO_ESP_LITTLEFS` and define a :c:macro:`LV_FS_ARDUINO_ESP_LITTLEFS_LETTER` in ``lv_conf.h``.
20 | 
21 | 
22 | API
23 | ***
24 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/arduino_sd.rst:
--------------------------------------------------------------------------------
 1 | .. _arduino_sd:
 2 | 
 3 | ==========
 4 | Arduino SD
 5 | ==========
 6 | 
 7 | Enables reading from and writing to SD cards.
 8 | Once an SD memory card is connected to the SPI interface of the Arduino or Genuino board, you can create files
 9 | and read from, and write to them.  You can also move through directories on the SD card.
10 | 
11 | For a detailed introduction, see:
12 | 
13 | - https://www.arduino.cc/reference/en/libraries/sd/
14 | 
15 | 
16 | Usage
17 | *****
18 | 
19 | Enable :c:macro:`LV_USE_FS_ARDUINO_SD` and define a :c:macro:`LV_FS_ARDUINO_SD_LETTER` in ``lv_conf.h``.
20 | You will need to initialize the SD card before LVGL can use it (i.e. :cpp:expr:`SD.begin(0, SPI, 40000000)`).
21 | 
22 | 
23 | API
24 | ***
25 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/barcode.rst:
--------------------------------------------------------------------------------
 1 | .. _barcode:
 2 | 
 3 | =======
 4 | Barcode
 5 | =======
 6 | 
 7 | The LVGL Barcode utility enables you to generate Code-128 bar codes.  It uses the
 8 | `code128 <https://github.com/fhunleth/code128>`__ library by
 9 | `fhunleth <https://github.com/fhunleth>`__.
10 | 
11 | 
12 | 
13 | .. _barcode_usage:
14 | 
15 | Usage
16 | *****
17 | 
18 | Set :c:macro:`LV_USE_BARCODE` to ``1`` in ``lv_conf.h``.
19 | 
20 | Use :cpp:func:`lv_barcode_create` to create a barcode object, and use
21 | :cpp:func:`lv_barcode_update` to generate a barcode.
22 | 
23 | Call :cpp:func:`lv_barcode_set_scale` to adjust scaling,
24 | call :cpp:func:`lv_barcode_set_dark_color` and :cpp:func:`lv_barcode_set_light_color`
25 | adjust colors.  Call :cpp:func:`lv_barcode_set_direction` to set the bar code's
26 | orientation.
27 | 
28 | By default, :cpp:enumerator:`LV_BARCODE_ENCODING_CODE128_GS1` encoding is used
29 | and strips ``[FCN1]`` and spaces. Optionally use
30 | :cpp:func:`lv_barcode_set_encoding` to set
31 | :cpp:enumerator:`LV_BARCODE_ENCODING_CODE128_RAW`.
32 | 
33 | After any of a bar code's settings have changed, call
34 | :cpp:func:`lv_barcode_update` again to regenerate it.
35 | 
36 | 
37 | 
38 | Notes
39 | *****
40 | 
41 | -  It is best not to manually set the width of the barcode, because when
42 |    the width of the Widget is lower than the width of the barcode, the
43 |    display will be incomplete due to truncation.
44 | -  The scale adjustment can only be an integer multiple, for example,
45 |    :cpp:expr:`lv_barcode_set_scale(barcode, 2)` means 2x scaling.
46 | -  The direction setting can be :cpp:enumerator:`LV_DIR_HOR` or :cpp:enumerator:`LV_DIR_VER`.
47 | 
48 | 
49 | 
50 | .. _barcode_example:
51 | 
52 | Example
53 | *******
54 | 
55 | .. include:: ../../examples/libs/barcode/index.rst
56 | 
57 | 
58 | 
59 | .. _barcode_api:
60 | 
61 | API
62 | ***
63 | 
64 | .. API startswith:  lv_barcode_
65 | 
66 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/bmp.rst:
--------------------------------------------------------------------------------
 1 | .. _bmp:
 2 | 
 3 | ===========
 4 | BMP Decoder
 5 | ===========
 6 | 
 7 | This BMP Decoder utility allows you to use images from .BMP files in LVGL.
 8 | 
 9 | Library source: https://github.com/caj-johnson/bmp-decoder
10 | 
11 | Instead of loading the whole image at once, BMP pixels are read on demand,
12 | so using BMP images requires very little RAM.
13 | 
14 | If enabled in ``lv_conf.h`` by setting :c:macro:`LV_USE_BMP` to ``1``, LVGL will
15 | register a new image decoder automatically so BMP files can be directly used as image
16 | sources.  Example:
17 | 
18 | .. code-block:: c
19 | 
20 |    lv_image_set_src(my_img, "S:path/to/picture.bmp");
21 | 
22 | Note that, a :ref:`file_system` driver needs to registered to open images from
23 | files.  Follow the instructions in :ref:`file_system`.
24 | 
25 | 
26 | 
27 | .. _bmp_limitations:
28 | 
29 | Limitations
30 | ***********
31 | 
32 | -  Only BMP files are supported.  BMP images as C arrays
33 |    (:c:struct:`lv_image_dsc_t`) are not.  This is because there is no practical
34 |    differences between how the BMP files and LVGL's image format stores
35 |    the image data.
36 | -  BMP files can be loaded only from .BMP files. If you want to store them in
37 |    flash it's better to convert them to a C array with `LVGL's image converter <https://lvgl.io/tools/imageconverter>`__.
38 | -  The BMP file's color format needs to match the configured :c:macro:`LV_COLOR_DEPTH`
39 |    of the display on which it will be rendered.  You can use GIMP to save the image
40 |    in the required format.  Both RGB888 and ARGB888 works with
41 |    :c:macro:`LV_COLOR_DEPTH` ``32``
42 | -  Color palettes are not supported.
43 | -  Because the whole image is not loaded, it cannot be zoomed or rotated.
44 | 
45 | 
46 | 
47 | .. _bmp_example:
48 | 
49 | Example
50 | *******
51 | 
52 | .. include:: ../../examples/libs/bmp/index.rst
53 | 
54 | 
55 | 
56 | .. _bmp_api:
57 | 
58 | API
59 | ***
60 | 
61 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/ffmpeg.rst:
--------------------------------------------------------------------------------
  1 | .. _ffmpeg:
  2 | 
  3 | ==============
  4 | FFmpeg Support
  5 | ==============
  6 | 
  7 | **FFmpeg** is a complete, cross-platform solution to record, convert and stream audio and video.
  8 | 
  9 | The FFmpeg is an LVGL extension that interfaces with the official FFmpeg library to help
 10 | you add platform-independent recording, converting and streaming audio and video into
 11 | your LVGL UI.
 12 | 
 13 | The set-up steps below are for Linux, but they can be adapted for other platforms.
 14 | 
 15 | For a detailed introduction, see:  https://www.ffmpeg.org
 16 | 
 17 | 
 18 | 
 19 | Installing FFmpeg
 20 | *****************
 21 | 
 22 | .. code-block:: shell
 23 | 
 24 |     sudo apt install libavformat-dev libavcodec-dev libswscale-dev libavutil-dev
 25 | 
 26 | Or download the FFmpeg library from `its official download page
 27 | <https://www.ffmpeg.org/download.html>`__, then install it:
 28 | 
 29 | .. code-block:: shell
 30 | 
 31 |     ./configure --disable-all --disable-autodetect --disable-podpages --disable-asm --enable-avcodec --enable-avformat --enable-decoders --enable-encoders --enable-demuxers --enable-parsers --enable-protocol='file' --enable-swscale --enable-zlib
 32 |     make
 33 |     sudo make install
 34 | 
 35 | 
 36 | 
 37 | Adding FFmpeg to Your Project
 38 | *****************************
 39 | 
 40 | To use the ``FFmpeg`` library in your project, you will need to link against these
 41 | libraries:
 42 | 
 43 | :libavformat:   part of FFmpeg library
 44 | :libavcodec:    part of FFmpeg library
 45 | :libavutil:     part of FFmpeg library
 46 | :libswscale:    part of FFmpeg library
 47 | :libm:
 48 | :libz:
 49 | :libpthread:
 50 | 
 51 | If you are using GCC-based toolchain, this can be taken care of by adding the
 52 | following command-line options:
 53 | 
 54 | .. code-block:: shell
 55 | 
 56 |     -lavformat -lavcodec -lavutil -lswscale -lm -lz -lpthread
 57 | 
 58 | 
 59 | 
 60 | .. _ffmpeg_usage:
 61 | 
 62 | Usage
 63 | *****
 64 | 
 65 | Set the :c:macro:`LV_USE_FFMPEG` in ``lv_conf.h`` to ``1``.
 66 | 
 67 | Also set :c:macro:`LV_FFMPEG_PLAYER_USE_LV_FS` in ``lv_conf.h`` to ``1`` if you want
 68 | to integrate the LVGL :ref:`file_system` extension into FFmpeg.
 69 | This library can load videos and images. The LVGL file system
 70 | will always be used when an image is loaded with :cpp:func:`lv_image_set_src`
 71 | regardless of the value of :c:macro:`LV_FFMPEG_PLAYER_USE_LV_FS`.
 72 | 
 73 | See the examples below for how to correctly use this library.
 74 | 
 75 | 
 76 | 
 77 | .. _ffmpeg_example:
 78 | 
 79 | Events
 80 | ******
 81 | 
 82 | - :cpp:enumerator:`LV_EVENT_READY` Sent when playback is complete and auto-restart is not enabled.
 83 | 
 84 | Learn more about :ref:`events`.
 85 | 
 86 | 
 87 | 
 88 | Examples
 89 | ********
 90 | 
 91 | .. include:: ../../examples/libs/ffmpeg/index.rst
 92 | 
 93 | 
 94 | 
 95 | .. _ffmpeg_api:
 96 | 
 97 | API
 98 | ***
 99 | 
100 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/fs.rst:
--------------------------------------------------------------------------------
 1 | .. _libs_filesystem:
 2 | 
 3 | ======================
 4 | File System Interfaces
 5 | ======================
 6 | 
 7 | LVGL's :ref:`file_system` module provides an abstraction that enables you to attach
 8 | any type of file system for LVGL's use.  File systems already supported are:
 9 | 
10 | - `FATFS <http://elm-chan.org/fsw/ff/00index_e.html>`__
11 | - STDIO (Linux and Windows using C standard function .e.g ``fopen``, ``fread``)
12 | - POSIX (Linux and Windows using POSIX function .e.g ``open``, ``read``)
13 | - WIN32 (Windows using Win32 API function .e.g ``CreateFileA``, ``ReadFile``)
14 | - MEMFS (read a file from a memory buffer)
15 | - LITTLEFS (a little fail-safe filesystem designed for microcontrollers)
16 | - Arduino ESP LITTLEFS (a little fail-safe filesystem designed for Arduino ESP)
17 | - Arduino SD (allows for reading from and writing to SD cards)
18 | 
19 | You still need to provide the drivers and libraries, this extension
20 | provides only the bridge between LVGL and these file systems.
21 | 
22 | 
23 | 
24 | .. _libs_filesystem_usage:
25 | 
26 | Usage
27 | *****
28 | 
29 | In ``lv_conf.h`` enable ``LV_USE_FS_...`` (by setting its value to ``1``) and assign
30 | an upper cased letter to ``LV_FS_..._DRIVER_LETTER`` (e.g. ``'S'``).  If more than
31 | one file system is enabled, each driver will need to have a unique driver-identifier
32 | letter.  After that you can access files using that driver letter.  Example with
33 | driver identifier letter ``'S'``:
34 | 
35 | :Linux-like relative path:    ``"S:path/to/file.txt"``
36 | :Linux-like absolute path:    ``"S:/path/to/file.txt"``
37 | :Windows-like relative path:  ``"S:C:path/to/file.txt"``
38 | :Windows-like absolute path:  ``"S:C:/path/to/file.txt"``
39 | 
40 | Do not confuse the driver-identifier letter with the Windows/DOS/FAT "drive letter",
41 | which is part of the path passed to the OS-level functions.  For more details, see
42 | :ref:`lv_fs_identifier_letters`.
43 | 
44 | :ref:`Cached reading <file_system_cache>` is also supported if ``LV_FS_..._CACHE_SIZE`` is set to
45 | a non-zero value.
46 | 
47 | For further details, including how to create support for your own file system, see
48 | :ref:`file_system`.
49 | 
50 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/gif.rst:
--------------------------------------------------------------------------------
 1 | .. _gif:
 2 | 
 3 | ===========
 4 | GIF Decoder
 5 | ===========
 6 | 
 7 | **GIF Decoder** is an LVGL extension that enables you to use GIF images in your LVGL UI.
 8 | 
 9 | For a detailed introduction, see:  https://github.com/lecram/gifdec .
10 | 
11 | 
12 | 
13 | Usage
14 | *****
15 | 
16 | Once enabled in ``lv_conf.h`` by setting :c:macro:`LV_USE_GIF` to ``1``,
17 | :cpp:expr:`lv_gif_create(parent)` can be used to create a gif widget.
18 | 
19 | :cpp:expr:`lv_gif_set_src(widget, src)` works very similarly to :cpp:func:`lv_image_set_src`.
20 | As source, it also accepts images as variables (:c:struct:`lv_image_dsc_t`) or files.
21 | 
22 | Converting GIF Files to C Arrays
23 | --------------------------------
24 | 
25 | To convert a GIF file to an array of bytes, use `LVGL's online
26 | converter <https://lvgl.io/tools/imageconverter>`__. Select "Raw" color
27 | format and "C array" Output format.
28 | 
29 | Using GIF Images from Files
30 | ---------------------------
31 | 
32 | Example:
33 | 
34 | .. code-block:: c
35 | 
36 |    lv_gif_set_src(widget, "S:path/to/example.gif");
37 | 
38 | Note that, a file system driver needs to be registered to open images
39 | from files.  To do so, follow the instructions in :ref:`file_system`.
40 | 
41 | 
42 | 
43 | Memory Requirements
44 | *******************
45 | 
46 | To decode and display a GIF animation the following amount of RAM (in bytes) is
47 | required for each of the following color depths:
48 | 
49 | .. |times|  unicode:: U+000D7 .. MULTIPLICATION SIGN
50 | 
51 | - :c:macro:`LV_COLOR_DEPTH` ``8``: 3 |times| image width |times| image height
52 | - :c:macro:`LV_COLOR_DEPTH` ``16``: 4 |times| image width |times| image height
53 | - :c:macro:`LV_COLOR_DEPTH` ``32``: 5 |times| image width |times| image height
54 | 
55 | 
56 | 
57 | .. _gif_example:
58 | 
59 | Example
60 | *******
61 | 
62 | .. include:: ../../examples/libs/gif/index.rst
63 | 
64 | 
65 | 
66 | .. _gif_api:
67 | 
68 | API
69 | ***
70 | 
71 | .. API startswith:  lv_gif_
72 | 
73 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/index.rst:
--------------------------------------------------------------------------------
 1 | .. _3rd_party_libraries:
 2 | 
 3 | ===================
 4 | 3rd-Party Libraries
 5 | ===================
 6 | 
 7 | 
 8 | .. toctree::
 9 |     :maxdepth: 1
10 | 
11 |     arduino_esp_littlefs
12 |     arduino_sd
13 |     barcode
14 |     bmp
15 |     ffmpeg
16 |     freetype
17 |     fs
18 |     gif
19 |     lfs
20 |     libjpeg_turbo
21 |     libpng
22 |     lodepng
23 |     qrcode
24 |     rle
25 |     rlottie
26 |     svg
27 |     tiny_ttf
28 |     tjpgd
29 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/lfs.rst:
--------------------------------------------------------------------------------
 1 | .. _lfs:
 2 | 
 3 | ========
 4 | littlefs
 5 | ========
 6 | 
 7 | **littlefs** is a little fail-safe filesystem library designed for microcontrollers.
 8 | 
 9 | The lv_fs_littlefs extension is an interface to the littlefs library.
10 | 
11 | For a detailed introduction, see:  https://github.com/littlefs-project/littlefs .
12 | 
13 | 
14 | 
15 | Usage
16 | *****
17 | 
18 | Set :c:macro:`LV_USE_FS_LITTLEFS` in ``lv_conf.h`` to ``1`` and define an upper-case
19 | letter (as a C character type) for :c:macro:`LV_FS_LITTLEFS_LETTER` in the range
20 | ['A'..'Z'].
21 | 
22 | When enabled :cpp:func:`lv_littlefs_set_handler` can be used to set up a mount point.
23 | 
24 | Example
25 | *******
26 | 
27 | .. code-block:: c
28 | 
29 |     #include "lfs.h"
30 | 
31 |     // configuration of the filesystem is provided by this struct
32 |     const struct lfs_config cfg = {
33 |         // block device operations
34 |         .read  = user_provided_block_device_read,
35 |         .prog  = user_provided_block_device_prog,
36 |         .erase = user_provided_block_device_erase,
37 |         .sync  = user_provided_block_device_sync,
38 | 
39 |         // block device configuration
40 |         .read_size = 16,
41 |         .prog_size = 16,
42 |         .block_size = 4096,
43 |         .block_count = 128,
44 |         .cache_size = 16,
45 |         .lookahead_size = 16,
46 |         .block_cycles = 500,
47 |     };
48 | 
49 |     // mount the filesystem
50 |     int err = lfs_mount(&lfs, &cfg);
51 | 
52 |     // reformat if we can't mount the filesystem
53 |     // this should only happen on the first boot
54 |     if (err) {
55 |         lfs_format(&lfs, &cfg);
56 |         lfs_mount(&lfs, &cfg);
57 |     }
58 | 
59 |     lv_littlefs_set_handler(&lfs);
60 | 
61 | 
62 | API
63 | ***
64 | 
65 | :ref:`lv_fsdrv_h`
66 | 
67 | See also:  `lvgl/src/libs/fsdrv/lv_fs_littlefs.c <https://github.com/lvgl/lvgl/blob/master/src/libs/fsdrv/lv_fs_littlefs.c>`__
68 | 
69 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/libjpeg_turbo.rst:
--------------------------------------------------------------------------------
 1 | .. _libjpeg:
 2 | 
 3 | =====================
 4 | libjpeg-turbo Decoder
 5 | =====================
 6 | 
 7 | **libjpeg-turbo** is an LVGL interface to the libjpeg-turbo library --- a JPEG image
 8 | codec that uses SIMD instructions to accelerate baseline JPEG compression and
 9 | decompression on x86, x86-64, Arm, PowerPC, and MIPS systems, as well as progressive
10 | JPEG compression on x86, x86-64, and Arm systems.
11 | 
12 | On such systems, libjpeg-turbo is generally 2-6x as fast as libjpeg, all else being
13 | equal.
14 | 
15 | For a detailed introduction, see:  https://libjpeg-turbo.org .
16 | 
17 | Library source:  https://github.com/libjpeg-turbo/libjpeg-turbo
18 | 
19 | 
20 | 
21 | .. _libjpeg_install:
22 | 
23 | Install
24 | *******
25 | 
26 | .. code-block:: bash
27 | 
28 |     sudo apt install libjpeg-turbo8-dev
29 | 
30 | 
31 | 
32 | Adding  libjpeg-turbo to Your Project
33 | *************************************
34 | 
35 | Cmake:
36 | 
37 | .. code-block:: cmake
38 | 
39 |     find_package(JPEG REQUIRED)
40 |     include_directories(${JPEG_INCLUDE_DIR})
41 |     target_link_libraries(${PROJECT_NAME} PRIVATE ${JPEG_LIBRARIES})
42 | 
43 | 
44 | 
45 | .. _libjpeg_usage:
46 | 
47 | Usage
48 | *****
49 | 
50 | Set :c:macro:`LV_USE_LIBJPEG_TURBO` in ``lv_conf.h`` to ``1``.
51 | 
52 | See the examples below.
53 | 
54 | .. |times|  unicode:: U+000D7 .. MULTIPLICATION SIGN
55 | 
56 | It should be noted that each image decoded needs to consume:
57 | 
58 |     image width |times| image height |times| 3
59 | 
60 | bytes of RAM, and it needs to be combined with the :ref:`overview_image_caching`
61 | feature to ensure that the memory usage is within a reasonable range.
62 | 
63 | 
64 | 
65 | .. _libjpeg_example:
66 | 
67 | Example
68 | *******
69 | 
70 | .. include:: ../../examples/libs/libjpeg_turbo/index.rst
71 | 
72 | 
73 | 
74 | .. _libjpeg_api:
75 | 
76 | API
77 | ***
78 | 
79 | :ref:`lv_libjpeg_turbo_h`
80 | 
81 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/libpng.rst:
--------------------------------------------------------------------------------
 1 | .. _libpng:
 2 | 
 3 | ==============
 4 | libpng Decoder
 5 | ==============
 6 | 
 7 | **libpng** is an LVGL interface to the the official PNG reference library, which
 8 | supports almost all PNG features, is extensible, and has been extensively tested for
 9 | over 28 years.
10 | 
11 | For a detailed introduction, see:  http://www.libpng.org/pub/png/libpng.html .
12 | 
13 | 
14 | 
15 | Install
16 | *******
17 | 
18 | .. code-block:: bash
19 | 
20 |     sudo apt install libpng-dev
21 | 
22 | 
23 | 
24 | Adding libpng to Your Project
25 | *****************************
26 | 
27 | Cmake:
28 | 
29 | .. code-block:: cmake
30 | 
31 |     find_package(PNG REQUIRED)
32 |     include_directories(${PNG_INCLUDE_DIR})
33 |     target_link_libraries(${PROJECT_NAME} PRIVATE ${PNG_LIBRARIES})
34 | 
35 | 
36 | 
37 | .. _libpng_usage:
38 | 
39 | Usage
40 | *****
41 | 
42 | Set :c:macro:`LV_USE_LIBPNG` in ``lv_conf.h`` to ``1``.
43 | 
44 | See the examples below.
45 | 
46 | .. |times|  unicode:: U+000D7 .. MULTIPLICATION SIGN
47 | 
48 | It should be noted that each image of this decoder needs to consume
49 | 
50 |     width |times| height |times| 4
51 | 
52 | bytes of RAM, and it needs to be combined with the :ref:`overview_image_caching` feature to
53 | ensure that the memory usage is within a reasonable range. The decoded image is
54 | stored in RGBA pixel format.
55 | 
56 | 
57 | 
58 | .. _libpng_example:
59 | 
60 | Example
61 | *******
62 | 
63 | .. include:: ../../examples/libs/libpng/index.rst
64 | 
65 | 
66 | 
67 | .. _libpng_api:
68 | 
69 | API
70 | ***
71 | 
72 | .. API startswith:  lv_libpng_
73 | 
74 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/lodepng.rst:
--------------------------------------------------------------------------------
 1 | .. _lodepng_rst:
 2 | 
 3 | ===============
 4 | LodePNG Decoder
 5 | ===============
 6 | 
 7 | **LodePNG** is an LVGL interface to the LodePNG library --- a PNG encoder and decoder
 8 | in C and C++, without any dependencies, giving you an alternate way to use PNG images
 9 | in your LVGL UI.
10 | 
11 | For a detailed introduction, see:  https://github.com/lvandeve/lodepng .
12 | 
13 | If enabled in ``lv_conf.h`` by setting :c:macro:`LV_USE_LODEPNG` to ``1``, LVGL will
14 | register a new image decoder automatically so PNG files can be used directly as an
15 | image source.
16 | 
17 | .. note::
18 | 
19 |     A file system driver needs to be registered to open images from files.  To do so,
20 |     follow the instructions in :ref:`file_system`.
21 | 
22 | .. |times|  unicode:: U+000D7 .. MULTIPLICATION SIGN
23 | 
24 | The whole PNG image is decoded, so
25 | 
26 |     width |times| height |times| 4
27 | 
28 | bytes of RAM is required from the LVGL heap.  The decoded image is stored in RGBA
29 | pixel format.
30 | 
31 | Since it might take significant time to decode PNG images LVGL's
32 | :ref:`overview_image_caching` feature can be useful.
33 | 
34 | 
35 | 
36 | Compressing PNG Files
37 | *********************
38 | 
39 | PNG file format supports True color (24/32 bit), and 8-bit palette colors.
40 | Usually cliparts, drawings, icons and simple graphics are stored in PNG format,
41 | that do not use the whole color space, so it is possible to compress further
42 | the image by using 8-bit palette colors, instead of 24/32 bit True color format.
43 | Because embedded devices have limited (flash) storage, it is recommended
44 | to compress images.
45 | 
46 | One option is to use a free online PNG compressor site,
47 | for example Compress PNG: https://compresspng.com/
48 | 
49 | 
50 | 
51 | .. _lodepng_example:
52 | 
53 | Example
54 | *******
55 | 
56 | .. include:: ../../examples/libs/lodepng/index.rst
57 | 
58 | 
59 | 
60 | .. _lodepng_api:
61 | 
62 | API
63 | ***
64 | 
65 | .. API startswith:  lv_lodepng_
66 | 
67 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/qrcode.rst:
--------------------------------------------------------------------------------
 1 | .. _qrcode:
 2 | 
 3 | =======
 4 | QR Code
 5 | =======
 6 | 
 7 | The `QR-Code-generator library <https://github.com/nayuki/QR-Code-generator>`__ by
 8 | `nayuki <https://github.com/nayuki>`__ is a 3rd-party library that generates QR-Code
 9 | bitmaps.
10 | 
11 | The lv_qrcode LVGL extension is an interface to that library which implements a custom
12 | Widget that generates and displays QR Codes using the library.
13 | 
14 | 
15 | 
16 | .. _qrcode_usage:
17 | 
18 | Usage
19 | *****
20 | 
21 | Enable :c:macro:`LV_USE_QRCODE` in ``lv_conf.h`` by setting its value to ``1``.
22 | 
23 | Use :cpp:func:`lv_qrcode_create` to create the QR-Code Widget.  Then use
24 | :cpp:func:`lv_qrcode_update` to generate the QR Code on it.
25 | 
26 | If you need to re-modify the size and color, use
27 | :cpp:func:`lv_qrcode_set_size` and :cpp:func:`lv_qrcode_set_dark_color` or
28 | :cpp:func:`lv_qrcode_set_light_color` respectively, and then
29 | call :cpp:func:`lv_qrcode_update` again to update the QR Code.
30 | 
31 | 
32 | 
33 | Notes
34 | *****
35 | 
36 | -  QR Codes with less data are smaller, but they are scaled by an integer
37 |    value to best fit to the given size.
38 | 
39 | 
40 | 
41 | .. _qrcode_example:
42 | 
43 | Example
44 | *******
45 | 
46 | .. include:: ../../examples/libs/qrcode/index.rst
47 | 
48 | 
49 | 
50 | .. _qrcode_api:
51 | 
52 | API
53 | ***
54 | 
55 | .. API startswith:  lv_qrcode_
56 | 
57 | 


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/lvgl/lvgl/master/docs/src/details/libs/rle-compress-statistics.png


--------------------------------------------------------------------------------
/docs/src/details/libs/rle.rst:
--------------------------------------------------------------------------------
  1 | .. _rle:
  2 | 
  3 | =================
  4 | RLE Decompression
  5 | =================
  6 | 
  7 | LVGL provides a custom RLE (Run-Length Encoding) decompression method.  It can be
  8 | used to reduce binary image size.  The RLE compression is a lossless compression
  9 | method.
 10 | 
 11 | The LVGL's built-in binary image decoder supports RLE-compressed images.
 12 | The decoder supports both variable and file as image sources. The original
 13 | binary data is directly decoded to RAM.
 14 | 
 15 | 
 16 | 
 17 | Benefits
 18 | ********
 19 | 
 20 | Most screenshot and UI images (where there are a limited number of colors) can be
 21 | compressed to save more than 70% space.  The below statistics are from a watch
 22 | project.  It shows the file count of every compress level. For rare conditions, RLE
 23 | compress may increase the file size if there's no large repetition in data.
 24 | 
 25 | .. image:: rle-compress-statistics.png
 26 |    :alt: RLE compress statistics from a watch project
 27 |    :align: center
 28 | 
 29 | 
 30 | Theory
 31 | ******
 32 | 
 33 | The RLE algorithm is a simple compression algorithm that is based on the fact that
 34 | for many adjacent pixels, the color is the same.  The algorithm simply counts how
 35 | many repeated pixels with the same color there are, and stores the count value and
 36 | the color value.  If the up-coming pixels are not repeated, it stores the non-repeat
 37 | count value and original color values.  For more details, the script used to compress
 38 | the image can be found from ``lvgl/script/LVGLImage.py``.
 39 | 
 40 | .. code-block:: python
 41 | 
 42 |     def rle_compress(self, data: bytearray, blksize: int, threshold=16):
 43 |         index = 0
 44 |         data_len = len(data)
 45 |         compressed_data = []
 46 |         while index < data_len:
 47 |             memview = memoryview(data)
 48 |             repeat_cnt = self.get_repeat_count(
 49 |                 memview[index:], blksize)
 50 |             if repeat_cnt == 0:
 51 |                 # done
 52 |                 break
 53 |             elif repeat_cnt < threshold:
 54 |                 nonrepeat_cnt = self.get_nonrepeat_count(
 55 |                     memview[index:], blksize, threshold)
 56 |                 ctrl_byte = uint8_t(nonrepeat_cnt | 0x80)
 57 |                 compressed_data.append(ctrl_byte)
 58 |                 compressed_data.append(
 59 |                     memview[index: index + nonrepeat_cnt * blksize])
 60 |                 index += nonrepeat_cnt * blksize
 61 |             else:
 62 |                 ctrl_byte = uint8_t(repeat_cnt)
 63 |                 compressed_data.append(ctrl_byte)
 64 |                 compressed_data.append(memview[index: index + blksize])
 65 |                 index += repeat_cnt * blksize
 66 | 
 67 |         return b"".join(compressed_data)
 68 | 
 69 | 
 70 | 
 71 | .. _rle_usage:
 72 | 
 73 | Usage
 74 | *****
 75 | 
 76 | To use the RLE Decoder, enable it in ``lv_conf.h`` configuration file by setting
 77 | :c:macro:`LV_USE_RLE` to ``1``.  The RLE image can then be used in the same way as
 78 | other images.
 79 | 
 80 | .. code-block:: c
 81 | 
 82 |    lv_image_set_src(img, "path/to/image.rle");
 83 | 
 84 | 
 85 | 
 86 | Generating RLE Compressed Binary Images
 87 | ***************************************
 88 | 
 89 | An RLE image binary can be directly generated from another image using script
 90 | ``lvgl/script/LVGLImage.py``.
 91 | 
 92 | .. code-block:: bash
 93 | 
 94 |    ./scripts/LVGLImage.py --ofmt BIN --cf I8 --compress RLE cogwheel.png
 95 | 
 96 | This will decompress ``cogwheel.png``, and then re-compress it using RLE and write
 97 | the output to ``./output/cogwheel.bin``.
 98 | 
 99 | 
100 | 
101 | API
102 | ***
103 | 
104 | :ref:`lv_rle_h`
105 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/svg.rst:
--------------------------------------------------------------------------------
 1 | .. _svg:
 2 | 
 3 | ===========
 4 | SVG Support
 5 | ===========
 6 | 
 7 | The lv_svg extension provides makes it possible to use SVG images in your LVGL UI using the
 8 | `Scalable Vector Graphics (SVG) Tiny 1.2 Specification <https://www.w3.org/TR/SVGTiny12/>`__.
 9 | 
10 | For a detailed introduction, see:  https://www.w3.org/TR/SVGTiny12/
11 | 
12 | 
13 | 
14 | Usage
15 | *****
16 | 
17 | Enable :c:macro:`LV_USE_SVG` in ``lv_conf.h`` by setting its value to ``1``.
18 | 
19 | See the examples below.
20 | 
21 | If you need support for SVG animation attribute parsing,
22 | you can set :c:macro:`LV_USE_SVG_ANIMATION` in ``lv_conf.h`` to ``1``.
23 | 
24 | 
25 | 
26 | .. _svg_example:
27 | 
28 | Example
29 | *******
30 | 
31 | .. code:: c
32 | 
33 |     lv_svg_node_t * svg_doc;
34 |     const char* svg_data = "<svg><rect x=\"0\" y=\"0\" width=\"100\" height=\"100\"/></svg>";
35 | 
36 |     /* Create an SVG DOM tree */
37 |     svg_doc = lv_svg_load_data(svg_data, svg_len);
38 |     ...
39 | 
40 |     /* Draw SVG image */
41 |     lv_draw_svg(layer, svg_doc);
42 |     ...
43 | 
44 |     /* Release the DOM tree */
45 |     lv_svg_node_delete(svg_doc);
46 | 
47 | `lv_image` also supports SVG images, For example:
48 | 
49 | .. code-block:: c
50 | 
51 |     lv_image_set_src(widget, "S:path/to/example.svg");
52 | 
53 | 
54 | 
55 | .. _svg_api:
56 | 
57 | API
58 | ***
59 | 
60 | .. API equals:  lv_svg_load_data
61 | 
62 | .. API startswith:  lv_svg_
63 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/tiny_ttf.rst:
--------------------------------------------------------------------------------
 1 | .. _tiny_ttf:
 2 | 
 3 | ====================
 4 | Tiny TTF font engine
 5 | ====================
 6 | 
 7 | The lv_tiny_ttf extension allows using TrueType fonts in LVGL using the
 8 | `stb_truetype 3rd-Party Library <https://github.com/nothings/stb>`__.
 9 | 
10 | For a detailed introduction, see:  https://github.com/nothings/stb.
11 | 
12 | 
13 | 
14 | .. _tiny_ttf_usage:
15 | 
16 | Usage
17 | *****
18 | 
19 | When enabled in ``lv_conf.h`` by setting :c:macro:`LV_USE_TINY_TTF` to ``1``,
20 | :cpp:expr:`lv_tiny_ttf_create_data(data, data_size, font_size)` can be used to
21 | create a TTF font instance with the specified line height.  You can then
22 | use that font anywhere :c:struct:`lv_font_t` is accepted.
23 | 
24 | By default, the TTF or OTF file must be embedded as an array, either in
25 | a header, or loaded into RAM in order to function.
26 | 
27 | However, if :c:macro:`LV_TINY_TTF_FILE_SUPPORT` is enabled (i.e. ``1``),
28 | :cpp:expr:`lv_tiny_ttf_create_file(path, font_size)` will also be available,
29 | allowing tiny_ttf to stream from a file. The file must remain open the
30 | entire time the font is being used.
31 | 
32 | After a font is created, you can change the font size in pixels by using
33 | :cpp:expr:`lv_tiny_ttf_set_size(font, font_size)`.
34 | 
35 | By default, a font will cache data for up to 256 glyph elements to speed up rendering.
36 | This maximum can be changed by using
37 | :cpp:expr:`lv_tiny_ttf_create_data_ex(data, data_size, font_size, kerning, cache_size)`
38 | or :cpp:expr:`lv_tiny_ttf_create_file_ex(path, font_size, kerning, cache_size)` (when
39 | available). The cache size is indicated in number of entries.  The ``kerning``
40 | argument will be one of the ``LV_FONT_KERNING_...`` values, indicating whether to
41 | allow kerning, if supported, or disable.
42 | 
43 | 
44 | 
45 | .. _tiny_ttf_example:
46 | 
47 | Example
48 | *******
49 | 
50 | .. include:: ../../examples/libs/tiny_ttf/index.rst
51 | 
52 | 
53 | 
54 | .. _tiny_ttf_api:
55 | 
56 | API
57 | ***
58 | 
59 | .. API startswith:  lv_tiny_ttf_
60 | 
61 | 


--------------------------------------------------------------------------------
/docs/src/details/libs/tjpgd.rst:
--------------------------------------------------------------------------------
 1 | .. _tjpgd:
 2 | 
 3 | ================================
 4 | Tiny JPEG Decompressor (TJpgDec)
 5 | ================================
 6 | 
 7 | **Tiny JPEG Decompressor** is an LVGL interface to the TJpgDec library --- a generic
 8 | JPEG image decompressor module that highly optimized for small embedded systems.  It
 9 | works with very low memory consumption, so that it can be incorporated into tiny
10 | microcontrollers, such as AVR, 8051, PIC, Z80, Cortex-M0, etc..
11 | 
12 | For a detailed introduction, see: `TJpgDec <http://elm-chan.org/fsw/tjpgd/>`__.
13 | 
14 | 
15 | 
16 | .. _tjpgd_overview:
17 | 
18 | Overview
19 | ********
20 | 
21 | Features and restrictions:
22 | 
23 | - JPEG is decoded in 8x8 tiles.
24 | - Only baseline JPEG files are supported (no progressive JPEG support).
25 | - Read from file and C array are implemented.
26 | - Only the required portions of the JPEG images are decoded,
27 |   therefore they cannot be zoomed or rotated.
28 | 
29 | 
30 | 
31 | .. _tjpgd_usage:
32 | 
33 | Usage
34 | *****
35 | 
36 | Set :c:macro:`LV_USE_TJPGD` to ``1`` in ``lv_conf.h``.  LVGL will register a new
37 | image decoder automatically so JPEG files can be used directly as image sources.
38 | 
39 | For example:
40 | 
41 | .. code-block:: c
42 | 
43 |    lv_image_set_src(my_img, "S:path/to/picture.jpg");
44 | 
45 | .. note::
46 | 
47 |     A file system driver needs to be registered to open images from files.  To do so,
48 |     follow the instructions in :ref:`file_system`.
49 | 
50 | 
51 | 
52 | Converter
53 | *********
54 | 
55 | Converting JPEG to C array
56 | --------------------------
57 | 
58 | -  Use lvgl online tool https://lvgl.io/tools/imageconverter
59 | -  Color format = RAW, output format = C Array
60 | 
61 | 
62 | 
63 | .. _tjpgd_example:
64 | 
65 | Example
66 | *******
67 | 
68 | .. include:: ../../examples/libs/tjpgd/index.rst
69 | 
70 | 
71 | 
72 | .. _tjpgd_api:
73 | 
74 | API
75 | ***
76 | 
77 | .. API startswith:  lv_tjpgd_
78 | 
79 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/display_events.rst:
--------------------------------------------------------------------------------
 1 | .. _display_events:
 2 | 
 3 | Events
 4 | ******
 5 | 
 6 | :cpp:expr:`lv_display_add_event_cb(disp, event_cb, LV_EVENT_..., user_data)` adds
 7 | an event handler to a display.
 8 | 
 9 | If you added ``user_data`` to the Display, you can retrieve it in an event like this:
10 | 
11 | .. code-block:: c
12 | 
13 |     lv_display_t * display1;
14 |     my_type_t    * my_user_data;
15 |     display1 = (lv_display_t *)lv_event_get_current_target(e);
16 |     my_user_data = lv_display_get_user_data(display1);
17 | 
18 | The following events are sent for Display (lv_display_t) objects:
19 | 
20 | .. include:: display_events_list.txt
21 | 
22 | 
23 | 
24 | API
25 | ***
26 | 
27 | .. API equals:  lv_display_add_event_cb
28 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/display_events_list.txt:
--------------------------------------------------------------------------------
 1 | ..
 2 |     display_events_list.txt
 3 |     Note:  this is used in full in 2 places currently.  Thus, it is placed
 4 |     here so its source is only in one place and will be fully duplicated
 5 |     where it is used:
 6 |     - display_events.rst
 7 |     - event.rst
 8 | 
 9 | - :cpp:enumerator:`LV_EVENT_INVALIDATE_AREA` An area is invalidated (marked for redraw).
10 |   :cpp:expr:`lv_event_get_param(e)` returns a pointer to an :cpp:struct:`lv_area_t`
11 |   object with the coordinates of the area to be invalidated. The area can
12 |   be freely modified if needed to adapt it a special requirement of the
13 |   display. Usually needed with monochrome displays to invalidate ``N x 8``
14 |   rows or columns in one pass.
15 | - :cpp:enumerator:`LV_EVENT_RESOLUTION_CHANGED`: Sent when the resolution changes due
16 |   to :cpp:func:`lv_display_set_resolution` or :cpp:func:`lv_display_set_rotation`.
17 | - :cpp:enumerator:`LV_EVENT_COLOR_FORMAT_CHANGED`: Sent as a result of any call to `lv_display_set_color_format()`.
18 | - :cpp:enumerator:`LV_EVENT_REFR_REQUEST`: Sent when something happened that requires redraw.
19 | - :cpp:enumerator:`LV_EVENT_REFR_START`: Sent before a refreshing cycle starts. Sent even
20 |   if there is nothing to redraw.
21 | - :cpp:enumerator:`LV_EVENT_REFR_READY`: Sent when refreshing has been completed (after
22 |   rendering and calling :ref:`flush_callback`). Sent even if no redraw happened.
23 | - :cpp:enumerator:`LV_EVENT_RENDER_START`: Sent just before rendering begins.
24 | - :cpp:enumerator:`LV_EVENT_RENDER_READY`: Sent after rendering has been completed (before
25 |   calling :ref:`flush_callback`)
26 | - :cpp:enumerator:`LV_EVENT_FLUSH_START`: Sent before :ref:`flush_callback` is called.
27 | - :cpp:enumerator:`LV_EVENT_FLUSH_FINISH`: Sent after :ref:`flush_callback` call has returned.
28 | - :cpp:enumerator:`LV_EVENT_FLUSH_WAIT_START`: Sent at the beginning of internal call to
29 |   `wait_for_flushing()` -- happens whether or not any waiting will actually occur.
30 |   Call returns immediately if `disp->flushing == 0`.
31 | - :cpp:enumerator:`LV_EVENT_FLUSH_WAIT_FINISH`: Sent when the call to `wait_for_flushing()`
32 |   is about to return, regardless whether any actual waiting occurred.
33 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/extending_combining.rst:
--------------------------------------------------------------------------------
 1 | .. _extending_combining_displays:
 2 | 
 3 | ============================
 4 | Extending/Combining Displays
 5 | ============================
 6 | 
 7 | .. _display_mirroring:
 8 | 
 9 | Mirroring a Display
10 | *******************
11 | 
12 | To mirror the image of a display to another display, you don't need to use
13 | multi-display support. Just transfer the buffer received in the first display's
14 | :ref:`flush_callback` to the other display as well.
15 | 
16 | 
17 | 
18 | .. _display_split_image:
19 | 
20 | Splitting an Image
21 | ******************
22 | 
23 | You can create a larger virtual display from an array of smaller ones.
24 | You can create it by:
25 | 
26 | 1. setting the resolution of the displays to the large display's resolution;
27 | 2. in :ref:`flush_callback`, truncate and modify the ``area`` parameter for each display; and
28 | 3. send the buffer's content to each real display with the truncated area.
29 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/inactivity.rst:
--------------------------------------------------------------------------------
 1 | .. _display_inactivity:
 2 | 
 3 | ======================
 4 | Inactivity Measurement
 5 | ======================
 6 | 
 7 | A user's inactivity time is measured and stored with each ``lv_display_t`` object.
 8 | Every use of an :ref:`Input Device <indev>` (if :ref:`associated with the display
 9 | <indev_other_features>`) counts as an activity.  To get time elapsed since the last
10 | activity, use :cpp:expr:`lv_display_get_inactive_time(display1)`.  If ``NULL`` is
11 | passed, the lowest inactivity time among all displays will be returned (in this case
12 | NULL does *not* mean the :ref:`default_display`).
13 | 
14 | You can manually trigger an activity using
15 | :cpp:expr:`lv_display_trigger_activity(display1)`.  If ``display1`` is ``NULL``, the
16 | :ref:`default_display` will be used (**not all displays**).
17 | 
18 | 
19 | .. admonition::  Further Reading
20 | 
21 |     -  `lv_port_disp_template.c <https://github.com/lvgl/lvgl/blob/master/examples/porting/lv_port_disp_template.c>`__
22 |        for a template for your own driver.
23 |     -  :ref:`Drawing <draw>` to learn more about how rendering works in LVGL.
24 | 
25 | 
26 | 
27 | API
28 | ***
29 | 
30 | .. API equals:  lv_display_get_inactive_time
31 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/index.rst:
--------------------------------------------------------------------------------
 1 | .. _display:
 2 | 
 3 | ====================
 4 | Display (lv_display)
 5 | ====================
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     overview
11 |     setup
12 |     screen_layers
13 |     color_format
14 |     refreshing
15 |     display_events
16 |     resolution
17 |     inactivity
18 |     rotation
19 |     redraw_area
20 |     tiling
21 |     extending_combining
22 | 
23 | 
24 | .. _display_api:
25 | 
26 | API
27 | ***
28 | 
29 | :ref:`lv_display_h`
30 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/overview.rst:
--------------------------------------------------------------------------------
 1 | .. _display_overview:
 2 | 
 3 | ========
 4 | Overview
 5 | ========
 6 | 
 7 | What is a Display?
 8 | ******************
 9 | 
10 | In LVGL, an *lv_display_t* (not to be confused with a :ref:`Screen <screens>`) is a
11 | data type that represents a single display panel --- the hardware that displays
12 | LVGL-rendered pixels on your device.
13 | 
14 | 
15 | 
16 | .. _multiple_displays:
17 | 
18 | How Many Displays Can LVGL Use?
19 | *******************************
20 | 
21 | LVGL can use any number of displays.  It is only limited by available RAM and MCU time.
22 | 
23 | Why would you want multi-display support?  Here are some examples:
24 | 
25 | - Have a "normal" TFT display with local UI and create "virtual" screens on VNC
26 |   on demand. (You need to add your VNC driver.)
27 | - Have a large TFT display and a small monochrome display.
28 | - Have some smaller and simple displays in a large instrument or technology.
29 | - Have two large TFT displays: one for a customer and one for the shop assistant.
30 | 
31 | If you set up LVGL to use more than one display, be aware that some functions use the
32 | :ref:`default_display` during their execution, such as creating :ref:`screens`.
33 | 
34 | 
35 | 
36 | .. _display_attributes:
37 | 
38 | Attributes
39 | **********
40 | 
41 | Once created, a Display object remembers the characteristics of the display hardware
42 | it is representing, as well as other things relevant to its lifetime:
43 | 
44 | - Resolution (width and height in pixels)
45 | - Color Depth (bits per pixel)
46 | - Color Format (how colors in pixels are laid out)
47 | - DPI (default is configured :c:macro:`LV_DPI_DEF` in ``lv_conf.h``, but can be
48 |   modified with :cpp:expr:`lv_display_set_dpi(disp, new_dpi)`).
49 | - 4 :ref:`display_screen_layers` automatically created with each display
50 | - All :ref:`screens` created in association with this display (and not yet deleted---only
51 |   one is displayed at any given time)
52 | - The :ref:`draw_buffers` assigned to it
53 | - The :ref:`flush_callback` function that moves pixels from :ref:`draw_buffers` to Display hardware
54 | - What areas of the display have been updated (made "dirty") so rendering logic can
55 |   compute what to render during a :ref:`display refresh <basic_data_flow>`
56 | - Optional custom pointer as :ref:`display_user_data`
57 | 
58 | 
59 | 
60 | .. _display_user_data:
61 | 
62 | User Data
63 | *********
64 | 
65 | With :cpp:expr:`lv_display_set_user_data(display1, p)` a custom pointer can be stored
66 | with ``lv_display_t`` object.  This pointer can be used later, e.g. in
67 | :ref:`display_events`.   See code example for how to do this in :ref:`display_events`.
68 | 
69 | 
70 | 
71 | API
72 | ***
73 | 
74 | .. API equals:
75 |     lv_display_set_dpi
76 |     lv_display_set_user_data
77 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/redraw_area.rst:
--------------------------------------------------------------------------------
 1 | .. _display_redraw_area:
 2 | 
 3 | ===========================
 4 | Constraints on Redrawn Area
 5 | ===========================
 6 | 
 7 | Some display controllers have specific requirements for the window area where the
 8 | rendered image can be sent (e.g., `x1` must be even, and `x2` must be odd).
 9 | 
10 | In the case of monochrome displays, `x1` must be `Nx8`, and `x2` must be `Nx8 - 1`.
11 | (If the display uses `LV_COLOR_FORMAT_I1`, LVGL automatically applies this rounding.
12 | See :ref:`display_monochrome`.)
13 | 
14 | The size of the invalidated (redrawn) area can be controlled as follows:
15 | 
16 | .. code-block:: c
17 | 
18 |     void rounder_event_cb(lv_event_t * e)
19 |     {
20 |         lv_area_t * a = lv_event_get_invalidated_area(e);
21 | 
22 |         a->x1 = a->x1 & (~0x1); /* Ensure x1 is even */
23 |         a->x2 = a->x2 | 0x1;    /* Ensure x2 is odd */
24 |     }
25 | 
26 |     ...
27 | 
28 |     lv_display_add_event_cb(disp, rounder_event_cb, LV_EVENT_INVALIDATE_AREA, NULL);
29 | 
30 | 
31 | 
32 | API
33 | ***
34 | 
35 | .. API equals:
36 |     lv_event_get_invalidated_area
37 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/refreshing.rst:
--------------------------------------------------------------------------------
 1 | .. _display_refreshing:
 2 | 
 3 | ==========
 4 | Refreshing
 5 | ==========
 6 | 
 7 | Default Refresh Behavior
 8 | ************************
 9 | 
10 | Normally the dirty (a.k.a invalid) areas are checked and redrawn in
11 | every :c:macro:`LV_DEF_REFR_PERIOD` milliseconds (set in ``lv_conf.h``).
12 | This happens as a result of a refresh :ref:`timer` created that gets created when
13 | the display is created, and is executed at that interval.
14 | 
15 | 
16 | 
17 | .. _display_decoupling_refresh_timer:
18 | 
19 | Decoupling the Display Refresh Timer
20 | ************************************
21 | 
22 | However, in some cases you might need more control on when display
23 | refreshing happens, for example:
24 | 
25 | - to synchronize rendering with VSYNC or the TE signal;
26 | 
27 | - to time display refreshes immediately after a single screen update of all widgets
28 |   that needed to have their display data updated (i.e. only updated once immediately
29 |   before display refresh to reduce CPU overhead).
30 | 
31 | You can do this in the following way:
32 | 
33 | .. code-block:: c
34 | 
35 |    /* Delete original display refresh timer */
36 |    lv_display_delete_refr_timer(display1);
37 | 
38 |    /* Call this to refresh dirty (changed) areas of the display. */
39 |    lv_display_refr_timer(NULL);
40 | 
41 | If you have multiple displays call :cpp:expr:`lv_display_set_default(display1)` to
42 | select the display to refresh before :cpp:expr:`lv_display_refr_timer(NULL)`.
43 | 
44 | 
45 | .. note:: :cpp:func:`lv_timer_handler` and :cpp:func:`lv_display_refr_timer` must not run at the same time.
46 | 
47 | 
48 | If the performance monitor is enabled, the value of :c:macro:`LV_DEF_REFR_PERIOD` needs to be set to be
49 | consistent with the refresh period of the display to ensure that the statistical results are correct.
50 | 
51 | 
52 | 
53 | .. _display_force_refresh:
54 | 
55 | Forcing a Refresh
56 | *****************
57 | 
58 | Normally the invalidated areas (marked for redrawing) are rendered in
59 | :cpp:func:`lv_timer_handler` in every :c:macro:`LV_DEF_REFR_PERIOD` milliseconds.
60 | However, by using :cpp:expr:`lv_refr_now(display)` you can tell LVGL to redraw the
61 | invalid areas immediately. The refreshing will happen in :cpp:func:`lv_refr_now`
62 | which might take longer.
63 | 
64 | The parameter of :cpp:func:`lv_refr_now` is a pointer to the display to refresh.  If
65 | ``NULL`` is passed, all displays that have active refresh timers will be refreshed.
66 | 
67 | 
68 | 
69 | API
70 | ***
71 | 
72 | .. API equals:
73 |     LV_DEF_REFR_PERIOD
74 |     lv_display_refr_timer
75 |     lv_display_set_default
76 |     lv_refr_now
77 |     lv_timer_handler
78 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/resolution.rst:
--------------------------------------------------------------------------------
 1 | .. _display_resolution:
 2 | 
 3 | ===================
 4 | Changing Resolution
 5 | ===================
 6 | 
 7 | To set the resolution of the display after creation use
 8 | :cpp:expr:`lv_display_set_resolution(display, hor_res, ver_res)`
 9 | 
10 | It's not mandatory to use the whole display for LVGL, however in some
11 | cases the physical resolution is important. For example the touchpad
12 | still sees the whole resolution and the values needs to be converted to
13 | the active LVGL display area. So the physical resolution and the offset
14 | of the active area can be set with
15 | :cpp:expr:`lv_display_set_physical_resolution(disp, hor_res, ver_res)` and
16 | :cpp:expr:`lv_display_set_offset(disp, x, y)`
17 | 
18 | 
19 | 
20 | API
21 | ***
22 | 
23 | .. API equals:
24 |     lv_display_set_resolution,
25 |     lv_display_set_physical_resolution,
26 |     lv_display_set_offset
27 | 
28 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/screen_layers.rst:
--------------------------------------------------------------------------------
  1 | .. _display_screen_layers:
  2 | 
  3 | =============
  4 | Screen Layers
  5 | =============
  6 | 
  7 | When an ``lv_display_t`` object is created, 4 permanent :ref:`screens` that
  8 | facilitate layering are created and attached to it.
  9 | 
 10 | 1.  Bottom Layer       (below Active Screen, transparent, not scroll-able, but click-able)
 11 | 2.  :ref:`active_screen`
 12 | 3.  Top Layer          (above Active Screen, transparent and neither scroll-able nor click-able)
 13 | 4.  System Layer       (above Top Layer, transparent and neither scroll-able nor click-able)
 14 | 
 15 | 1, 3 and 4 are independent of the :ref:`active_screen` and they will be shown (if
 16 | they contain anything that is visible) regardless of which screen is the
 17 | :ref:`active_screen`.
 18 | 
 19 | .. note::
 20 | 
 21 |     For the bottom layer to be visible, the Active Screen's background has to be
 22 |     at least partially, if not fully, transparent.
 23 | 
 24 | You can get pointers to each of these screens on the :ref:`default_display` by using
 25 | (respectively):
 26 | 
 27 | - :cpp:func:`lv_screen_active`,
 28 | - :cpp:func:`lv_layer_top`,
 29 | - :cpp:func:`lv_layer_sys`, and
 30 | - :cpp:func:`lv_layer_bottom`.
 31 | 
 32 | You can get pointers to each of these screens on a specified display by using
 33 | (respectively):
 34 | 
 35 | - :cpp:expr:`lv_display_get_screen_active(disp)`,
 36 | - :cpp:expr:`lv_display_get_layer_top(disp)`,
 37 | - :cpp:expr:`lv_display_get_layer_sys(disp)`, and
 38 | - :cpp:expr:`lv_display_get_layer_bottom(disp)`.
 39 | 
 40 | To set a Screen you create to be the :ref:`active_screen`, call
 41 | :cpp:func:`lv_screen_load` or :cpp:func:`lv_screen_load_anim`.
 42 | 
 43 | 
 44 | 
 45 | .. _layers_top_and_sys:
 46 | 
 47 | Top and System Layers
 48 | *********************
 49 | 
 50 | LVGL uses the Top Layer and System Layer two empower you to ensure that certain
 51 | :ref:`widgets` are *always* on top of other layers.
 52 | 
 53 | You can add "pop-up windows" to the *Top Layer* freely.  The Top Layer was meant to
 54 | be used to create Widgets that are visible on all Screens shown on a Display.  But,
 55 | the *System Layer* is intended for system-level things (e.g. mouse cursor will be
 56 | placed there with :cpp:func:`lv_indev_set_cursor`).
 57 | 
 58 | These layers work like any other Widget, meaning they have styles, and any kind of
 59 | Widgets can be created in them.
 60 | 
 61 | .. note::
 62 |     While the Top Layer and System Layer are created by their owning :ref:`display`
 63 |     as not scroll-able and not click-able, these behaviors can be overridden the same
 64 |     as any other Widget by using :cpp:expr:`lv_obj_set_scrollbar_mode(scr1, LV_SCROLLBAR_MODE_xxx)`
 65 |     and :cpp:expr:`lv_obj_add_flag(scr1, LV_OBJ_FLAG_CLICKABLE)` respectively.
 66 | 
 67 | If the :cpp:enumerator:`LV_OBJ_FLAG_CLICKABLE` flag is set on the Top Layer, then it will
 68 | absorb all user clicks and acts as a modal Widget.
 69 | 
 70 | .. code-block:: c
 71 | 
 72 |    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
 73 | 
 74 | 
 75 | 
 76 | .. _layers_bottom:
 77 | 
 78 | Bottom Layer
 79 | ************
 80 | 
 81 | Similar to the Top- and System Layers, the Bottom Layer is also the full size of the
 82 | Display, but it is located below the :ref:`active_screen`.  It's visible only if the
 83 | Active Screen's background opacity is < 255.
 84 | 
 85 | 
 86 | .. admonition::  Further Reading
 87 | 
 88 |     :ref:`transparent_screens`.
 89 | 
 90 | 
 91 | 
 92 | API
 93 | ***
 94 | 
 95 | .. API equals:
 96 |     lv_screen_active,
 97 |     lv_layer_top,
 98 |     lv_layer_sys,
 99 |     lv_layer_bottom,
100 |     lv_display_get_screen_active,
101 |     lv_display_get_layer_top,
102 |     lv_display_get_layer_sys,
103 |     lv_display_get_layer_bottom
104 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/display/tiling.rst:
--------------------------------------------------------------------------------
 1 | .. _display_tiling:
 2 | 
 3 | ===============
 4 | Tiled Rendering
 5 | ===============
 6 | 
 7 | When multiple CPU cores are available and a large area needs to be redrawn, LVGL must
 8 | identify independent areas that can be rendered in parallel.
 9 | 
10 | For example, if there are 4 CPU cores, one core can draw the screen's background
11 | while the other 3 must wait until it is finished. If there are 2 buttons on the
12 | screen, those 2 buttons can be rendered in parallel, but 2 cores will still remain
13 | idle.
14 | 
15 | Due to dependencies among different areas, CPU cores cannot always be fully utilized.
16 | 
17 | To address this, LVGL can divide large areas that need to be updated into smaller
18 | tiles. These tiles are independent, making it easier to find areas that can be
19 | rendered concurrently.
20 | 
21 | Specifically, if there are 4 tiles and 4 cores, there will always be an independent
22 | area for each core within one of the tiles.
23 | 
24 | The maximum number of tiles can be set using the function
25 | :cpp:expr:`lv_display_set_tile_cnt(disp, cnt)`. The default value is
26 | :cpp:expr:`LV_DRAW_SW_DRAW_UNIT_CNT` (or 1 if software rendering is not enabled).
27 | 
28 | Small areas are not further divided into smaller tiles because the overhead of
29 | spinning up 4 cores would outweigh the benefits.
30 | 
31 | The ideal tile size is calculated as ``ideal_tile_size = draw_buf_size / tile_cnt``.
32 | For example, in :cpp:enumerator:`LV_DISPLAY_RENDER_MODE_DIRECT` mode on an 800x480
33 | screen, the display buffer is 800x480 = 375k pixels. If there are 4 tiles, the ideal
34 | tile size is approximately 93k pixels. Based on this, core utilization is as follows:
35 | 
36 | - 30k pixels: 1 core
37 | - 90k pixels: 1 core
38 | - 95k pixels: 2 cores (above 93k pixels, 2 cores are used)
39 | - 150k pixels: 2 cores
40 | - 200k pixels: 3 cores (above 186k pixels, 3 cores are used)
41 | - 300k pixels: 4 cores (above 279k pixels, 4 cores are used)
42 | - 375k pixels: 4 cores
43 | 
44 | In :cpp:enumerator:`LV_DISPLAY_RENDER_MODE_DIRECT`, the screen-sized draw buffer is
45 | divided by the tile count to determine the ideal tile sizes. If smaller areas are
46 | refreshed, it may result in fewer cores being used.
47 | 
48 | In :cpp:enumerator:`LV_DISPLAY_RENDER_MODE_FULL`, the maximum number of tiles is
49 | always created when the entire screen is refreshed.
50 | 
51 | In :cpp:enumerator:`LV_DISPLAY_RENDER_MODE_PARTIAL`, the partial buffer is divided
52 | into tiles. For example, if the draw buffer is 1/10th the size of the screen and
53 | there are 2 tiles, then 1/20th + 1/20th of the screen area will be rendered at once.
54 | 
55 | Tiled rendering only affects the rendering process, and the :ref:`flush_callback` is
56 | called once for each invalidated area. Therefore, tiling is not visible from the
57 | flushing point of view.
58 | 
59 | 
60 | 
61 | API
62 | ***
63 | 
64 | .. API equals:  lv_display_set_tile_cnt, LV_DISPLAY_RENDER_MODE_FULL
65 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/draw/draw_api.rst:
--------------------------------------------------------------------------------
 1 | .. _draw_api:
 2 | 
 3 | ========
 4 | Draw API
 5 | ========
 6 | 
 7 | Where to Use the Drawing API
 8 | ****************************
 9 | 
10 | In most cases you use LVGL's Drawing API through the API of Widgets:  by creating
11 | buttons, labels, etc., and setting the their styles, positions, and other properties.
12 | In these cases rendering (drawing) is handled internally and you doen't see the
13 | :ref:`Drawing Pipeline <draw_pipeline>` at all.
14 | 
15 | However there are three places where you can use LVGL's Drawing API directly.
16 | 
17 | 1. **In the draw events of the Widgets**:
18 |    There are event codes which are sent when the Widget needs to render itself:
19 | 
20 |    - :cpp:enumerator:`LV_EVENT_DRAW_MAIN_BEGIN`, :cpp:enumerator:`LV_EVENT_DRAW_MAIN`,
21 |      :cpp:enumerator:`LV_EVENT_DRAW_MAIN_END`:
22 |      Triggered before, during, and after a Widget is drawn, respectively.  Widget
23 |      rendering typically occurs in :cpp:enumerator:`LV_EVENT_DRAW_MAIN`.
24 |    - :cpp:enumerator:`LV_EVENT_DRAW_POST_BEGIN`, :cpp:enumerator:`LV_EVENT_DRAW_POST`,
25 |      :cpp:enumerator:`LV_EVENT_DRAW_POST_END`:
26 |      Triggered before, during, and after all child Widgets are rendered, respectively.
27 |      This can be useful for overlay-like drawings, such as scrollbars which should be
28 |      rendered on top of any children.
29 | 
30 |    These are relevant if a new Widget is implemented and it uses custom drawing.
31 | 
32 | 2. **Modifying the created draw tasks**:
33 |    The when a draw task is created for a Widget :cpp:enumerator:`LV_EVENT_DRAW_TASK_ADDED`
34 |    is sent.  In this event the created draw task can be modified or new draw tasks
35 |    can be added.  Typical use cases for this are modifying each bar of a bar chart,
36 |    or cells of a table.
37 | 
38 |    For performance reasons, this event is disabled by default.  Enable it by setting
39 |    the :cpp:enumerator:`LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS` flag on the Widget(s) you
40 |    wish to emit this event.
41 | 
42 | 3. **Draw to the Canvas Widget**:
43 |    The drawing functions can be used directly to draw to a Canvas Widget.  Doing so
44 |    renders custom drawing to a buffer which can be used later as an image or a mask.
45 | 
46 |    For more information see :ref:`lv_canvas`.
47 | 
48 | 
49 | 
50 | Drawing API
51 | ***********
52 | 
53 | The main components of LVGL's Drawing API are the :cpp:func:`lv_draw_rect`,
54 | :cpp:func:`lv_draw_label`, :cpp:func:`lv_draw_image`, and similar functions.
55 | When they are called :cpp:type:`lv_draw_task_t` objects are created internally.
56 | 
57 | These functions have the following parameters:
58 | 
59 | - **Layer**:  This is the target of the drawing.  See details at :ref:`draw_layers`.
60 | - **Draw Descriptor**:  This is a large ``struct`` containing all the information
61 |   about the drawing.  See details of the draw descriptors at :ref:`draw_descriptors`.
62 | - **Area** (in some cases):  Specifies where to draw.
63 | 
64 | 
65 | 
66 | Coordinate System
67 | *****************
68 | 
69 | Some functions and draw descriptors require area or point parameters.  These are
70 | always **absolute coordinates** on the display.  For example, if the target layer is
71 | on a 800x480 display and the layer's area is (100,100) (200,200), to render a 10x10
72 | object in the middle, the coordinates (145,145) (154,154) should be used
73 | (not (40,40) (49,49)).
74 | 
75 | Exception:  for the Canvas Widget the layer is always assumed to be at the (0,0)
76 | coordinate, regardless of the Canvas Widget's position.
77 | 
78 | 
79 | 
80 | API
81 | ***
82 | 
83 | .. API equals:
84 |     LV_EVENT_DRAW_MAIN_BEGIN
85 |     lv_draw_arc
86 |     lv_draw_image
87 |     lv_draw_label
88 |     lv_draw_line
89 |     lv_draw_mask_rect
90 |     lv_draw_triangle
91 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/draw/index.rst:
--------------------------------------------------------------------------------
 1 | .. _draw:
 2 | 
 3 | =======
 4 | Drawing
 5 | =======
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     draw_pipeline
11 |     draw_api
12 |     draw_layers
13 |     draw_descriptors
14 | 


--------------------------------------------------------------------------------
/docs/src/details/main-modules/index.rst:
--------------------------------------------------------------------------------
 1 | .. _main_modules:
 2 | 
 3 | ============
 4 | Main Modules
 5 | ============
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 2
 9 | 
10 |     display/index
11 |     indev
12 |     color
13 |     font
14 |     image
15 |     timer
16 |     animation
17 |     fs
18 |     draw/index
19 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/3dtexture.rst:
--------------------------------------------------------------------------------
 1 | .. _lv_3dtexture:
 2 | 
 3 | =========================
 4 | 3D Texture (lv_3dtexture)
 5 | =========================
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | 3D texture widgets are used to embed an external 3D graphics library's "texture" primitive
11 | into an LVGL UI.
12 | 
13 | 
14 | .. _lv_3dtexture_parts_and_styles:
15 | 
16 | Parts and Styles
17 | ****************
18 | 
19 | The size should be set to the actual size of the texture primitive.
20 | The opacity may also be changed.
21 | 
22 | 
23 | .. _lv_3dtexture_usage:
24 | 
25 | Usage
26 | *****
27 | 
28 | Requires a draw unit to be enabled which can draw the
29 | :cpp:enumerator:`LV_DRAW_TASK_TYPE_3D` draw task type.
30 | 
31 | OpenGL is the first supported 3D graphics back-end. The following must be enabled.
32 | 
33 | - :c:macro:`LV_USE_3DTEXTURE`
34 | - :c:macro:`LV_USE_OPENGLES`
35 | - :c:macro:`LV_USE_DRAW_OPENGLES`
36 | 
37 | See :ref:`LVGL's OpenGLES driver docs <opengl_es_driver>` to create a window and a
38 | display texture.
39 | 
40 | The `lv_example_3dtexture <https://github.com/lvgl/lv_example_3dtexture>` repository is a
41 | demonstration of how to use the ``3dtexture`` widget to load glTF models with OpenGL
42 | and display them in LVGL.
43 | 
44 | .. code-block:: c
45 | 
46 |     lv_obj_t * tex = lv_3dtexture_create(parent);
47 |     /* Render something to the texture. You can replace it with your code. */
48 |     lv_3dtexture_id_t gltf_texture = render_gltf_model_to_opengl_texture(path, w, h, color);
49 |     lv_3dtexture_set_src(tex, gltf_texture);
50 |     lv_obj_set_size(tex, w, h);
51 |     lv_obj_set_style_opa(tex, opa, 0);
52 | 
53 | The real type of :cpp:type:`lv_3dtexture_id_t` depends on the active 3D graphics back-end.
54 | With OpenGL, the type is ``unsigned int``.
55 | 
56 | 
57 | .. _lv_3dtexture_events:
58 | 
59 | Events
60 | ******
61 | 
62 | 3D Texture has no special event handling.
63 | 
64 | 
65 | .. _lv_3dtexture_example:
66 | 
67 | Example
68 | *******
69 | 
70 | See the `lv_example_3dtexture <https://github.com/lvgl/lv_example_3dtexture>` repo.
71 | 
72 | 
73 | .. _lv_3dtexture_api:
74 | 
75 | API
76 | ***
77 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/animimg.rst:
--------------------------------------------------------------------------------
 1 | .. _lv_animimg:
 2 | 
 3 | ============================
 4 | Animation Image (lv_animimg)
 5 | ============================
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | The animation image is similar to the normal 'Image' Widget. The only
11 | difference is that instead of one source image, you set an array of
12 | multiple source images that supply "frames" in an animation.
13 | 
14 | You can specify a duration and repeat count.
15 | 
16 | .. _lv_animimg_parts_and_styles:
17 | 
18 | Parts and Styles
19 | ****************
20 | 
21 | -  :cpp:enumerator:`LV_PART_MAIN` A background rectangle that uses the :ref:`typical
22 |    background style properties <typical bg props>` and the image itself using the image
23 |    style properties.
24 | 
25 | .. _lv_animimg_usage:
26 | 
27 | Usage
28 | *****
29 | 
30 | Image sources
31 | -------------
32 | 
33 | To set the image animation images sources, use
34 | :cpp:expr:`lv_animimg_set_src(animimg, dsc[], num)`.
35 | 
36 | To set the images source for flip playback of animation image, use
37 | :cpp:expr:`lv_animimg_set_src_reverse(animimg, dsc[], num)`.
38 | 
39 | Using the inner animation
40 | -------------------------
41 | 
42 | For more advanced use cases, the animation used internally by the image can be
43 | retrieved using :cpp:expr:`lv_animimg_get_anim(animimg)`.  Using this, you can
44 | use the :ref:`Animation <animation>` functions, for example, to
45 | override the animation values using the
46 | :cpp:expr:`lv_anim_set_values(anim, start, end)` or to set a callback
47 | on the animation completed event.
48 | 
49 | 
50 | 
51 | .. _lv_animimg_events:
52 | 
53 | Events
54 | ******
55 | 
56 | No special events are sent by Animation-Image Widgets.
57 | 
58 | .. admonition::  Further Reading
59 | 
60 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
61 | 
62 |     Learn more about :ref:`events`.
63 | 
64 | 
65 | 
66 | .. _lv_animimg_keys:
67 | 
68 | Keys
69 | ****
70 | 
71 | No *Keys* are processed by Animation-Image Widgets.
72 | 
73 | .. admonition::  Further Reading
74 | 
75 |     Learn more about :ref:`indev_keys`.
76 | 
77 | 
78 | 
79 | .. _lv_animimg_example:
80 | 
81 | Example
82 | *******
83 | 
84 | .. include:: ../../examples/widgets/animimg/index.rst
85 | 
86 | 
87 | 
88 | .. _lv_animimg_api:
89 | 
90 | API
91 | ***
92 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/bar.rst:
--------------------------------------------------------------------------------
  1 | .. _lv_bar:
  2 | 
  3 | ============
  4 | Bar (lv_bar)
  5 | ============
  6 | 
  7 | 
  8 | Overview
  9 | ********
 10 | 
 11 | The Bar Widget has a background and an indicator. The length of the
 12 | indicator against the background indicates the Bar's current value.
 13 | 
 14 | Both the start and end values of the Bar can be set.  Changing the start value to a
 15 | value other than the minimum value in its range changes the start position of the indicator.
 16 | 
 17 | 
 18 | 
 19 | .. _lv_bar_parts_and_styles:
 20 | 
 21 | Parts and Styles
 22 | ****************
 23 | 
 24 | -  :cpp:enumerator:`LV_PART_MAIN` The Bar's background.  It uses the :ref:`typical
 25 |    background style properties <typical bg props>`. Adding padding makes the indicator
 26 |    smaller or larger. The ``anim_time`` style property sets the
 27 |    animation time if the values set with :cpp:enumerator:`LV_ANIM_ON`.
 28 | -  :cpp:enumerator:`LV_PART_INDICATOR` The Bar's indicator; also uses the :ref:`typical
 29 |    background style properties <typical bg props>`.
 30 | 
 31 | .. _lv_bar_usage:
 32 | 
 33 | Usage
 34 | *****
 35 | 
 36 | 
 37 | Orientation and size
 38 | --------------------
 39 | 
 40 | - for orientation, width and height, simply set width and height style properties;
 41 | - :cpp:expr:`lv_bar_set_orientation(bar, orientation)` to override orientation
 42 |   caused by ``width`` and ``height``.  Valid values for ``orientation`` are:
 43 | 
 44 |   - :cpp:enumerator:`LV_BAR_ORIENTATION_AUTO`
 45 |   - :cpp:enumerator:`LV_BAR_ORIENTATION_HORIZONTAL`
 46 |   - :cpp:enumerator:`LV_BAR_ORIENTATION_VERTICAL`
 47 | 
 48 | 
 49 | Value and range
 50 | ---------------
 51 | 
 52 | A new value can be set with
 53 | :cpp:expr:`lv_bar_set_value(bar, new_value, LV_ANIM_ON/OFF)`. The value is
 54 | interpreted in a range (minimum and maximum values) which can be
 55 | modified with :cpp:expr:`lv_bar_set_range(bar, min, max)`. The default range is
 56 | 0..100, and the default drawing direction is from left to right in horizontal mode and
 57 | bottom to top in vertical mode. If the minimum value is greater than the maximum value, like
 58 | 100..0, the drawing direction is reversed.
 59 | 
 60 | The new value in :cpp:func:`lv_bar_set_value` can be set with or without an
 61 | animation depending on the last parameter (``LV_ANIM_ON/OFF``).
 62 | 
 63 | 
 64 | Modes
 65 | -----
 66 | 
 67 | The Bar can be one of the following modes:
 68 | 
 69 | - :cpp:enumerator:`LV_BAR_MODE_NORMAL` A normal Bar as described above
 70 | - :cpp:enumerator:`LV_BAR_MODE_SYMMETRICAL` Draws indicator from zero value to current value. Requires a negative
 71 |   minimum value and positive maximum value, e.g. [-100..100].
 72 | - :cpp:enumerator:`LV_BAR_MODE_RANGE` Allows setting the start value as well with
 73 |   :cpp:expr:`lv_bar_set_start_value(bar, new_value, LV_ANIM_ON/OFF)`. The start
 74 |   value must be smaller than the end value.
 75 | 
 76 | 
 77 | 
 78 | .. _lv_bar_events:
 79 | 
 80 | Events
 81 | ******
 82 | 
 83 | No special events are sent by Bar Widgets.
 84 | 
 85 | .. admonition::  Further Reading
 86 | 
 87 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
 88 | 
 89 |     Learn more about :ref:`events`.
 90 | 
 91 | 
 92 | 
 93 | .. _lv_bar_keys:
 94 | 
 95 | Keys
 96 | ****
 97 | 
 98 | No *Keys* are processed by Bar Widgets.
 99 | 
100 | .. admonition::  Further Reading
101 | 
102 |     Learn more about :ref:`indev_keys`.
103 | 
104 | 
105 | 
106 | .. _lv_bar_example:
107 | 
108 | Example
109 | *******
110 | 
111 | .. include:: ../../examples/widgets/bar/index.rst
112 | 
113 | 
114 | 
115 | .. _lv_bar_api:
116 | 
117 | API
118 | ***
119 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/base_widget.rst:
--------------------------------------------------------------------------------
 1 | .. _base_widget:
 2 | .. _lv_obj:
 3 | 
 4 | ====================
 5 | Base Widget (lv_obj)
 6 | ====================
 7 | 
 8 | The most fundamental of all Widgets is the Base Widget, on which all other widgets
 9 | are based.  From an Object-Oriented perspective, think of the Base Widget as the
10 | Widget class from which all other Widgets inherit.
11 | 
12 | By this mechanisms, all Widgets carry :ref:`the features of the Base Widget
13 | <common_widget_features>`.  Therefore, the functions and functionalities of the Base
14 | Widget can be used with other widgets as well.  For example
15 | :cpp:expr:`lv_obj_set_width(slider, 100)`.
16 | 
17 | The Base Widget can be used directly as a simple widget.  While it is a simple
18 | rectangle, it has a large number of features shared with all Widgets, detailed
19 | in :ref:`common_widget_features`.  In HTML terms, think of it as a ``<div>``.
20 | 
21 | 
22 | 
23 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/button.rst:
--------------------------------------------------------------------------------
 1 | .. _lv_button:
 2 | 
 3 | ==================
 4 | Button (lv_button)
 5 | ==================
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | Buttons have no new features compared to the :ref:`base_widget`.
11 | They are useful for semantic purposes and have slightly different default settings.
12 | 
13 | Buttons, by default, differ from Base Widget in the following ways:
14 | 
15 | - Not scrollable
16 | - Added to the default group
17 | - Default height and width set to :cpp:enumerator:`LV_SIZE_CONTENT`
18 | 
19 | .. _lv_button_parts_and_styles:
20 | 
21 | Parts and Styles
22 | ****************
23 | 
24 | -  :cpp:enumerator:`LV_PART_MAIN` The background of the button; uses the :ref:`typical
25 |    background style properties <typical bg props>`.
26 | 
27 | .. _lv_button_usage:
28 | 
29 | Usage
30 | *****
31 | 
32 | There are no new features compared to :ref:`Base Widget <base_widget>`.
33 | 
34 | 
35 | 
36 | .. _lv_button_events:
37 | 
38 | Events
39 | ******
40 | 
41 | -  :cpp:enumerator:`LV_EVENT_VALUE_CHANGED` when the :cpp:enumerator:`LV_OBJ_FLAG_CHECKABLE` flag is
42 |    enabled and the Widget is clicked. The event happens on transition
43 |    to/from the checked state.
44 | 
45 | .. admonition::  Further Reading
46 | 
47 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
48 | 
49 |     Learn more about :ref:`events`.
50 | 
51 | 
52 | 
53 | .. _lv_button_keys:
54 | 
55 | Keys
56 | ****
57 | 
58 | Note that the state of :cpp:enumerator:`LV_KEY_ENTER` is translated to
59 | :cpp:enumerator:`LV_EVENT_PRESSED`, :cpp:enumerator:`LV_EVENT_PRESSING`
60 | and :cpp:enumerator:`LV_EVENT_RELEASED` etc.
61 | 
62 | .. admonition::  Further Reading
63 | 
64 |     Learn more about :ref:`indev_keys`.
65 | 
66 | 
67 | 
68 | .. _lv_button_example:
69 | 
70 | Example
71 | *******
72 | 
73 | .. include:: ../../examples/widgets/button/index.rst
74 | 
75 | 
76 | 
77 | .. _lv_button_api:
78 | 
79 | API
80 | ***
81 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/checkbox.rst:
--------------------------------------------------------------------------------
  1 | .. _lv_checkbox:
  2 | 
  3 | ======================
  4 | Checkbox (lv_checkbox)
  5 | ======================
  6 | 
  7 | Overview
  8 | ********
  9 | 
 10 | The Checkbox Widget is created from a "tick box" and a label. When the
 11 | Checkbox is clicked the tick box is toggled.
 12 | 
 13 | 
 14 | .. _lv_checkbox_parts_and_styles:
 15 | 
 16 | Parts and Styles
 17 | ****************
 18 | 
 19 | -  :cpp:enumerator:`LV_PART_MAIN` Background of Checkbox and it uses
 20 |    the text and the :ref:`typical background style properties <typical bg props>`.
 21 |    ``pad_column`` adjusts spacing between tickbox and label
 22 | -  :cpp:enumerator:`LV_PART_INDICATOR` The "tick box" is a square that uses the
 23 |    :ref:`typical background style properties <typical bg props>`.  By default, its
 24 |    size is equal to the height of the main part's font. Padding properties make the
 25 |    tick box larger in the respective directions.
 26 | 
 27 | The Checkbox is added to the default group (if one is set).
 28 | 
 29 | 
 30 | .. _lv_checkbox_usage:
 31 | 
 32 | Usage
 33 | *****
 34 | 
 35 | Text
 36 | ----
 37 | 
 38 | The text can be modified with
 39 | :cpp:expr:`lv_checkbox_set_text(cb, "New text")` and will be
 40 | dynamically allocated.
 41 | 
 42 | To set static text, use :cpp:expr:`lv_checkbox_set_text_static(cb, txt)`. This
 43 | way, only a pointer to ``txt`` will be stored.  The provided text buffer must remain
 44 | available for the life of the Checkbox.
 45 | 
 46 | Check, uncheck, disable
 47 | -----------------------
 48 | 
 49 | You can programmatically check, un-check, and disable the Checkbox by using the
 50 | common state add/clear function:
 51 | 
 52 | .. code-block:: c
 53 | 
 54 |    lv_obj_add_state(cb, LV_STATE_CHECKED);    /* Make Checkbox checked */
 55 |    lv_obj_remove_state(cb, LV_STATE_CHECKED); /* Make Checkbox unchecked */
 56 |    lv_obj_add_state(cb, LV_STATE_CHECKED | LV_STATE_DISABLED); /* Make Checkbox checked and disabled */
 57 | 
 58 | To find out whether the Checkbox is checked use
 59 | :cpp:expr:`lv_obj_has_state(cb, LV_STATE_CHECKED)`.
 60 | 
 61 | 
 62 | 
 63 | .. _lv_checkbox_events:
 64 | 
 65 | Events
 66 | ******
 67 | 
 68 | -  :cpp:enumerator:`LV_EVENT_VALUE_CHANGED` Sent when Checkbox is toggled.
 69 | 
 70 | .. admonition::  Further Reading
 71 | 
 72 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
 73 | 
 74 |     Learn more about :ref:`events`.
 75 | 
 76 | 
 77 | 
 78 | .. _lv_checkbox_keys:
 79 | 
 80 | Keys
 81 | ****
 82 | 
 83 | The following *Keys* are processed by Checkbox:
 84 | 
 85 | - ``LV_KEY_RIGHT/UP`` Go to CHECKED state if Checkbox is enabled
 86 | - ``LV_KEY_LEFT/DOWN`` Go to non-CHECKED state if Checkbox is enabled
 87 | - :cpp:enumerator:`LV_KEY_ENTER` Clicks the Checkbox and toggles its value.
 88 | 
 89 | Note that, as usual, the state of :cpp:enumerator:`LV_KEY_ENTER` is translated to
 90 | ``LV_EVENT_PRESSED/PRESSING/RELEASED`` etc.
 91 | 
 92 | .. admonition::  Further Reading
 93 | 
 94 |     Learn more about :ref:`indev_keys`.
 95 | 
 96 | 
 97 | 
 98 | .. _lv_checkbox_example:
 99 | 
100 | Example
101 | *******
102 | 
103 | .. include:: ../../examples/widgets/checkbox/index.rst
104 | 
105 | 
106 | 
107 | .. _lv_checkboxapi:
108 | 
109 | API
110 | ***
111 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/index.rst:
--------------------------------------------------------------------------------
 1 | .. _widgets:
 2 | 
 3 | ===========
 4 | All Widgets
 5 | ===========
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 1
 9 | 
10 |     base_widget
11 | 
12 | |hr_left_250|
13 | 
14 | .. toctree::
15 |     :maxdepth: 1
16 | 
17 |     3dtexture
18 |     animimg
19 |     arc
20 |     arclabel
21 |     bar
22 |     button
23 |     buttonmatrix
24 |     calendar
25 |     canvas
26 |     chart
27 |     checkbox
28 |     dropdown
29 |     image
30 |     imagebutton
31 |     keyboard
32 |     label
33 |     led
34 |     line
35 |     list
36 |     lottie
37 |     menu
38 |     msgbox
39 |     roller
40 |     scale
41 |     slider
42 |     spangroup
43 |     spinbox
44 |     spinner
45 |     switch
46 |     table
47 |     tabview
48 |     textarea
49 |     tileview
50 |     win
51 |     new_widget
52 | 
53 | .. |hr_left_250|  raw:: html
54 | 
55 |     <hr />
56 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/led.rst:
--------------------------------------------------------------------------------
 1 | .. _lv_led:
 2 | 
 3 | ============
 4 | LED (lv_led)
 5 | ============
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | LEDs are rectangle-like (or circle) Widgets whose brightness can be
11 | adjusted. With lower brightness the color of the LED becomes darker.
12 | 
13 | .. _lv_led_parts_and_styles:
14 | 
15 | Parts and Styles
16 | ****************
17 | 
18 | - :cpp:enumerator:`LV_LED_PART_MAIN` uses the :ref:`typical background style
19 |   properties <typical bg props>`.
20 | 
21 | .. _lv_led_usage:
22 | 
23 | Usage
24 | *****
25 | 
26 | Color
27 | -----
28 | 
29 | You set the color of the LED with
30 | :cpp:expr:`lv_led_set_color(led, lv_color_hex(0xff0080))`. This will be used as its
31 | background color, border color, and shadow color.
32 | 
33 | Brightness
34 | ----------
35 | 
36 | You can set their brightness with :cpp:expr:`lv_led_set_brightness(led, brightness)`.
37 | The ``brightness`` value should be in the range 0 (darkest) to 255 (lightest).
38 | 
39 | Toggle
40 | ------
41 | 
42 | Use :cpp:expr:`lv_led_on(led)` and :cpp:expr:`lv_led_off(led)` to set the brightness to
43 | a predefined ON or OFF value. The :cpp:expr:`lv_led_toggle(led)` toggles between
44 | the ON and OFF state.
45 | 
46 | You can set custom LED ON and OFF brightness values by defining macros
47 | ``LV_LED_BRIGHT_MAX`` and ``LV_LED_BRIGHT_MIN`` in your project.  Their default
48 | values are 80 and 255. These too must be in the range [0..255].
49 | 
50 | 
51 | 
52 | .. _lv_led_events:
53 | 
54 | Events
55 | ******
56 | 
57 | No special events are sent by LED Widgets.
58 | 
59 | .. admonition::  Further Reading
60 | 
61 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
62 | 
63 |     Learn more about :ref:`events`.
64 | 
65 | 
66 | 
67 | .. _lv_led_keys:
68 | 
69 | Keys
70 | ****
71 | 
72 | No *Keys* are processed by LED Widgets.
73 | 
74 | .. admonition::  Further Reading
75 | 
76 |     Learn more about :ref:`indev_keys`.
77 | 
78 | 
79 | 
80 | .. _lv_led_example:
81 | 
82 | Example
83 | *******
84 | 
85 | .. include:: ../../examples/widgets/led/index.rst
86 | 
87 | 
88 | 
89 | .. _lv_led_api:
90 | 
91 | API
92 | ***
93 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/line.rst:
--------------------------------------------------------------------------------
 1 | .. _lv_line:
 2 | 
 3 | ==============
 4 | Line (lv_line)
 5 | ==============
 6 | 
 7 | Overview
 8 | ********
 9 | 
10 | The Line Widget is capable of drawing straight lines between a set of
11 | points.
12 | 
13 | .. _lv_line_parts_and_styles:
14 | 
15 | Parts and Styles
16 | ****************
17 | 
18 | -  :cpp:enumerator:`LV_PART_MAIN` uses the :ref:`typical background <typical bg props>`
19 |    and line style properties.
20 | 
21 | .. _lv_line_usage:
22 | 
23 | Usage
24 | *****
25 | 
26 | Set points
27 | ----------
28 | 
29 | A Line's points have to be stored in an :cpp:struct:`lv_point_precise_t` array and passed to
30 | the Widget by the :cpp:expr:`lv_line_set_points(lines, point_array, point_cnt)`
31 | function.
32 | 
33 | Their coordinates can either be specified as raw pixel coordinates
34 | (e.g. ``{5, 10}``), or as a percentage of the Line's bounding box using
35 | :cpp:expr:`lv_pct(x)`. In the latter case, the Line's width/height may need to
36 | be set explicitly using :cpp:func:`lv_obj_set_width` and :cpp:func:`lv_obj_set_height`,
37 | as percentage values do not automatically expand the bounding box.
38 | 
39 | Auto-size
40 | ---------
41 | 
42 | By default, the Line's width and height are set to :c:macro:`LV_SIZE_CONTENT`.
43 | This means it will automatically set its size to fit all the points. If
44 | the size is set explicitly, parts on the Line may not be visible.
45 | 
46 | Invert y
47 | --------
48 | 
49 | By default, the *y == 0* point is in the top of the Widget. It might be
50 | counter-intuitive in some cases so the y coordinates can be inverted
51 | with :cpp:expr:`lv_line_set_y_invert(line, true)`. In this case, *y == 0* will
52 | be at the bottom of the Widget. *y invert* is disabled by default.
53 | 
54 | 
55 | 
56 | .. _lv_line_events:
57 | 
58 | Events
59 | ******
60 | 
61 | Only :ref:`generic events <events>` are sent by Line Widgets.
62 | 
63 | .. admonition::  Further Reading
64 | 
65 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
66 | 
67 |     Learn more about :ref:`events`.
68 | 
69 | 
70 | 
71 | .. _lv_line_keys:
72 | 
73 | Keys
74 | ****
75 | 
76 | No *Keys* are processed by Line Widgets.
77 | 
78 | .. admonition::  Further Reading
79 | 
80 |     Learn more about :ref:`indev_keys`.
81 | 
82 | 
83 | 
84 | .. _lv_line_example:
85 | 
86 | Example
87 | *******
88 | 
89 | .. include:: ../../examples/widgets/line/index.rst
90 | 
91 | 
92 | 
93 | .. _lv_line_api:
94 | 
95 | API
96 | ***
97 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/list.rst:
--------------------------------------------------------------------------------
 1 | .. _lv_list:
 2 | 
 3 | ==============
 4 | List (lv_list)
 5 | ==============
 6 | 
 7 | 
 8 | Overview
 9 | ********
10 | 
11 | The List Widget is basically a rectangle with vertical layout to which Buttons
12 | and Text can be added.
13 | 
14 | 
15 | .. _lv_list_parts_and_styles:
16 | 
17 | Parts and Styles
18 | ****************
19 | 
20 | **Background**
21 | 
22 | - :cpp:enumerator:`LV_PART_MAIN` The main part of the List that uses the
23 |   :ref:`typical background style properties <typical bg props>`.
24 | - :cpp:enumerator:`LV_PART_SCROLLBAR` The scrollbar. See :ref:`base_widget`
25 |   documentation for details.
26 | 
27 | **Buttons and Text**
28 | 
29 | - See the :ref:`Button <lv_button>`'s and :ref:`Label <lv_label>`'s documentation.
30 | 
31 | 
32 | .. _lv_list_usage:
33 | 
34 | Usage
35 | *****
36 | 
37 | Buttons
38 | -------
39 | 
40 | :cpp:expr:`lv_list_add_button(list, icon, text)` adds a full-width button with an icon
41 | (that can be an image or symbol) and text.  This function returns a pointer to the
42 | button created, which you can use to, for example, add an event call-back.
43 | 
44 | The text is scrolled horizontally if it is longer than the button.
45 | 
46 | Text
47 | ----
48 | 
49 | :cpp:expr:`lv_list_add_text(list, text)` adds a text string.  This function returns a
50 | pointer to the label created, which you can use to, for example, change its text
51 | with one of the ``lv_label_set_text...()`` functions.
52 | 
53 | 
54 | 
55 | .. _lv_list_events:
56 | 
57 | Events
58 | ******
59 | 
60 | No special events are sent by List Widgets, but events can be sent by Buttons as usual.
61 | 
62 | .. admonition::  Further Reading
63 | 
64 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
65 | 
66 |     Learn more about :ref:`events`.
67 | 
68 | 
69 | 
70 | .. _lv_list_keys:
71 | 
72 | Keys
73 | ****
74 | 
75 | No *Keys* are processed by List Widgets.
76 | 
77 | .. admonition::  Further Reading
78 | 
79 |     Learn more about :ref:`indev_keys`.
80 | 
81 | 
82 | 
83 | .. _lv_list_example:
84 | 
85 | Example
86 | *******
87 | 
88 | .. include:: ../../examples/widgets/list/index.rst
89 | 
90 | 
91 | 
92 | .. _lv_list_api:
93 | 
94 | API
95 | ***
96 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/new_widget.rst:
--------------------------------------------------------------------------------
1 | .. _new_widget:
2 | 
3 | ==========
4 | New Widget
5 | ==========
6 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/spinner.rst:
--------------------------------------------------------------------------------
 1 | .. _lv_spinner:
 2 | 
 3 | ====================
 4 | Spinner (lv_spinner)
 5 | ====================
 6 | 
 7 | 
 8 | Overview
 9 | ********
10 | 
11 | The Spinner Widget is a spinning arc over a ring, typically used to show some type of
12 | activity is in progress.
13 | 
14 | 
15 | 
16 | .. _lv_spinner_parts_and_styles:
17 | 
18 | Parts and Styles
19 | ****************
20 | 
21 | Spinner's parts are identical to those of :ref:`Arc <lv_arc_parts_and_styles>`.
22 | 
23 | 
24 | 
25 | .. _lv_spinner_usage:
26 | 
27 | Usage
28 | *****
29 | 
30 | Create a spinner
31 | ----------------
32 | 
33 | To create a spinner use
34 | :cpp:expr:`lv_spinner_create(parent)`.
35 | 
36 | Use :cpp:expr:`lv_spinner_set_anim_params(spinner, spin_duration, angle)` to
37 | customize the duration of one revolution and the length of the arc.
38 | 
39 | 
40 | 
41 | .. _lv_spinner_events:
42 | 
43 | Events
44 | ******
45 | 
46 | No special events are sent by Spinner Widgets.
47 | 
48 | .. admonition::  Further Reading
49 | 
50 |     :ref:`Arc Events <lv_arc_events>`
51 | 
52 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
53 | 
54 |     Learn more about :ref:`events`.
55 | 
56 | 
57 | 
58 | .. _lv_spinner_keys:
59 | 
60 | Keys
61 | ****
62 | 
63 | No *Keys* are processed by Spinner Widgets.
64 | 
65 | .. admonition::  Further Reading
66 | 
67 |     Learn more about :ref:`indev_keys`.
68 | 
69 | 
70 | 
71 | .. _lv_spinner_example:
72 | 
73 | Example
74 | *******
75 | 
76 | .. include:: ../../examples/widgets/spinner/index.rst
77 | 
78 | 
79 | 
80 | .. _lv_spinner_api:
81 | 
82 | API
83 | ***
84 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/switch.rst:
--------------------------------------------------------------------------------
  1 | .. _lv_switch:
  2 | 
  3 | ==================
  4 | Switch (lv_switch)
  5 | ==================
  6 | 
  7 | 
  8 | Overview
  9 | ********
 10 | 
 11 | Switch Widgets look like little sliders and are used to display, and optionally
 12 | modify, a value that can be "on" or "off".
 13 | 
 14 | By default, a Switch is oriented horizontally.  It's orientation will be vertical
 15 | if you set ``width`` < ``height``.
 16 | 
 17 | 
 18 | 
 19 | .. _lv_switch_parts_and_styles:
 20 | 
 21 | Parts and Styles
 22 | ****************
 23 | 
 24 | -  :cpp:enumerator:`LV_PART_MAIN` Switch's background; uses the :ref:`typical
 25 |    background style properties <typical bg props>`. ``padding`` makes the indicator smaller
 26 |    in the respective direction.
 27 | -  :cpp:enumerator:`LV_PART_INDICATOR` The indicator that shows the current state of
 28 |    the Switch; also uses the :ref:`typical background style properties <typical bg props>`.
 29 | -  :cpp:enumerator:`LV_PART_KNOB` A rectangle (or circle) drawn at the left or right
 30 |    side of the indicator; also uses the :ref:`typical background style properties
 31 |    <typical bg props>` to modify the knob's appearance. By default, the knob is round
 32 |    (radius-style can modify this) with diameter slightly smaller than the smaller
 33 |    side of the slider.  The knob can be made larger with the ``padding`` values.
 34 |    Padding values can be asymmetric as well.
 35 | 
 36 | 
 37 | 
 38 | .. _lv_switch_usage:
 39 | 
 40 | Usage
 41 | *****
 42 | 
 43 | Change state
 44 | ------------
 45 | 
 46 | The Switch uses the standard :cpp:enumerator:`LV_STATE_CHECKED` state.
 47 | 
 48 | To get the current state of the Switch (with ``true`` being on), use
 49 | :cpp:expr:`lv_obj_has_state(widget, LV_STATE_CHECKED)`.
 50 | 
 51 | Call :cpp:expr:`lv_obj_add_state(widget, LV_STATE_CHECKED)` to turn it on, or
 52 | :cpp:expr:`lv_obj_remove_state(widget, LV_STATE_CHECKED)` to turn it off
 53 | programmatically.
 54 | 
 55 | Change orientation
 56 | ------------------
 57 | 
 58 | With a Switch is created, its default orientation is
 59 | :cpp:enumerator:`LV_SWITCH_ORIENTATION_AUTO`, which causes it to be oriented based
 60 | on ``width`` and ``height``.  You can change this behavior using
 61 | :cpp:expr:`lv_switch_set_orientation(widget, orientation)`.  Possible values for
 62 | ``orientation`` are:
 63 | 
 64 | - :cpp:enumerator:`LV_SWITCH_ORIENTATION_AUTO`
 65 | - :cpp:enumerator:`LV_SWITCH_ORIENTATION_HORIZONTAL`
 66 | - :cpp:enumerator:`LV_SWITCH_ORIENTATION_VERTICAL`
 67 | 
 68 | 
 69 | 
 70 | .. _lv_switch_events:
 71 | 
 72 | Events
 73 | ******
 74 | 
 75 | -  :cpp:enumerator:`LV_EVENT_VALUE_CHANGED` Sent when Switch changes state.
 76 | 
 77 | .. admonition::  Further Reading
 78 | 
 79 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
 80 | 
 81 |     Learn more about :ref:`events`.
 82 | 
 83 | 
 84 | 
 85 | .. _lv_switch_keys:
 86 | 
 87 | Keys
 88 | ****
 89 | 
 90 | -  ``LV_KEY_UP/RIGHT`` Turns Switch ON
 91 | -  ``LV_KEY_DOWN/LEFT`` Turns Switch OFF
 92 | -  :cpp:enumerator:`LV_KEY_ENTER` Toggles the Switch
 93 | 
 94 | .. admonition::  Further Reading
 95 | 
 96 |     Learn more about :ref:`indev_keys`.
 97 | 
 98 | 
 99 | 
100 | .. _lv_switch_example:
101 | 
102 | Example
103 | *******
104 | 
105 | .. include:: ../../examples/widgets/switch/index.rst
106 | 
107 | 
108 | 
109 | .. _lv_switch_api:
110 | 
111 | API
112 | ***
113 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/tabview.rst:
--------------------------------------------------------------------------------
  1 | .. _lv_tabview:
  2 | 
  3 | =====================
  4 | Tab View (lv_tabview)
  5 | =====================
  6 | 
  7 | 
  8 | Overview
  9 | ********
 10 | 
 11 | The Tab View Widget can be used to organize content in tabs. The Tab
 12 | View is built from other Widgets:
 13 | 
 14 | - Main container: :ref:`base_widget`
 15 | - Tab buttons: an :ref:`base_widget` with :ref:`lv_button`
 16 | - Container for the tabs: :ref:`base_widget`
 17 | - Content of the tabs: :ref:`base_widget`
 18 | 
 19 | The tab buttons can be positioned on the top, bottom, left and right
 20 | side of the Tab View.
 21 | 
 22 | A new tab can be selected either by clicking on a tab button or by
 23 | sliding horizontally on the content.
 24 | 
 25 | 
 26 | 
 27 | .. _lv_tabview_parts_and_styles:
 28 | 
 29 | 
 30 | Parts and Styles
 31 | ****************
 32 | 
 33 | There are no special parts on the Tab View but the :ref:`base_widget` and
 34 | :ref:`lv_button` Widgets are used to create the Tab View.
 35 | 
 36 | 
 37 | 
 38 | .. _lv_tabview_usage:
 39 | 
 40 | Usage
 41 | *****
 42 | 
 43 | Creating a Tab View
 44 | -------------------
 45 | 
 46 | :cpp:expr:`lv_tabview_create(parent)` creates a new empty Tab View.
 47 | 
 48 | Adding tabs
 49 | -----------
 50 | 
 51 | New tabs can be added with :cpp:expr:`lv_tabview_add_tab(tabview, "Tab name")`.
 52 | This will return a pointer to a :ref:`base_widget` where
 53 | the tab's content can be created.
 54 | 
 55 | Renaming tabs
 56 | -------------
 57 | 
 58 | A tab can be renamed with
 59 | :cpp:expr:`lv_tabview_rename_tab(tabview, tab_id, "New Name")`.
 60 | 
 61 | Navigating to a new tab
 62 | -----------------------
 63 | 
 64 | To select a new tab you can:
 65 | 
 66 | - Click on its tab button
 67 | - Slide horizontally
 68 | - Use :cpp:expr:`lv_tabview_set_active(tabview, tab_id, LV_ANIM_ON / OFF)` function
 69 | 
 70 | 
 71 | Setting tab bar position
 72 | ------------------------
 73 | 
 74 | Using the :cpp:expr:`lv_tabview_set_tab_bar_position(tabview, LV_DIR_LEFT/RIGHT/TOP/BOTTOM)`
 75 | the tab bar can be moved to any side.
 76 | 
 77 | Setting tab bar size
 78 | --------------------
 79 | 
 80 | The size of the tab bar can be adjusted by :cpp:expr:`lv_tabview_set_tab_bar_size(tabview, size)`
 81 | When tabs are on the top or bottom, this means the height of the tab bar, and when
 82 | they are on the sides, it means the width.
 83 | 
 84 | Accessing the parts
 85 | -------------------
 86 | 
 87 | - :cpp:expr:`lv_tabview_get_content(tabview)` returns a pointer to the container for
 88 |   tabs content (a :ref:`base_widget`)
 89 | - :cpp:expr:`lv_tabview_get_tab_bar(tabview)` returns a pointer to the container for
 90 |   tab buttons (a :ref:`base_widget`)
 91 | 
 92 | 
 93 | 
 94 | .. _lv_tabview_events:
 95 | 
 96 | Events
 97 | ******
 98 | 
 99 | -  :cpp:enumerator:`LV_EVENT_VALUE_CHANGED` Sent when a new tab is selected by sliding
100 |    or clicking the tab button. :cpp:expr:`lv_tabview_get_tab_active(tabview)`
101 |    returns the zero based index of the current tab.
102 | 
103 | .. admonition::  Further Reading
104 | 
105 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
106 | 
107 |     Learn more about :ref:`events`.
108 | 
109 | 
110 | 
111 | .. _lv_tabview_keys:
112 | 
113 | Keys
114 | ****
115 | 
116 | Keys have effect only on the tab buttons.
117 | Programmatically add these buttons to a group if required.
118 | 
119 | .. admonition::  Further Reading
120 | 
121 |     Learn more about :ref:`indev_keys`.
122 | 
123 | 
124 | 
125 | .. _lv_tabview_example:
126 | 
127 | Example
128 | *******
129 | 
130 | .. include:: ../../examples/widgets/tabview/index.rst
131 | 
132 | 
133 | 
134 | .. _lv_tabview_api:
135 | 
136 | API
137 | ***
138 | 


--------------------------------------------------------------------------------
/docs/src/details/widgets/tileview.rst:
--------------------------------------------------------------------------------
  1 | .. _lv_tileview:
  2 | 
  3 | =======================
  4 | Tile View (lv_tileview)
  5 | =======================
  6 | 
  7 | 
  8 | Overview
  9 | ********
 10 | 
 11 | The Tile View is a container Widget whose elements (called *tiles*) can
 12 | be arranged in grid form. A user can navigate between the tiles by
 13 | swiping. Any direction of swiping can be disabled on the tiles
 14 | individually to not allow moving from one tile to another.
 15 | 
 16 | If the Tile View is screen sized, the user interface resembles what you
 17 | may have seen on smartwatches.
 18 | 
 19 | 
 20 | 
 21 | .. _lv_tileview_parts_and_styles:
 22 | 
 23 | Parts and Styles
 24 | ****************
 25 | 
 26 | The Tile View is built from a :ref:`base_widget` container and
 27 | :ref:`base_widget` tiles.
 28 | 
 29 | The parts and styles work the same as for :ref:`base_widget`.
 30 | 
 31 | 
 32 | 
 33 | .. _lv_tileview_usage:
 34 | 
 35 | Usage
 36 | *****
 37 | 
 38 | Add a tile
 39 | ----------
 40 | 
 41 | :cpp:expr:`lv_tileview_add_tile(tileview, col_id, row_id, dir)` creates a new
 42 | tile on the ``col_id``\ -th column and ``row_id``\ -th row. ``dir`` can be
 43 | ``LV_DIR_LEFT/RIGHT/TOP/BOTTOM/HOR/VER/ALL`` or OR-ed values to enable
 44 | moving to the adjacent tiles in the given direction by swiping.
 45 | 
 46 | The returned value is a pointer to the tile (a :ref:`base_widget`) on which the
 47 | content of the tab can be created.
 48 | 
 49 | Change tile
 50 | -----------
 51 | 
 52 | The Tile View can scroll to a specified tile with
 53 | :cpp:expr:`lv_tileview_set_tile(tileview, tile, LV_ANIM_ON/OFF)` or
 54 | :cpp:expr:`lv_tileview_set_tile_by_index(tileview, col_id, row_id, LV_ANIM_ON/OFF)`.
 55 | 
 56 | 
 57 | 
 58 | .. _lv_tileview_events:
 59 | 
 60 | Events
 61 | ******
 62 | 
 63 | -  :cpp:enumerator:`LV_EVENT_VALUE_CHANGED` Sent after a new tile is displayed by scrolling.
 64 |    :cpp:expr:`lv_tileview_get_tile_active(tabview)` can be used within the event to
 65 |    get a pointer to the newly-displayed tile.
 66 | 
 67 | .. admonition::  Further Reading
 68 | 
 69 |     Learn more about :ref:`lv_obj_events` emitted by all Widgets.
 70 | 
 71 |     Learn more about :ref:`events`.
 72 | 
 73 | 
 74 | 
 75 | .. _lv_tileview_keys:
 76 | 
 77 | Keys
 78 | ****
 79 | 
 80 | No *Keys* are processed by Tileview Widgets.
 81 | 
 82 | .. admonition::  Further Reading
 83 | 
 84 |     Learn more about :ref:`indev_keys`.
 85 | 
 86 | 
 87 | 
 88 | .. _lv_tileview_example:
 89 | 
 90 | Example
 91 | *******
 92 | 
 93 | .. include:: ../../examples/widgets/tileview/index.rst
 94 | 
 95 | 
 96 | 
 97 | .. _lv_tileview_api:
 98 | 
 99 | API
100 | ***
101 | 


--------------------------------------------------------------------------------
/docs/src/intro/index.rst:
--------------------------------------------------------------------------------
 1 | .. _intro-page:
 2 | 
 3 | ============
 4 | Introduction
 5 | ============
 6 | 
 7 | .. toctree::
 8 |     :maxdepth: 1
 9 | 
10 |     introduction
11 |     getting_started
12 | 


--------------------------------------------------------------------------------
/docs/src/lvgl_version.py:
--------------------------------------------------------------------------------
 1 | """
 2 | Utility used by `./docs/src/conf.py` and `./docs/build.py`
 3 | to fetch current LVGL version string from `lv_version.h`.
 4 | """
 5 | import os
 6 | import re
 7 | 
 8 | 
 9 | def lvgl_version(version_file):
10 |     """Build and return LVGL version string from `lv_version.h`.  Updated to be
11 |     multi-platform compatible and resilient to changes in file in compliance
12 |     with C macro syntax.
13 | 
14 |     :param version_file:  path to `lv_version.h`
15 |     :return:  version string
16 |     """
17 |     major = ''
18 |     minor = ''
19 | 
20 |     if version_file is not None:
21 |         with open(version_file, 'r') as file:
22 |             major_re = re.compile(r'define\s+LVGL_VERSION_MAJOR\s+(\d+)')
23 |             minor_re = re.compile(r'define\s+LVGL_VERSION_MINOR\s+(\d+)')
24 | 
25 |             for line in file.readlines():
26 |                 # Skip if line not long enough to match.
27 |                 if len(line) < 28:
28 |                     continue
29 | 
30 |                 match = major_re.search(line)
31 |                 if match is not None:
32 |                     major = match[1]
33 |                 else:
34 |                     match = minor_re.search(line)
35 |                     if match is not None:
36 |                         minor = match[1]
37 |                         # Exit early if we have both values.
38 |                         if len(major) > 0 and len(minor) > 0:
39 |                             break
40 | 
41 |     return f'{major}.{minor}'
42 | 
43 | 
44 | if __name__ == '__main__':
45 |     """Make module importable as well as run-able."""
46 |     base_dir = os.path.abspath(os.path.dirname(__file__))
47 |     project_dir = os.path.abspath(os.path.join(base_dir, '..', '..'))
48 |     version_file = os.path.join(project_dir, "lv_version.h")
49 |     version_str = lvgl_version(version_file)
50 |     print(version_str, end='', flush=True)
51 | 


---------------------------------------------------------