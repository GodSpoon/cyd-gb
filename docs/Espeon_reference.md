├── .gitattributes
├── .github
    └── FUNDING.yml
├── .gitignore
├── LICENSE
├── README.md
├── cpu.cpp
├── cpu.h
├── espeon.cpp
├── espeon.h
├── espeon.ino
├── firmwares
    ├── Espeon
    │   ├── boot_app0_0xe000.bin
    │   ├── bootloader_0x1000.bin
    │   └── partitions_espeon_0x8000.bin
    ├── espeon.csv
    └── m5burner.json
├── gbborder.jpg
├── gbfiles.h
├── interrupt.cpp
├── interrupt.h
├── lcd.cpp
├── lcd.h
├── logo
    ├── espeon_dmg.png
    ├── espeon_dmg.xcf
    ├── espeon_dmg_small.png
    ├── espeon_logo.png
    └── espeon_logo.xcf
├── makeborder.bat
├── mbc.cpp
├── mbc.h
├── mem.cpp
├── mem.h
├── menu.cpp
├── menu.h
├── rom.cpp
├── rom.h
├── rom2h.bat
├── timer.cpp
└── timer.h


/.gitattributes:
--------------------------------------------------------------------------------
1 | # Auto detect text files and perform LF normalization
2 | * text=auto
3 | 


--------------------------------------------------------------------------------
/.github/FUNDING.yml:
--------------------------------------------------------------------------------
 1 | # These are supported funding model platforms
 2 | 
 3 | github: # Replace with up to 4 GitHub Sponsors-enabled usernames e.g., [user1, user2]
 4 | patreon: # Replace with a single Patreon username
 5 | open_collective: # Replace with a single Open Collective username
 6 | ko_fi: ryuzakimrl
 7 | tidelift: # Replace with a single Tidelift platform-name/package-name e.g., npm/babel
 8 | community_bridge: # Replace with a single Community Bridge project-name e.g., cloud-foundry
 9 | liberapay: # Replace with a single Liberapay username
10 | issuehunt: # Replace with a single IssueHunt username
11 | otechie: # Replace with a single Otechie username
12 | custom: # Replace with up to 4 custom sponsorship URLs e.g., ['link1', 'link2']
13 | 


--------------------------------------------------------------------------------
/.gitignore:
--------------------------------------------------------------------------------
 1 | # Prerequisites
 2 | *.d
 3 | 
 4 | # Compiled Object files
 5 | *.slo
 6 | *.lo
 7 | *.o
 8 | *.obj
 9 | 
10 | # Precompiled Headers
11 | *.gch
12 | *.pch
13 | 
14 | # Compiled Dynamic libraries
15 | *.so
16 | *.dylib
17 | *.dll
18 | 
19 | # Fortran module files
20 | *.mod
21 | *.smod
22 | 
23 | # Compiled Static libraries
24 | *.lai
25 | *.la
26 | *.a
27 | *.lib
28 | 
29 | # Executables
30 | *.exe
31 | *.out
32 | *.app
33 | 
34 | # Misc
35 | roms
36 | *.gb
37 | *.txt
38 | gbrom.h
39 | gbborder.h
40 | gbbios.h
41 | espeon*.bin
42 | 


--------------------------------------------------------------------------------
/LICENSE:
--------------------------------------------------------------------------------
  1 | GNU GENERAL PUBLIC LICENSE
  2 |                        Version 3, 29 June 2007
  3 | 
  4 |  Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
  5 |  Everyone is permitted to copy and distribute verbatim copies
  6 |  of this license document, but changing it is not allowed.
  7 | 
  8 |                             Preamble
  9 | 
 10 |   The GNU General Public License is a free, copyleft license for
 11 | software and other kinds of works.
 12 | 
 13 |   The licenses for most software and other practical works are designed
 14 | to take away your freedom to share and change the works.  By contrast,
 15 | the GNU General Public License is intended to guarantee your freedom to
 16 | share and change all versions of a program--to make sure it remains free
 17 | software for all its users.  We, the Free Software Foundation, use the
 18 | GNU General Public License for most of our software; it applies also to
 19 | any other work released this way by its authors.  You can apply it to
 20 | your programs, too.
 21 | 
 22 |   When we speak of free software, we are referring to freedom, not
 23 | price.  Our General Public Licenses are designed to make sure that you
 24 | have the freedom to distribute copies of free software (and charge for
 25 | them if you wish), that you receive source code or can get it if you
 26 | want it, that you can change the software or use pieces of it in new
 27 | free programs, and that you know you can do these things.
 28 | 
 29 |   To protect your rights, we need to prevent others from denying you
 30 | these rights or asking you to surrender the rights.  Therefore, you have
 31 | certain responsibilities if you distribute copies of the software, or if
 32 | you modify it: responsibilities to respect the freedom of others.
 33 | 
 34 |   For example, if you distribute copies of such a program, whether
 35 | gratis or for a fee, you must pass on to the recipients the same
 36 | freedoms that you received.  You must make sure that they, too, receive
 37 | or can get the source code.  And you must show them these terms so they
 38 | know their rights.
 39 | 
 40 |   Developers that use the GNU GPL protect your rights with two steps:
 41 | (1) assert copyright on the software, and (2) offer you this License
 42 | giving you legal permission to copy, distribute and/or modify it.
 43 | 
 44 |   For the developers' and authors' protection, the GPL clearly explains
 45 | that there is no warranty for this free software.  For both users' and
 46 | authors' sake, the GPL requires that modified versions be marked as
 47 | changed, so that their problems will not be attributed erroneously to
 48 | authors of previous versions.
 49 | 
 50 |   Some devices are designed to deny users access to install or run
 51 | modified versions of the software inside them, although the manufacturer
 52 | can do so.  This is fundamentally incompatible with the aim of
 53 | protecting users' freedom to change the software.  The systematic
 54 | pattern of such abuse occurs in the area of products for individuals to
 55 | use, which is precisely where it is most unacceptable.  Therefore, we
 56 | have designed this version of the GPL to prohibit the practice for those
 57 | products.  If such problems arise substantially in other domains, we
 58 | stand ready to extend this provision to those domains in future versions
 59 | of the GPL, as needed to protect the freedom of users.
 60 | 
 61 |   Finally, every program is threatened constantly by software patents.
 62 | States should not allow patents to restrict development and use of
 63 | software on general-purpose computers, but in those that do, we wish to
 64 | avoid the special danger that patents applied to a free program could
 65 | make it effectively proprietary.  To prevent this, the GPL assures that
 66 | patents cannot be used to render the program non-free.
 67 | 
 68 |   The precise terms and conditions for copying, distribution and
 69 | modification follow.
 70 | 
 71 |                        TERMS AND CONDITIONS
 72 | 
 73 |   0. Definitions.
 74 | 
 75 |   "This License" refers to version 3 of the GNU General Public License.
 76 | 
 77 |   "Copyright" also means copyright-like laws that apply to other kinds of
 78 | works, such as semiconductor masks.
 79 | 
 80 |   "The Program" refers to any copyrightable work licensed under this
 81 | License.  Each licensee is addressed as "you".  "Licensees" and
 82 | "recipients" may be individuals or organizations.
 83 | 
 84 |   To "modify" a work means to copy from or adapt all or part of the work
 85 | in a fashion requiring copyright permission, other than the making of an
 86 | exact copy.  The resulting work is called a "modified version" of the
 87 | earlier work or a work "based on" the earlier work.
 88 | 
 89 |   A "covered work" means either the unmodified Program or a work based
 90 | on the Program.
 91 | 
 92 |   To "propagate" a work means to do anything with it that, without
 93 | permission, would make you directly or secondarily liable for
 94 | infringement under applicable copyright law, except executing it on a
 95 | computer or modifying a private copy.  Propagation includes copying,
 96 | distribution (with or without modification), making available to the
 97 | public, and in some countries other activities as well.
 98 | 
 99 |   To "convey" a work means any kind of propagation that enables other
100 | parties to make or receive copies.  Mere interaction with a user through
101 | a computer network, with no transfer of a copy, is not conveying.
102 | 
103 |   An interactive user interface displays "Appropriate Legal Notices"
104 | to the extent that it includes a convenient and prominently visible
105 | feature that (1) displays an appropriate copyright notice, and (2)
106 | tells the user that there is no warranty for the work (except to the
107 | extent that warranties are provided), that licensees may convey the
108 | work under this License, and how to view a copy of this License.  If
109 | the interface presents a list of user commands or options, such as a
110 | menu, a prominent item in the list meets this criterion.
111 | 
112 |   1. Source Code.
113 | 
114 |   The "source code" for a work means the preferred form of the work
115 | for making modifications to it.  "Object code" means any non-source
116 | form of a work.
117 | 
118 |   A "Standard Interface" means an interface that either is an official
119 | standard defined by a recognized standards body, or, in the case of
120 | interfaces specified for a particular programming language, one that
121 | is widely used among developers working in that language.
122 | 
123 |   The "System Libraries" of an executable work include anything, other
124 | than the work as a whole, that (a) is included in the normal form of
125 | packaging a Major Component, but which is not part of that Major
126 | Component, and (b) serves only to enable use of the work with that
127 | Major Component, or to implement a Standard Interface for which an
128 | implementation is available to the public in source code form.  A
129 | "Major Component", in this context, means a major essential component
130 | (kernel, window system, and so on) of the specific operating system
131 | (if any) on which the executable work runs, or a compiler used to
132 | produce the work, or an object code interpreter used to run it.
133 | 
134 |   The "Corresponding Source" for a work in object code form means all
135 | the source code needed to generate, install, and (for an executable
136 | work) run the object code and to modify the work, including scripts to
137 | control those activities.  However, it does not include the work's
138 | System Libraries, or general-purpose tools or generally available free
139 | programs which are used unmodified in performing those activities but
140 | which are not part of the work.  For example, Corresponding Source
141 | includes interface definition files associated with source files for
142 | the work, and the source code for shared libraries and dynamically
143 | linked subprograms that the work is specifically designed to require,
144 | such as by intimate data communication or control flow between those
145 | subprograms and other parts of the work.
146 | 
147 |   The Corresponding Source need not include anything that users
148 | can regenerate automatically from other parts of the Corresponding
149 | Source.
150 | 
151 |   The Corresponding Source for a work in source code form is that
152 | same work.
153 | 
154 |   2. Basic Permissions.
155 | 
156 |   All rights granted under this License are granted for the term of
157 | copyright on the Program, and are irrevocable provided the stated
158 | conditions are met.  This License explicitly affirms your unlimited
159 | permission to run the unmodified Program.  The output from running a
160 | covered work is covered by this License only if the output, given its
161 | content, constitutes a covered work.  This License acknowledges your
162 | rights of fair use or other equivalent, as provided by copyright law.
163 | 
164 |   You may make, run and propagate covered works that you do not
165 | convey, without conditions so long as your license otherwise remains
166 | in force.  You may convey covered works to others for the sole purpose
167 | of having them make modifications exclusively for you, or provide you
168 | with facilities for running those works, provided that you comply with
169 | the terms of this License in conveying all material for which you do
170 | not control copyright.  Those thus making or running the covered works
171 | for you must do so exclusively on your behalf, under your direction
172 | and control, on terms that prohibit them from making any copies of
173 | your copyrighted material outside their relationship with you.
174 | 
175 |   Conveying under any other circumstances is permitted solely under
176 | the conditions stated below.  Sublicensing is not allowed; section 10
177 | makes it unnecessary.
178 | 
179 |   3. Protecting Users' Legal Rights From Anti-Circumvention Law.
180 | 
181 |   No covered work shall be deemed part of an effective technological
182 | measure under any applicable law fulfilling obligations under article
183 | 11 of the WIPO copyright treaty adopted on 20 December 1996, or
184 | similar laws prohibiting or restricting circumvention of such
185 | measures.
186 | 
187 |   When you convey a covered work, you waive any legal power to forbid
188 | circumvention of technological measures to the extent such circumvention
189 | is effected by exercising rights under this License with respect to
190 | the covered work, and you disclaim any intention to limit operation or
191 | modification of the work as a means of enforcing, against the work's
192 | users, your or third parties' legal rights to forbid circumvention of
193 | technological measures.
194 | 
195 |   4. Conveying Verbatim Copies.
196 | 
197 |   You may convey verbatim copies of the Program's source code as you
198 | receive it, in any medium, provided that you conspicuously and
199 | appropriately publish on each copy an appropriate copyright notice;
200 | keep intact all notices stating that this License and any
201 | non-permissive terms added in accord with section 7 apply to the code;
202 | keep intact all notices of the absence of any warranty; and give all
203 | recipients a copy of this License along with the Program.
204 | 
205 |   You may charge any price or no price for each copy that you convey,
206 | and you may offer support or warranty protection for a fee.
207 | 
208 |   5. Conveying Modified Source Versions.
209 | 
210 |   You may convey a work based on the Program, or the modifications to
211 | produce it from the Program, in the form of source code under the
212 | terms of section 4, provided that you also meet all of these conditions:
213 | 
214 |     a) The work must carry prominent notices stating that you modified
215 |     it, and giving a relevant date.
216 | 
217 |     b) The work must carry prominent notices stating that it is
218 |     released under this License and any conditions added under section
219 |     7.  This requirement modifies the requirement in section 4 to
220 |     "keep intact all notices".
221 | 
222 |     c) You must license the entire work, as a whole, under this
223 |     License to anyone who comes into possession of a copy.  This
224 |     License will therefore apply, along with any applicable section 7
225 |     additional terms, to the whole of the work, and all its parts,
226 |     regardless of how they are packaged.  This License gives no
227 |     permission to license the work in any other way, but it does not
228 |     invalidate such permission if you have separately received it.
229 | 
230 |     d) If the work has interactive user interfaces, each must display
231 |     Appropriate Legal Notices; however, if the Program has interactive
232 |     interfaces that do not display Appropriate Legal Notices, your
233 |     work need not make them do so.
234 | 
235 |   A compilation of a covered work with other separate and independent
236 | works, which are not by their nature extensions of the covered work,
237 | and which are not combined with it such as to form a larger program,
238 | in or on a volume of a storage or distribution medium, is called an
239 | "aggregate" if the compilation and its resulting copyright are not
240 | used to limit the access or legal rights of the compilation's users
241 | beyond what the individual works permit.  Inclusion of a covered work
242 | in an aggregate does not cause this License to apply to the other
243 | parts of the aggregate.
244 | 
245 |   6. Conveying Non-Source Forms.
246 | 
247 |   You may convey a covered work in object code form under the terms
248 | of sections 4 and 5, provided that you also convey the
249 | machine-readable Corresponding Source under the terms of this License,
250 | in one of these ways:
251 | 
252 |     a) Convey the object code in, or embodied in, a physical product
253 |     (including a physical distribution medium), accompanied by the
254 |     Corresponding Source fixed on a durable physical medium
255 |     customarily used for software interchange.
256 | 
257 |     b) Convey the object code in, or embodied in, a physical product
258 |     (including a physical distribution medium), accompanied by a
259 |     written offer, valid for at least three years and valid for as
260 |     long as you offer spare parts or customer support for that product
261 |     model, to give anyone who possesses the object code either (1) a
262 |     copy of the Corresponding Source for all the software in the
263 |     product that is covered by this License, on a durable physical
264 |     medium customarily used for software interchange, for a price no
265 |     more than your reasonable cost of physically performing this
266 |     conveying of source, or (2) access to copy the
267 |     Corresponding Source from a network server at no charge.
268 | 
269 |     c) Convey individual copies of the object code with a copy of the
270 |     written offer to provide the Corresponding Source.  This
271 |     alternative is allowed only occasionally and noncommercially, and
272 |     only if you received the object code with such an offer, in accord
273 |     with subsection 6b.
274 | 
275 |     d) Convey the object code by offering access from a designated
276 |     place (gratis or for a charge), and offer equivalent access to the
277 |     Corresponding Source in the same way through the same place at no
278 |     further charge.  You need not require recipients to copy the
279 |     Corresponding Source along with the object code.  If the place to
280 |     copy the object code is a network server, the Corresponding Source
281 |     may be on a different server (operated by you or a third party)
282 |     that supports equivalent copying facilities, provided you maintain
283 |     clear directions next to the object code saying where to find the
284 |     Corresponding Source.  Regardless of what server hosts the
285 |     Corresponding Source, you remain obligated to ensure that it is
286 |     available for as long as needed to satisfy these requirements.
287 | 
288 |     e) Convey the object code using peer-to-peer transmission, provided
289 |     you inform other peers where the object code and Corresponding
290 |     Source of the work are being offered to the general public at no
291 |     charge under subsection 6d.
292 | 
293 |   A separable portion of the object code, whose source code is excluded
294 | from the Corresponding Source as a System Library, need not be
295 | included in conveying the object code work.
296 | 
297 |   A "User Product" is either (1) a "consumer product", which means any
298 | tangible personal property which is normally used for personal, family,
299 | or household purposes, or (2) anything designed or sold for incorporation
300 | into a dwelling.  In determining whether a product is a consumer product,
301 | doubtful cases shall be resolved in favor of coverage.  For a particular
302 | product received by a particular user, "normally used" refers to a
303 | typical or common use of that class of product, regardless of the status
304 | of the particular user or of the way in which the particular user
305 | actually uses, or expects or is expected to use, the product.  A product
306 | is a consumer product regardless of whether the product has substantial
307 | commercial, industrial or non-consumer uses, unless such uses represent
308 | the only significant mode of use of the product.
309 | 
310 |   "Installation Information" for a User Product means any methods,
311 | procedures, authorization keys, or other information required to install
312 | and execute modified versions of a covered work in that User Product from
313 | a modified version of its Corresponding Source.  The information must
314 | suffice to ensure that the continued functioning of the modified object
315 | code is in no case prevented or interfered with solely because
316 | modification has been made.
317 | 
318 |   If you convey an object code work under this section in, or with, or
319 | specifically for use in, a User Product, and the conveying occurs as
320 | part of a transaction in which the right of possession and use of the
321 | User Product is transferred to the recipient in perpetuity or for a
322 | fixed term (regardless of how the transaction is characterized), the
323 | Corresponding Source conveyed under this section must be accompanied
324 | by the Installation Information.  But this requirement does not apply
325 | if neither you nor any third party retains the ability to install
326 | modified object code on the User Product (for example, the work has
327 | been installed in ROM).
328 | 
329 |   The requirement to provide Installation Information does not include a
330 | requirement to continue to provide support service, warranty, or updates
331 | for a work that has been modified or installed by the recipient, or for
332 | the User Product in which it has been modified or installed.  Access to a
333 | network may be denied when the modification itself materially and
334 | adversely affects the operation of the network or violates the rules and
335 | protocols for communication across the network.
336 | 
337 |   Corresponding Source conveyed, and Installation Information provided,
338 | in accord with this section must be in a format that is publicly
339 | documented (and with an implementation available to the public in
340 | source code form), and must require no special password or key for
341 | unpacking, reading or copying.
342 | 
343 |   7. Additional Terms.
344 | 
345 |   "Additional permissions" are terms that supplement the terms of this
346 | License by making exceptions from one or more of its conditions.
347 | Additional permissions that are applicable to the entire Program shall
348 | be treated as though they were included in this License, to the extent
349 | that they are valid under applicable law.  If additional permissions
350 | apply only to part of the Program, that part may be used separately
351 | under those permissions, but the entire Program remains governed by
352 | this License without regard to the additional permissions.
353 | 
354 |   When you convey a copy of a covered work, you may at your option
355 | remove any additional permissions from that copy, or from any part of
356 | it.  (Additional permissions may be written to require their own
357 | removal in certain cases when you modify the work.)  You may place
358 | additional permissions on material, added by you to a covered work,
359 | for which you have or can give appropriate copyright permission.
360 | 
361 |   Notwithstanding any other provision of this License, for material you
362 | add to a covered work, you may (if authorized by the copyright holders of
363 | that material) supplement the terms of this License with terms:
364 | 
365 |     a) Disclaiming warranty or limiting liability differently from the
366 |     terms of sections 15 and 16 of this License; or
367 | 
368 |     b) Requiring preservation of specified reasonable legal notices or
369 |     author attributions in that material or in the Appropriate Legal
370 |     Notices displayed by works containing it; or
371 | 
372 |     c) Prohibiting misrepresentation of the origin of that material, or
373 |     requiring that modified versions of such material be marked in
374 |     reasonable ways as different from the original version; or
375 | 
376 |     d) Limiting the use for publicity purposes of names of licensors or
377 |     authors of the material; or
378 | 
379 |     e) Declining to grant rights under trademark law for use of some
380 |     trade names, trademarks, or service marks; or
381 | 
382 |     f) Requiring indemnification of licensors and authors of that
383 |     material by anyone who conveys the material (or modified versions of
384 |     it) with contractual assumptions of liability to the recipient, for
385 |     any liability that these contractual assumptions directly impose on
386 |     those licensors and authors.
387 | 
388 |   All other non-permissive additional terms are considered "further
389 | restrictions" within the meaning of section 10.  If the Program as you
390 | received it, or any part of it, contains a notice stating that it is
391 | governed by this License along with a term that is a further
392 | restriction, you may remove that term.  If a license document contains
393 | a further restriction but permits relicensing or conveying under this
394 | License, you may add to a covered work material governed by the terms
395 | of that license document, provided that the further restriction does
396 | not survive such relicensing or conveying.
397 | 
398 |   If you add terms to a covered work in accord with this section, you
399 | must place, in the relevant source files, a statement of the
400 | additional terms that apply to those files, or a notice indicating
401 | where to find the applicable terms.
402 | 
403 |   Additional terms, permissive or non-permissive, may be stated in the
404 | form of a separately written license, or stated as exceptions;
405 | the above requirements apply either way.
406 | 
407 |   8. Termination.
408 | 
409 |   You may not propagate or modify a covered work except as expressly
410 | provided under this License.  Any attempt otherwise to propagate or
411 | modify it is void, and will automatically terminate your rights under
412 | this License (including any patent licenses granted under the third
413 | paragraph of section 11).
414 | 
415 |   However, if you cease all violation of this License, then your
416 | license from a particular copyright holder is reinstated (a)
417 | provisionally, unless and until the copyright holder explicitly and
418 | finally terminates your license, and (b) permanently, if the copyright
419 | holder fails to notify you of the violation by some reasonable means
420 | prior to 60 days after the cessation.
421 | 
422 |   Moreover, your license from a particular copyright holder is
423 | reinstated permanently if the copyright holder notifies you of the
424 | violation by some reasonable means, this is the first time you have
425 | received notice of violation of this License (for any work) from that
426 | copyright holder, and you cure the violation prior to 30 days after
427 | your receipt of the notice.
428 | 
429 |   Termination of your rights under this section does not terminate the
430 | licenses of parties who have received copies or rights from you under
431 | this License.  If your rights have been terminated and not permanently
432 | reinstated, you do not qualify to receive new licenses for the same
433 | material under section 10.
434 | 
435 |   9. Acceptance Not Required for Having Copies.
436 | 
437 |   You are not required to accept this License in order to receive or
438 | run a copy of the Program.  Ancillary propagation of a covered work
439 | occurring solely as a consequence of using peer-to-peer transmission
440 | to receive a copy likewise does not require acceptance.  However,
441 | nothing other than this License grants you permission to propagate or
442 | modify any covered work.  These actions infringe copyright if you do
443 | not accept this License.  Therefore, by modifying or propagating a
444 | covered work, you indicate your acceptance of this License to do so.
445 | 
446 |   10. Automatic Licensing of Downstream Recipients.
447 | 
448 |   Each time you convey a covered work, the recipient automatically
449 | receives a license from the original licensors, to run, modify and
450 | propagate that work, subject to this License.  You are not responsible
451 | for enforcing compliance by third parties with this License.
452 | 
453 |   An "entity transaction" is a transaction transferring control of an
454 | organization, or substantially all assets of one, or subdividing an
455 | organization, or merging organizations.  If propagation of a covered
456 | work results from an entity transaction, each party to that
457 | transaction who receives a copy of the work also receives whatever
458 | licenses to the work the party's predecessor in interest had or could
459 | give under the previous paragraph, plus a right to possession of the
460 | Corresponding Source of the work from the predecessor in interest, if
461 | the predecessor has it or can get it with reasonable efforts.
462 | 
463 |   You may not impose any further restrictions on the exercise of the
464 | rights granted or affirmed under this License.  For example, you may
465 | not impose a license fee, royalty, or other charge for exercise of
466 | rights granted under this License, and you may not initiate litigation
467 | (including a cross-claim or counterclaim in a lawsuit) alleging that
468 | any patent claim is infringed by making, using, selling, offering for
469 | sale, or importing the Program or any portion of it.
470 | 
471 |   11. Patents.
472 | 
473 |   A "contributor" is a copyright holder who authorizes use under this
474 | License of the Program or a work on which the Program is based.  The
475 | work thus licensed is called the contributor's "contributor version".
476 | 
477 |   A contributor's "essential patent claims" are all patent claims
478 | owned or controlled by the contributor, whether already acquired or
479 | hereafter acquired, that would be infringed by some manner, permitted
480 | by this License, of making, using, or selling its contributor version,
481 | but do not include claims that would be infringed only as a
482 | consequence of further modification of the contributor version.  For
483 | purposes of this definition, "control" includes the right to grant
484 | patent sublicenses in a manner consistent with the requirements of
485 | this License.
486 | 
487 |   Each contributor grants you a non-exclusive, worldwide, royalty-free
488 | patent license under the contributor's essential patent claims, to
489 | make, use, sell, offer for sale, import and otherwise run, modify and
490 | propagate the contents of its contributor version.
491 | 
492 |   In the following three paragraphs, a "patent license" is any express
493 | agreement or commitment, however denominated, not to enforce a patent
494 | (such as an express permission to practice a patent or covenant not to
495 | sue for patent infringement).  To "grant" such a patent license to a
496 | party means to make such an agreement or commitment not to enforce a
497 | patent against the party.
498 | 
499 |   If you convey a covered work, knowingly relying on a patent license,
500 | and the Corresponding Source of the work is not available for anyone
501 | to copy, free of charge and under the terms of this License, through a
502 | publicly available network server or other readily accessible means,
503 | then you must either (1) cause the Corresponding Source to be so
504 | available, or (2) arrange to deprive yourself of the benefit of the
505 | patent license for this particular work, or (3) arrange, in a manner
506 | consistent with the requirements of this License, to extend the patent
507 | license to downstream recipients.  "Knowingly relying" means you have
508 | actual knowledge that, but for the patent license, your conveying the
509 | covered work in a country, or your recipient's use of the covered work
510 | in a country, would infringe one or more identifiable patents in that
511 | country that you have reason to believe are valid.
512 | 
513 |   If, pursuant to or in connection with a single transaction or
514 | arrangement, you convey, or propagate by procuring conveyance of, a
515 | covered work, and grant a patent license to some of the parties
516 | receiving the covered work authorizing them to use, propagate, modify
517 | or convey a specific copy of the covered work, then the patent license
518 | you grant is automatically extended to all recipients of the covered
519 | work and works based on it.
520 | 
521 |   A patent license is "discriminatory" if it does not include within
522 | the scope of its coverage, prohibits the exercise of, or is
523 | conditioned on the non-exercise of one or more of the rights that are
524 | specifically granted under this License.  You may not convey a covered
525 | work if you are a party to an arrangement with a third party that is
526 | in the business of distributing software, under which you make payment
527 | to the third party based on the extent of your activity of conveying
528 | the work, and under which the third party grants, to any of the
529 | parties who would receive the covered work from you, a discriminatory
530 | patent license (a) in connection with copies of the covered work
531 | conveyed by you (or copies made from those copies), or (b) primarily
532 | for and in connection with specific products or compilations that
533 | contain the covered work, unless you entered into that arrangement,
534 | or that patent license was granted, prior to 28 March 2007.
535 | 
536 |   Nothing in this License shall be construed as excluding or limiting
537 | any implied license or other defenses to infringement that may
538 | otherwise be available to you under applicable patent law.
539 | 
540 |   12. No Surrender of Others' Freedom.
541 | 
542 |   If conditions are imposed on you (whether by court order, agreement or
543 | otherwise) that contradict the conditions of this License, they do not
544 | excuse you from the conditions of this License.  If you cannot convey a
545 | covered work so as to satisfy simultaneously your obligations under this
546 | License and any other pertinent obligations, then as a consequence you may
547 | not convey it at all.  For example, if you agree to terms that obligate you
548 | to collect a royalty for further conveying from those to whom you convey
549 | the Program, the only way you could satisfy both those terms and this
550 | License would be to refrain entirely from conveying the Program.
551 | 
552 |   13. Use with the GNU Affero General Public License.
553 | 
554 |   Notwithstanding any other provision of this License, you have
555 | permission to link or combine any covered work with a work licensed
556 | under version 3 of the GNU Affero General Public License into a single
557 | combined work, and to convey the resulting work.  The terms of this
558 | License will continue to apply to the part which is the covered work,
559 | but the special requirements of the GNU Affero General Public License,
560 | section 13, concerning interaction through a network will apply to the
561 | combination as such.
562 | 
563 |   14. Revised Versions of this License.
564 | 
565 |   The Free Software Foundation may publish revised and/or new versions of
566 | the GNU General Public License from time to time.  Such new versions will
567 | be similar in spirit to the present version, but may differ in detail to
568 | address new problems or concerns.
569 | 
570 |   Each version is given a distinguishing version number.  If the
571 | Program specifies that a certain numbered version of the GNU General
572 | Public License "or any later version" applies to it, you have the
573 | option of following the terms and conditions either of that numbered
574 | version or of any later version published by the Free Software
575 | Foundation.  If the Program does not specify a version number of the
576 | GNU General Public License, you may choose any version ever published
577 | by the Free Software Foundation.
578 | 
579 |   If the Program specifies that a proxy can decide which future
580 | versions of the GNU General Public License can be used, that proxy's
581 | public statement of acceptance of a version permanently authorizes you
582 | to choose that version for the Program.
583 | 
584 |   Later license versions may give you additional or different
585 | permissions.  However, no additional obligations are imposed on any
586 | author or copyright holder as a result of your choosing to follow a
587 | later version.
588 | 
589 |   15. Disclaimer of Warranty.
590 | 
591 |   THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY
592 | APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT
593 | HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY
594 | OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,
595 | THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
596 | PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM
597 | IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF
598 | ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
599 | 
600 |   16. Limitation of Liability.
601 | 
602 |   IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
603 | WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS
604 | THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY
605 | GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE
606 | USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF
607 | DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD
608 | PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS),
609 | EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF
610 | SUCH DAMAGES.
611 | 
612 |   17. Interpretation of Sections 15 and 16.
613 | 
614 |   If the disclaimer of warranty and limitation of liability provided
615 | above cannot be given local legal effect according to their terms,
616 | reviewing courts shall apply local law that most closely approximates
617 | an absolute waiver of all civil liability in connection with the
618 | Program, unless a warranty or assumption of liability accompanies a
619 | copy of the Program in return for a fee.
620 | 
621 |                      END OF TERMS AND CONDITIONS
622 | 
623 |             How to Apply These Terms to Your New Programs
624 | 
625 |   If you develop a new program, and you want it to be of the greatest
626 | possible use to the public, the best way to achieve this is to make it
627 | free software which everyone can redistribute and change under these terms.
628 | 
629 |   To do so, attach the following notices to the program.  It is safest
630 | to attach them to the start of each source file to most effectively
631 | state the exclusion of warranty; and each file should have at least
632 | the "copyright" line and a pointer to where the full notice is found.
633 | 
634 |     Espeon - Gameboy emulator for the ESP32
635 |     Copyright (C) 2019  Ryuzaki_MrL
636 | 
637 |     This program is free software: you can redistribute it and/or modify
638 |     it under the terms of the GNU General Public License as published by
639 |     the Free Software Foundation, either version 3 of the License, or
640 |     (at your option) any later version.
641 | 
642 |     This program is distributed in the hope that it will be useful,
643 |     but WITHOUT ANY WARRANTY; without even the implied warranty of
644 |     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
645 |     GNU General Public License for more details.
646 | 
647 |     You should have received a copy of the GNU General Public License
648 |     along with this program.  If not, see <http://www.gnu.org/licenses/>.
649 | 
650 | Also add information on how to contact you by electronic and paper mail.
651 | 
652 |   If the program does terminal interaction, make it output a short
653 | notice like this when it starts in an interactive mode:
654 | 
655 |     Espeon  Copyright (C) 2019  Ryuzaki_MrL
656 |     This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
657 |     This is free software, and you are welcome to redistribute it
658 |     under certain conditions; type `show c' for details.
659 | 
660 | The hypothetical commands `show w' and `show c' should show the appropriate
661 | parts of the General Public License.  Of course, your program's commands
662 | might be different; for a GUI interface, you would use an "about box".
663 | 
664 |   You should also get your employer (if you work as a programmer) or school,
665 | if any, to sign a "copyright disclaimer" for the program, if necessary.
666 | For more information on this, and how to apply and follow the GNU GPL, see
667 | <http://www.gnu.org/licenses/>.
668 | 
669 |   The GNU General Public License does not permit incorporating your program
670 | into proprietary programs.  If your program is a subroutine library, you
671 | may consider it more useful to permit linking proprietary applications with
672 | the library.  If this is what you want to do, use the GNU Lesser General
673 | Public License instead of this License.  But first, please read
674 | <http://www.gnu.org/philosophy/why-not-lgpl.html>.


--------------------------------------------------------------------------------
/README.md:
--------------------------------------------------------------------------------
 1 | ![Espeon](/logo/espeon_dmg_small.png)
 2 | 
 3 | Espeon is a gameboy emulator for Espressif's ESP32 SoC.
 4 | 
 5 | This project started out as a [rewrite](https://github.com/Ryuzaki-MrL/m5stack-gameboy) in order to be more accurate and optimized for the ESP32.
 6 | 
 7 | ## About Espeon
 8 | 
 9 | This emulator is being developed primarily with the M5Stack device in mind. You can find more info about it here: https://m5stack.com/
10 | 
11 | M5Stack Arduino API, M5Stack TreeView library, and M5Stack FACES are required.
12 | 
13 | If you don't own a M5Stack, feel free to adapt this codebase to your setup.
14 | 
15 | ### Recommended setup:
16 | 
17 | * A board containg an ESP32 chip and at least 4MB (32Mbit) of SPI flash, plus the tools to program it
18 | * A 320x240 ILI9341 display, controllable by a 4-wire SPI interface
19 | * Some kind of I2C gamepad
20 | * SD card reader (optional)
21 | 
22 | ## Compiling Espeon
23 | 
24 | To compile for the M5Stack, you'll need to:
25 | 
26 | * [Set up your Arduino IDE for the M5Stack](https://docs.m5stack.com/#/en/arduino/arduino_development)
27 | * (OPTIONAL) Get a copy of the gameboy's bootrom as a const array called gb_bios
28 | * (OPTIONAL) If you wish to bundle Espeon with a ROM, drag and drop the ROM file into rom2h.bat (max size of 512 KB)
29 | * Run espeon.ino
30 | * Compile the sketch and upload it to the board
31 | 
32 | Recommended: upload directly via esptool by using the provided partition scheme, or by using [M5Burner](http://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/software/M5Burner.zip).
33 | 
34 | A precompiled release will be provived for each new version.
35 | 
36 | ## Running games
37 | 
38 | If running on a M5Stack, you'll be presented with a menu where you can choose to either load a ROM from the SD card into the ESP32's flash (maximum of 2MB), or boot up the currently flashed ROM.
39 | 
40 | If either fails, the bundled ROM will be used instead (maximum of 512 KB).
41 | 
42 | ## Credits
43 | 
44 | * Code structure inspired by [zid](https://github.com/zid).
45 | * Base Arduino code and ROM bundle script by [lualiliu](https://github.com/lualiliu).
46 | * M5Stack TreeView UI library and example code by [lovyan](https://github.com/lovyan03).
47 | * Espeon artwork by [natsuki-o-bento](https://www.deviantart.com/natsukio-bento).
48 | 
49 | ## Features
50 | 
51 | * Fully taking advantage of both ESP32 cores (currently faster than the real gameboy, needs some tinkering)
52 | * Flash a ROM from the SD card
53 | * SRAM is saved to the SD card
54 | 
55 | ### TODO:
56 | 
57 | * Rewrite CPU/LR35902 code
58 | * Audio emulation
59 | * Object-oriented approach
60 | * SRAM autosaving (currently needs a button press)
61 | * Customizable palette and border
62 | 


--------------------------------------------------------------------------------
/cpu.cpp:
--------------------------------------------------------------------------------
   1 | #include <stdio.h>
   2 | #include "mem.h"
   3 | #include "interrupt.h"
   4 | #include "espeon.h"
   5 | 
   6 | /* 16-bit mode */
   7 | #define set_HL(x) do {uint32_t macro = (x); c.L = macro&0xFF; c.H = macro>>8;} while(0)
   8 | #define set_BC(x) do {uint32_t macro = (x); c.C = macro&0xFF; c.B = macro>>8;} while(0)
   9 | #define set_DE(x) do {uint32_t macro = (x); c.E = macro&0xFF; c.D = macro>>8;} while(0)
  10 | #define set_AF(x) do {uint32_t macro = (x); c.F = macro&0xFF; c.A = macro>>8;} while(0)
  11 | 
  12 | #define get_AF() ((c.A<<8) | c.F)
  13 | #define get_BC() ((c.B<<8) | c.C)
  14 | #define get_DE() ((c.D<<8) | c.E)
  15 | #define get_HL() ((c.H<<8) | c.L)
  16 | 
  17 | /* Flags */
  18 | #define set_Z(x) c.F = ((c.F&0x7F) | ((x)<<7))
  19 | #define set_N(x) c.F = ((c.F&0xBF) | ((x)<<6))
  20 | #define set_H(x) c.F = ((c.F&0xDF) | ((x)<<5))
  21 | #define set_C(x) c.F = ((c.F&0xEF) | ((x)<<4))
  22 | 
  23 | #define flag_Z !!((c.F & 0x80))
  24 | #define flag_N !!((c.F & 0x40))
  25 | #define flag_H !!((c.F & 0x20))
  26 | #define flag_C !!((c.F & 0x10))
  27 | 
  28 | static const uint8_t opcycles[] = {
  29 | /*  0  1  2  3  4  5  6  7		8  9  A  B  C  D  E  F	*/
  30 | 	1, 3, 2, 2, 1, 1, 2, 1, 	5, 2, 2, 2, 1, 1, 2, 1, // 0
  31 | 	1, 3, 2, 2, 1, 1, 2, 1, 	3, 2, 2, 2, 1, 1, 2, 1, // 1
  32 | 	2, 3, 2, 2, 1, 1, 2, 1, 	2, 2, 2, 2, 1, 1, 2, 1, // 2
  33 | 	2, 3, 2, 2, 3, 3, 3, 1, 	2, 2, 2, 2, 1, 1, 2, 1, // 3
  34 | 	1, 1, 1, 1, 1, 1, 2, 1, 	1, 1, 1, 1, 1, 1, 2, 1, // 4
  35 | 	1, 1, 1, 1, 1, 1, 2, 1, 	1, 1, 1, 1, 1, 1, 2, 1, // 5
  36 | 	1, 1, 1, 1, 1, 1, 2, 1, 	1, 1, 1, 1, 1, 1, 2, 1, // 6
  37 | 	2, 2, 2, 2, 2, 2, 1, 2, 	1, 1, 1, 1, 1, 1, 2, 1, // 7
  38 | 	
  39 | 	1, 1, 1, 1, 1, 1, 2, 1, 	1, 1, 1, 1, 1, 1, 2, 1, // 8
  40 | 	1, 1, 1, 1, 1, 1, 2, 1, 	1, 1, 1, 1, 1, 1, 2, 1, // 9
  41 | 	1, 1, 1, 1, 1, 1, 2, 1, 	1, 1, 1, 1, 1, 1, 2, 1, // A
  42 | 	1, 1, 1, 1, 1, 1, 2, 1, 	1, 1, 1, 1, 1, 1, 2, 1, // B
  43 | 	2, 3, 3, 4, 3, 4, 2, 4, 	2, 4, 3, 1, 3, 6, 2, 4, // C
  44 | 	2, 3, 3, 0, 3, 4, 2, 4, 	2, 4, 3, 0, 3, 0, 2, 4, // D
  45 | 	3, 3, 2, 0, 0, 4, 2, 4, 	4, 1, 4, 0, 0, 0, 2, 4, // E
  46 | 	3, 3, 2, 1, 0, 4, 2, 4, 	3, 2, 4, 1, 0, 0, 2, 4  // F
  47 | };
  48 | 
  49 | struct CPU {
  50 | 	uint8_t H, L;
  51 | 	uint8_t D, E;
  52 | 	uint8_t B, C;
  53 | 	uint8_t A, F;
  54 | 
  55 | 	uint16_t SP;
  56 | 	uint16_t PC;
  57 | 
  58 | 	uint32_t cycles;
  59 | 	uint32_t lastcycles;
  60 | };
  61 | 
  62 | static struct CPU c;
  63 | static bool halt_bug;
  64 | bool halted;
  65 | 
  66 | void cpu_init(void)
  67 | {	
  68 | 	if (usebootrom) return;
  69 | 	
  70 | 	set_AF(0x01B0);
  71 | 	set_BC(0x0013);
  72 | 	set_DE(0x00D8);
  73 | 	set_HL(0x014D);
  74 | 	c.SP = 0xFFFE;
  75 | 	c.PC = 0x0100;
  76 | }
  77 | 
  78 | static void RLC(uint8_t reg)
  79 | {
  80 | 	uint8_t t, old;
  81 | 
  82 | 	switch(reg)
  83 | 	{
  84 | 		case 0:	/* B */
  85 | 			old = !!(c.B&0x80);
  86 | 			c.B = (c.B << 1) | old;
  87 | 			set_C(old);
  88 | 			set_Z(!c.B);
  89 | 		break;
  90 | 		case 1:	/* C */
  91 | 			old = !!(c.C&0x80);
  92 | 			set_C(old);
  93 | 			c.C = c.C<<1 | old;
  94 | 			set_Z(!c.C);
  95 | 		break;
  96 | 		case 2:	/* D */
  97 | 			old = !!(c.D&0x80);
  98 | 			set_C(old);
  99 | 			c.D = c.D<<1 | old;
 100 | 			set_Z(!c.D);
 101 | 		break;
 102 | 		case 3:	/* E */
 103 | 			old = !!(c.E&0x80);
 104 | 			set_C(old);
 105 | 			c.E = c.E<<1 | old;
 106 | 			set_Z(!c.E);
 107 | 		break;
 108 | 		case 4:	/* H */
 109 | 			old = !!(c.H&0x80);
 110 | 			set_C(old);
 111 | 			c.H = c.H<<1 | old;
 112 | 			set_Z(!c.H);
 113 | 		break;
 114 | 		case 5:	/* L */
 115 | 			old = !!(c.L&0x80);
 116 | 			set_C(old);
 117 | 			c.L = c.L<<1 | old;
 118 | 			set_Z(!c.L);
 119 | 		break;
 120 | 		case 6:	/* (HL) */
 121 | 			t = mem_get_byte(get_HL());
 122 | 			old = !!(t&0x80);
 123 | 			set_C(old);
 124 | 			t = t<<1 | old;
 125 | 			mem_write_byte(get_HL(), t);
 126 | 			set_Z(!t);
 127 | 			c.cycles += 2;
 128 | 		break;
 129 | 		case 7:	/* A */
 130 | 			old = !!(c.A&0x80);
 131 | 			c.A = (c.A<<1) | old;
 132 | 			set_C(old);
 133 | 			set_Z(!c.A);
 134 | 		break;
 135 | 	}
 136 | 
 137 | 	set_N(0);
 138 | 	set_H(0);
 139 | }
 140 | 
 141 | static void RRC(uint8_t reg)
 142 | {
 143 | 	uint8_t t, old;
 144 | 
 145 | 	switch(reg)
 146 | 	{
 147 | 		case 0:	/* B */
 148 | 			old = c.B&1;
 149 | 			set_C(old);
 150 | 			c.B = c.B>>1 | old<<7;
 151 | 			set_Z(!c.B);
 152 | 		break;
 153 | 		case 1:	/* C */
 154 | 			old = c.C&1;
 155 | 			set_C(old);
 156 | 			c.C = c.C>>1 | old<<7;
 157 | 			set_Z(!c.C);
 158 | 		break;
 159 | 		case 2:	/* D */
 160 | 			old = c.D&1;
 161 | 			set_C(old);
 162 | 			c.D = c.D>>1 | old<<7;
 163 | 			set_Z(!c.D);
 164 | 		break;
 165 | 		case 3:	/* E */
 166 | 			old = c.E&1;
 167 | 			set_C(old);
 168 | 			c.E = c.E>>1 | old<<7;
 169 | 			set_Z(!c.E);
 170 | 		break;
 171 | 		case 4:	/* H */
 172 | 			old = c.H&1;
 173 | 			set_C(old);
 174 | 			c.H = c.H>>1 | old<<7;
 175 | 			set_Z(!c.H);
 176 | 		break;
 177 | 		case 5:	/* L */
 178 | 			old = c.L&1;
 179 | 			set_C(old);
 180 | 			c.L = c.L>>1 | old<<7;
 181 | 			set_Z(!c.L);
 182 | 		break;
 183 | 		case 6:	/* (HL) */
 184 | 			t = mem_get_byte(get_HL());
 185 | 			old = t;
 186 | 			set_C(old);
 187 | 			t = t>>1 | old<<7;
 188 | 			mem_write_byte(get_HL(), t);
 189 | 			set_Z(!t);
 190 | 			c.cycles += 2;
 191 | 		break;
 192 | 		case 7:	/* A */
 193 | 			old = c.A&1;
 194 | 			set_C(old);
 195 | 			c.A = c.A>>1 | old<<7;
 196 | 			set_Z(!c.A);
 197 | 		break;
 198 | 	}
 199 | 	set_N(0);
 200 | 	set_H(0);
 201 | }
 202 | 
 203 | static void RL(uint8_t reg)
 204 | {
 205 | 	uint8_t t, t2;
 206 | 
 207 | 	switch(reg)
 208 | 	{
 209 | 		case 0: /* B */
 210 | 			t2 = flag_C;
 211 | 			set_C(!!(c.B&0x80));
 212 | 			c.B = (c.B << 1) | !!(t2);
 213 | 			set_Z(!c.B);
 214 | 		break;
 215 | 		case 1: /* C */
 216 | 			t2 = flag_C;
 217 | 			set_C(!!(c.C&0x80));
 218 | 			c.C = (c.C << 1) | !!(t2);
 219 | 			set_Z(!c.C);
 220 | 		break;
 221 | 		case 2: /* D */
 222 | 			t2 = flag_C;
 223 | 			set_C(!!(c.D&0x80));
 224 | 			c.D = (c.D << 1) | !!(t2);
 225 | 			set_Z(!c.D);
 226 | 		break;
 227 | 		case 3: /* E */
 228 | 			t2 = flag_C;
 229 | 			set_C(!!(c.E&0x80));
 230 | 			c.E = (c.E << 1) | !!(t2);
 231 | 			set_Z(!c.E);
 232 | 		break;
 233 | 		case 4: /* H */
 234 | 			t2 = flag_C;
 235 | 			set_C(!!(c.H&0x80));
 236 | 			c.H = (c.H << 1) | !!(t2);
 237 | 			set_Z(!c.H);
 238 | 		break;
 239 | 		case 5: /* L */
 240 | 			t2 = flag_C;
 241 | 			set_C(!!(c.L&0x80));
 242 | 			c.L = (c.L << 1) | !!(t2);
 243 | 			set_Z(!c.L);
 244 | 		break;
 245 | 		case 6: /* (HL) */
 246 | 			t = mem_get_byte(get_HL());
 247 | 			t2 = flag_C;
 248 | 			set_C(!!(t&0x80));
 249 | 			t = (t << 1) | !!(t2);
 250 | 			mem_write_byte(get_HL(), t);
 251 | 			set_Z(!t);
 252 | 			c.cycles += 2;
 253 | 		break;
 254 | 		case 7: /* A */
 255 | 			t2 = flag_C;
 256 | 			set_C(!!(c.A&0x80));
 257 | 			c.A = (c.A << 1) | t2;
 258 | 			set_Z(!c.A);
 259 | 		break;
 260 | 	}
 261 | 
 262 | 	set_N(0);
 263 | 	set_H(0);
 264 | }
 265 | 
 266 | static void RR(uint8_t reg)
 267 | {
 268 | 	uint8_t t, t2;
 269 | 
 270 | 	switch(reg)
 271 | 	{
 272 | 		case 0:	/* B */
 273 | 			t2 = flag_C;
 274 | 			set_C(c.B&1);
 275 | 			c.B = (c.B >> 1) | t2<<7;
 276 | 			set_Z(!c.B);
 277 | 		break;
 278 | 		case 1: /* C */
 279 | 			t2 = flag_C;
 280 | 			set_C(c.C&1);
 281 | 			c.C = (c.C >> 1) | t2<<7;
 282 | 			set_Z(!c.C);
 283 | 		break;
 284 | 		case 2: /* D */
 285 | 			t2 = flag_C;
 286 | 			set_C(c.D&1);
 287 | 			c.D = (c.D >> 1) | t2<<7;
 288 | 			set_Z(!c.D);
 289 | 		break;
 290 | 		case 3: /* E */
 291 | 			t2 = flag_C;
 292 | 			set_C(c.E&1);
 293 | 			c.E = (c.E >> 1) | t2<<7;
 294 | 			set_Z(!c.E);
 295 | 		break;
 296 | 		case 4: /* H */
 297 | 			t2 = flag_C;
 298 | 			set_C(c.H&1);
 299 | 			c.H = (c.H >> 1) | t2<<7;
 300 | 			set_Z(!c.H);
 301 | 		break;
 302 | 		case 5: /* L */
 303 | 			t2 = flag_C;
 304 | 			set_C(c.L&1);
 305 | 			c.L = (c.L >> 1) | t2<<7;
 306 | 			set_Z(!c.L);
 307 | 		break;
 308 | 		case 6: /* (HL) */
 309 | 			t = mem_get_byte(get_HL());
 310 | 			t2 = flag_C;
 311 | 			set_C(t&1);
 312 | 			t = (t >> 1) | t2<<7;
 313 | 			set_Z(!t);
 314 | 			mem_write_byte(get_HL(), t);
 315 | 			c.cycles += 2;
 316 | 		break;
 317 | 		case 7: /* A */
 318 | 			t2 = flag_C;
 319 | 			set_C(c.A&1);
 320 | 			c.A = (c.A >> 1) | (t2<<7);
 321 | 			set_Z(!c.A);
 322 | 		break;
 323 | 	}
 324 | 	set_N(0);
 325 | 	set_H(0);
 326 | }
 327 | 
 328 | static void SLA(uint8_t reg)
 329 | {
 330 | 	uint8_t t;
 331 | 
 332 | 	switch(reg)
 333 | 	{
 334 | 		case 0: /* B */
 335 | 			set_C(!!(c.B & 0x80));
 336 | 			c.B = c.B << 1;
 337 | 			set_Z(!c.B);
 338 | 		break;
 339 | 		case 1: /* C */
 340 | 			set_C(!!(c.C & 0x80));
 341 | 			c.C = c.C << 1;
 342 | 			set_Z(!c.C);
 343 | 		break;
 344 | 		case 2: /* D */
 345 | 			set_C(!!(c.D & 0x80));
 346 | 			c.D = c.D << 1;
 347 | 			set_Z(!c.D);
 348 | 		break;
 349 | 		case 3: /* E */
 350 | 			set_C(!!(c.E & 0x80));
 351 | 			c.E = c.E << 1;
 352 | 			set_Z(!c.E);
 353 | 		break;
 354 | 		case 4: /* H */
 355 | 			set_C(!!(c.H & 0x80));
 356 | 			c.H = c.H << 1;
 357 | 			set_Z(!c.H);
 358 | 		break;
 359 | 		case 5: /* L */
 360 | 			set_C(!!(c.L & 0x80));
 361 | 			c.L = c.L << 1;
 362 | 			set_Z(!c.L);
 363 | 		break;
 364 | 		case 6: /* (HL) */
 365 | 			t = mem_get_byte(get_HL());
 366 | 			set_C(!!(t & 0x80));
 367 | 			t = t << 1;
 368 | 			mem_write_byte(get_HL(), t);
 369 | 			set_Z(!t);
 370 | 			c.cycles += 2;
 371 | 		break;
 372 | 		case 7: /* A */
 373 | 			set_C(!!(c.A & 0x80));
 374 | 			c.A = c.A << 1;
 375 | 			set_Z(!c.A);
 376 | 		break;
 377 | 	}
 378 | 
 379 | 	set_H(0);
 380 | 	set_N(0);
 381 | }
 382 | 
 383 | static void SRA(uint8_t reg)
 384 | {
 385 | 	uint8_t old, t;
 386 | 
 387 | 	switch(reg)
 388 | 	{
 389 | 		case 0: /* B */
 390 | 			set_C(c.B&1);
 391 | 			old = c.B&0x80;
 392 | 			c.B = c.B >> 1 | old;
 393 | 			set_Z(!c.B);
 394 | 		break;
 395 | 		case 1: /* C */
 396 | 			set_C(c.C&1);
 397 | 			old = c.C&0x80;
 398 | 			c.C = c.C >> 1 | old;
 399 | 			set_Z(!c.C);
 400 | 		break;
 401 | 		case 2: /* D */
 402 | 			set_C(c.D&1);
 403 | 			old = c.D&0x80;
 404 | 			c.D = c.D >> 1 | old;
 405 | 			set_Z(!c.D);
 406 | 		break;
 407 | 		case 3: /* E */
 408 | 			set_C(c.E&1);
 409 | 			old = c.E&0x80;
 410 | 			c.E = c.E >> 1 | old;
 411 | 			set_Z(!c.E);
 412 | 		break;
 413 | 		case 4: /* H */
 414 | 			set_C(c.H&1);
 415 | 			old = c.H&0x80;
 416 | 			c.H = c.H >> 1 | old;
 417 | 			set_Z(!c.H);
 418 | 		break;
 419 | 		case 5: /* L */
 420 | 			set_C(c.L&1);
 421 | 			old = c.L&0x80;
 422 | 			c.L = c.L >> 1 | old;
 423 | 			set_Z(!c.L);
 424 | 		break;
 425 | 		case 6: /* (HL) */
 426 | 			t = mem_get_byte(get_HL());
 427 | 			set_C(t&1);
 428 | 			old = t&0x80;
 429 | 			t = t >> 1 | old;
 430 | 			mem_write_byte(get_HL(), t);
 431 | 			set_Z(!t);
 432 | 			c.cycles += 2;
 433 | 		break;
 434 | 		case 7: /* A */
 435 | 			set_C(c.A&1);
 436 | 			old = c.A&0x80;
 437 | 			c.A = c.A >> 1 | old;
 438 | 			set_Z(!c.A);
 439 | 		break;
 440 | 	}
 441 | 
 442 | 	set_H(0);
 443 | 	set_N(0);
 444 | }
 445 | 
 446 | static void SRL(uint8_t reg)
 447 | {
 448 | 	uint8_t t;
 449 | 
 450 | 	switch(reg)
 451 | 	{
 452 | 		case 0: /* B */
 453 | 			set_C(c.B & 1);
 454 | 			c.B = c.B >> 1;
 455 | 			set_Z(!c.B);
 456 | 		break;
 457 | 		case 1: /* C */
 458 | 			set_C(c.C & 1);
 459 | 			c.C = c.C >> 1;
 460 | 			set_Z(!c.C);
 461 | 		break;
 462 | 		case 2: /* D */
 463 | 			set_C(c.D & 1);
 464 | 			c.D = c.D >> 1;
 465 | 			set_Z(!c.D);
 466 | 		break;
 467 | 		case 3: /* E */
 468 | 			set_C(c.E & 1);
 469 | 			c.E = c.E >> 1;
 470 | 			set_Z(!c.E);
 471 | 		break;
 472 | 		case 4: /* H */
 473 | 			set_C(c.H & 1);
 474 | 			c.H = c.H >> 1;
 475 | 			set_Z(!c.H);
 476 | 		break;
 477 | 		case 5: /* L */
 478 | 			set_C(c.L & 1);
 479 | 			c.L = c.L >> 1;
 480 | 			set_Z(!c.L);
 481 | 		break;
 482 | 		case 6: /* (HL) */
 483 | 			t = mem_get_byte(get_HL());
 484 | 			set_C(t & 1);
 485 | 			t = t >> 1;
 486 | 			mem_write_byte(get_HL(), t);
 487 | 			set_Z(!t);
 488 | 			c.cycles += 2;
 489 | 		break;
 490 | 		case 7: /* A */
 491 | 			set_C(c.A & 1);
 492 | 			c.A = c.A >> 1;
 493 | 			set_Z(!c.A);
 494 | 		break;
 495 | 	}
 496 | 
 497 | 	set_H(0);
 498 | 	set_N(0);
 499 | }
 500 | 
 501 | static void SWAP(uint8_t reg)
 502 | {
 503 | 	uint8_t t;
 504 | 
 505 | 	switch(reg)
 506 | 	{
 507 | 		case 0: /* B */
 508 | 			c.B = ((c.B&0xF)<<4) | ((c.B&0xF0)>>4);
 509 | 			c.F = (!c.B)<<7;
 510 | 		break;
 511 | 		case 1: /* C */
 512 | 			c.C = ((c.C&0xF)<<4) | ((c.C&0xF0)>>4);
 513 | 			c.F = (!c.C)<<7;
 514 | 		break;
 515 | 		case 2: /* D */
 516 | 			c.D = ((c.D&0xF)<<4) | ((c.D&0xF0)>>4);
 517 | 			c.F = (!c.D)<<7;
 518 | 		break;
 519 | 		case 3: /* E */
 520 | 			c.E = ((c.E&0xF)<<4) | ((c.E&0xF0)>>4);
 521 | 			c.F = (!c.E)<<7;
 522 | 		break;
 523 | 		case 4: /* H */
 524 | 			c.H = ((c.H&0xF)<<4) | ((c.H&0xF0)>>4);
 525 | 			c.F = (!c.H)<<7;
 526 | 		break;
 527 | 		case 5: /* L */
 528 | 			c.L = ((c.L&0xF)<<4) | ((c.L&0xF0)>>4);
 529 | 			c.F = (!c.L)<<7;
 530 | 		break;
 531 | 		case 6: /* (HL) */
 532 | 			t = mem_get_byte(get_HL());
 533 | 			t = ((t&0xF)<<4) | ((t&0xF0)>>4);
 534 | 			mem_write_byte(get_HL(), t);
 535 | 			c.F = (!t)<<7;
 536 | 			c.cycles += 2;
 537 | 		break;
 538 | 		case 7: /* A */
 539 | 			c.A = ((c.A&0xF)<<4) | ((c.A&0xF0)>>4);
 540 | 			c.F = (!c.A)<<7;
 541 | 		break;
 542 | 	}
 543 | }
 544 | 
 545 | static void BIT_(uint8_t bit, uint8_t reg)
 546 | {
 547 | 	uint8_t t, f = 0 /* Make GCC happy */;
 548 | 
 549 | 	switch(reg)
 550 | 	{
 551 | 		case 0: /* B */
 552 | 		    f = !(c.B & bit);
 553 | 		break;
 554 | 		case 1: /* C */
 555 | 		    f = !(c.C & bit);
 556 | 		break;
 557 | 		case 2: /* D */
 558 | 		    f = !(c.D & bit);
 559 | 		break;
 560 | 		case 3: /* E */
 561 | 		    f = !(c.E & bit);
 562 | 		break;
 563 | 		case 4: /* H */
 564 | 		    f = !(c.H & bit);
 565 | 		break;
 566 | 		case 5: /* L */
 567 | 		    f = !(c.L & bit);
 568 | 		break;
 569 | 		case 6: /* (HL) */
 570 | 			t = mem_get_byte(get_HL());
 571 | 			f = !(t & bit);
 572 | 			c.cycles += 1;
 573 | 		break;
 574 | 		case 7: /* A */
 575 | 		    f = !(c.A & bit);
 576 | 		break;
 577 | 	}
 578 | 
 579 | 	set_Z(f);
 580 | 	set_N(0);
 581 | 	set_H(1);
 582 | }
 583 | 
 584 | static void RES(uint8_t bit, uint8_t reg)
 585 | {
 586 | 	uint8_t t;
 587 | 
 588 | 	switch(reg)
 589 | 	{
 590 | 		case 0: /* B */
 591 | 			c.B &= ~bit;
 592 | 		break;
 593 | 		case 1: /* C */
 594 | 			c.C &= ~bit;
 595 | 		break;
 596 | 		case 2: /* D */
 597 | 			c.D &= ~bit;
 598 | 		break;
 599 | 		case 3: /* E */
 600 | 			c.E &= ~bit;
 601 | 		break;
 602 | 		case 4: /* H */
 603 | 			c.H &= ~bit;
 604 | 		break;
 605 | 		case 5: /* L */
 606 | 			c.L &= ~bit;
 607 | 		break;
 608 | 		case 6: /* (HL) */
 609 | 			t = mem_get_byte(get_HL());
 610 | 			t &= ~bit;
 611 | 			mem_write_byte(get_HL(), t);
 612 | 			c.cycles += 2;
 613 | 		break;
 614 | 		case 7: /* A */
 615 | 			c.A &= ~bit;
 616 | 		break;
 617 | 	}
 618 | }
 619 | 
 620 | static void SET(uint8_t bit, uint8_t reg)
 621 | {
 622 | 	uint8_t t;
 623 | 
 624 | 	switch(reg)
 625 | 	{
 626 | 		case 0: /* B */
 627 | 			c.B |= bit;
 628 | 		break;
 629 | 		case 1: /* C */
 630 | 			c.C |= bit;
 631 | 		break;
 632 | 		case 2: /* D */
 633 | 			c.D |= bit;
 634 | 		break;
 635 | 		case 3: /* E */
 636 | 			c.E |= bit;
 637 | 		break;
 638 | 		case 4: /* H */
 639 | 			c.H |= bit;
 640 | 		break;
 641 | 		case 5: /* L */
 642 | 			c.L |= bit;
 643 | 		break;
 644 | 		case 6: /* (HL) */
 645 | 			t = mem_get_byte(get_HL());
 646 | 			t |= bit;
 647 | 			mem_write_byte(get_HL(), t);
 648 | 			c.cycles += 2;
 649 | 		break;
 650 | 		case 7: /* A */
 651 | 			c.A |= bit;
 652 | 		break;
 653 | 	}
 654 | }
 655 | 
 656 | /*
 657 | 00000xxx = RLC xxx
 658 | 00001xxx = RRC xxx
 659 | 00010xxx = RL xxx
 660 | 00011xxx = RR xxx
 661 | 00100xxx = SLA xxx
 662 | 00101xxx = SRA xxx
 663 | 00110xxx = SWAP xxx
 664 | 00111xxx = SRL xxx
 665 | 01yyyxxx = BIT yyy, xxx
 666 | 10yyyxxx = RES yyy, xxx
 667 | 11yyyxxx = SET yyy, xxx
 668 | */
 669 | static void decode_CB(uint8_t t)
 670 | {
 671 | 	uint8_t reg, opcode, bit;
 672 | 	void (*f[])(uint8_t) = {RLC, RRC, RL, RR, SLA, SRA, SWAP, SRL};
 673 | 	void (*f2[])(uint8_t, uint8_t) = {BIT_, RES, SET};
 674 | 
 675 | 	reg = t&7;
 676 | 	opcode = t>>3;
 677 | 	if(opcode < 8)
 678 | 	{
 679 | 		f[opcode](reg);
 680 | 		return;
 681 | 	}
 682 | 
 683 | 	bit = opcode&7;
 684 | 	opcode >>= 3;
 685 | 	f2[opcode-1](1<<bit, reg);
 686 | 	
 687 | 	c.cycles += 2;
 688 | }
 689 | 
 690 | void cpu_interrupt(uint16_t vector)
 691 | {
 692 | 	c.SP -= 2;
 693 | 	mem_write_word(c.SP, c.PC);
 694 | 	c.PC = vector;
 695 | 	c.cycles += 5 + halted;
 696 | 	halted = 0;
 697 | }
 698 | 
 699 | uint32_t cpu_get_cycles(void)
 700 | {
 701 | 	return c.cycles;
 702 | }
 703 | 
 704 | void cpu_print_debug(void)
 705 | {
 706 | 	printf("%04X: %02X\n", c.PC, mem_get_byte(c.PC));
 707 | 	printf("\tAF: %02X%02X, BC: %02X%02X, DE: %02X%02X, HL: %02X%02X SP: %04X, cycles %d\n",
 708 | 		c.A, c.F, c.B, c.C, c.D, c.E, c.H, c.L, c.SP, c.cycles);
 709 | }
 710 | 
 711 | /* TODO: investigate why blargg's instr_timing test is failing */
 712 | uint32_t cpu_cycle(void)
 713 | {
 714 | 	uint8_t b, t;
 715 | 	uint16_t s;
 716 | 	uint32_t i;
 717 | 	
 718 | 	if(halted)
 719 | 	{
 720 | 		c.cycles += 1;
 721 | 		uint32_t delta = (c.cycles - c.lastcycles);
 722 | 		c.lastcycles = c.cycles;
 723 | 		return delta;
 724 | 	}
 725 | 	
 726 | 	interrupt_flush();
 727 | 
 728 | 	b = mem_get_byte(c.PC);
 729 | 	
 730 | 	if (halt_bug) {
 731 | 		halt_bug = false;
 732 | 	} else {
 733 | 		++c.PC;
 734 | 	}
 735 | 	
 736 | 	switch(b)
 737 | 	{
 738 | 		case 0x00:	/* NOP */
 739 | 			c.cycles += 1;
 740 | 		break;
 741 | 		case 0x01:	/* LD BC, imm16 */
 742 | 			s = mem_get_word(c.PC);
 743 | 			set_BC(s);
 744 | 			c.PC += 2;
 745 | 			c.cycles += 3;
 746 | 		break;
 747 | 		case 0x02:	/* LD (BC), A */
 748 | 			mem_write_byte(get_BC(), c.A);
 749 | 			c.cycles += 2;
 750 | 		break;
 751 | 		case 0x03:	/* INC BC */
 752 | 			set_BC(get_BC()+1);
 753 | 			c.cycles += 2;
 754 | 		break;
 755 | 		case 0x04:	/* INC B */
 756 | 			set_H((c.B&0xF) == 0xF);
 757 | 			c.B++;
 758 | 			set_Z(!c.B);
 759 | 			set_N(0);
 760 | 			c.cycles += 1;
 761 | 		break;
 762 | 		case 0x05:	/* DEC B */
 763 | 			c.B--;
 764 | 			set_Z(!c.B);
 765 | 			set_N(1);
 766 | 			set_H((c.B & 0xF) == 0xF);
 767 | 			c.cycles += 1;
 768 | 		break;
 769 | 		case 0x06:	/* LD B, imm8 */
 770 | 			c.B = mem_get_byte(c.PC++);
 771 | 			c.cycles += 2;
 772 | 		break;
 773 | 		case 0x07:	/* RLCA */
 774 | 			RLC(7);
 775 | 			set_Z(0);
 776 | 			c.cycles += 1;
 777 | 		break;
 778 | 		case 0x08:	/* LD (imm16), SP */
 779 | 			mem_write_word(mem_get_word(c.PC), c.SP);
 780 | 			c.PC += 2;
 781 | 			c.cycles += 5;
 782 | 		break;
 783 | 		case 0x09:	/* ADD HL, BC */
 784 | 			i = get_HL() + get_BC();
 785 | 			set_N(0);
 786 | 			set_C(i >= 0x10000);
 787 | 			set_H((i&0xFFF) < (get_HL()&0xFFF));
 788 | 			set_HL(i&0xFFFF);
 789 | 			c.cycles += 2;
 790 | 		break;
 791 | 		case 0x0A:	/* LD A, (BC) */
 792 | 			c.A = mem_get_byte(get_BC());
 793 | 			c.cycles += 2;
 794 | 		break;
 795 | 		case 0x0B:	/* DEC BC */
 796 | 			s = get_BC();
 797 | 			s--;
 798 | 			set_BC(s);
 799 | 			c.cycles += 2;
 800 | 		break;
 801 | 		case 0x0C:	/* INC C */
 802 | 			set_H((c.C&0xF) == 0xF);
 803 | 			c.C++;
 804 | 			set_Z(!c.C);
 805 | 			set_N(0);
 806 | 			c.cycles += 1;
 807 | 		break;
 808 | 		case 0x0D:	/* DEC C */
 809 | 			set_H((c.C&0xF) == 0);
 810 | 			c.C--;
 811 | 			set_Z(!c.C);
 812 | 			set_N(1);
 813 | 			c.cycles += 1;
 814 | 		break;
 815 | 		case 0x0E:	/* LD C, imm8 */
 816 | 			c.C = mem_get_byte(c.PC++);
 817 | 			c.cycles += 2;
 818 | 		break;
 819 | 		case 0x0F:	/* RRCA */
 820 | 			RRC(7);
 821 | 			set_Z(0);
 822 | 			c.cycles += 1;
 823 | 		break;
 824 | 		case 0x10: /* STOP */
 825 | 			// TODO
 826 | 			c.PC++;
 827 | 			c.cycles += 1;
 828 | 		break;
 829 | 		case 0x11:	/* LD DE, imm16 */
 830 | 			s = mem_get_word(c.PC);
 831 | 			set_DE(s);
 832 | 			c.PC += 2;
 833 | 			c.cycles += 3;
 834 | 		break;
 835 | 		case 0x12:	/* LD (DE), A */
 836 | 			mem_write_byte(get_DE(), c.A);
 837 | 			c.cycles += 2;
 838 | 		break;
 839 | 		case 0x13:	/* INC DE */
 840 | 			s = get_DE();
 841 | 			s++;
 842 | 			set_DE(s);
 843 | 			c.cycles += 2;
 844 | 		break;
 845 | 		case 0x14:	/* INC D */
 846 | 			set_H((c.D&0xF) == 0xF);
 847 | 			c.D++;
 848 | 			set_Z(!c.D);
 849 | 			set_N(0);
 850 | 			c.cycles += 1;
 851 | 		break;
 852 | 		case 0x15:	/* DEC D */
 853 | 			c.D--;
 854 | 			set_Z(!c.D);
 855 | 			set_N(1);
 856 | 			set_H((c.D & 0xF) == 0xF);
 857 | 			c.cycles += 1;
 858 | 		break;
 859 | 		case 0x16:	/* LD D, imm8 */
 860 | 			c.D = mem_get_byte(c.PC++);
 861 | 			c.cycles += 2;
 862 | 		break;
 863 | 		case 0x17:	/* RLA */
 864 | 			RL(7);
 865 | 			set_Z(0);
 866 | 			c.cycles += 1;
 867 | 		break;
 868 | 		case 0x18:	/* JR rel8 */
 869 | 			c.PC += (signed char)mem_get_byte(c.PC) + 1;
 870 | 			c.cycles += 3;
 871 | 		break;
 872 | 		case 0x19:	/* ADD HL, DE */
 873 | 			i = get_HL() + get_DE();
 874 | 			set_H((i&0xFFF) < (get_HL()&0xFFF));
 875 | 			set_HL(i);
 876 | 			set_N(0);
 877 | 			set_C(i > 0xFFFF);
 878 | 			c.cycles += 2;
 879 | 		break;
 880 | 		case 0x1A:	/* LD A, (DE) */
 881 | 			c.A = mem_get_byte(get_DE());
 882 | 			c.cycles += 2;
 883 | 		break;
 884 | 		case 0x1B:	/* DEC DE */
 885 | 			s = get_DE();
 886 | 			s--;
 887 | 			set_DE(s);
 888 | 			c.cycles += 2;
 889 | 		break;
 890 | 		case 0x1C:	/* INC E */
 891 | 			set_H((c.E&0xF) == 0xF);
 892 | 			c.E++;
 893 | 			set_Z(!c.E);
 894 | 			set_N(0);
 895 | 			c.cycles += 1;
 896 | 		break;
 897 | 		case 0x1D:	/* DEC E */
 898 | 			c.E--;
 899 | 			set_Z(!c.E);
 900 | 			set_N(1);
 901 | 			set_H((c.E & 0xF) == 0xF);
 902 | 			c.cycles += 1;
 903 | 		break;
 904 | 		case 0x1E:	/* LD E, imm8 */
 905 | 			c.E = mem_get_byte(c.PC++);
 906 | 			c.cycles += 2;
 907 | 		break;
 908 | 		case 0x1F:	/* RR A */
 909 | 			RR(7);
 910 | 			set_Z(0);
 911 | 			c.cycles += 1;
 912 | 		break;
 913 | 		case 0x20:	/* JR NZ, rel8 */
 914 | 			if(flag_Z == 0)
 915 | 			{
 916 | 				c.PC += (signed char)mem_get_byte(c.PC) + 1;
 917 | 				c.cycles += 3;
 918 | 			} else {
 919 | 				c.PC += 1;
 920 | 				c.cycles += 2;
 921 | 			}
 922 | 		break;
 923 | 		case 0x21:	/* LD HL, imm16 */
 924 | 			s = mem_get_word(c.PC);
 925 | 			set_HL(s);
 926 | 			c.PC += 2;
 927 | 			c.cycles += 3;
 928 | 		break;
 929 | 		case 0x22:	/* LDI (HL), A */
 930 | 			i = get_HL();
 931 | 			mem_write_byte(i, c.A);
 932 | 			i++;
 933 | 			set_HL(i);
 934 | 			c.cycles += 2;
 935 | 		break;
 936 | 		case 0x23:	/* INC HL */
 937 | 			s = get_HL();
 938 | 			s++;
 939 | 			set_HL(s);
 940 | 			c.cycles += 2;
 941 | 		break;
 942 | 		case 0x24:	/* INC H */
 943 | 			c.H++;
 944 | 			set_Z(!c.H);
 945 | 			set_H((c.H&0xF) == 0);
 946 | 			set_N(0);
 947 | 			c.cycles += 1;
 948 | 		break;
 949 | 		case 0x25:	/* DEC H */
 950 | 			c.H--;
 951 | 			set_Z(!c.H);
 952 | 			set_N(1);
 953 | 			set_H((c.H & 0xF) == 0xF);
 954 | 			c.cycles += 1;
 955 | 		break;
 956 | 		case 0x26:	/* LD H, imm8 */
 957 | 			c.H = mem_get_byte(c.PC++);
 958 | 			c.cycles += 2;
 959 | 		break;
 960 | 		case 0x27:	/* DAA */
 961 | 			s = c.A;
 962 | 
 963 | 			if(flag_N)
 964 | 			{
 965 | 				if(flag_H)
 966 | 					s = (s - 0x06)&0xFF;
 967 | 				if(flag_C)
 968 | 					s -= 0x60;
 969 | 			}
 970 | 			else
 971 | 			{
 972 | 				if(flag_H || (s & 0xF) > 9)
 973 | 					s += 0x06;
 974 | 				if(flag_C || s > 0x9F)
 975 | 					s += 0x60;
 976 | 			}
 977 | 
 978 | 			c.A = s;
 979 | 			set_H(0);
 980 | 			set_Z(!c.A);
 981 | 			if(s >= 0x100)
 982 | 				set_C(1);
 983 | 			c.cycles += 1;
 984 | 		break;
 985 | 		case 0x28:	/* JR Z, rel8 */
 986 | 			if(flag_Z == 1)
 987 | 			{
 988 | 				c.PC += (signed char)mem_get_byte(c.PC) + 1;
 989 | 				c.cycles += 3;
 990 | 			} else {
 991 | 				c.PC += 1;
 992 | 				c.cycles += 2;
 993 | 			}
 994 | 		break;
 995 | 		case 0x29:	/* ADD HL, HL */
 996 | 			i = get_HL()*2;
 997 | 			set_H((i&0x7FF) < (get_HL()&0x7FF));
 998 | 			set_C(i > 0xFFFF);
 999 | 			set_HL(i);
1000 | 			set_N(0);
1001 | 			c.cycles += 2;
1002 | 		break;
1003 | 		case 0x2A:	/* LDI A, (HL) */
1004 | 			s = get_HL();
1005 | 			c.A = mem_get_byte(s);
1006 | 			set_HL(s+1);
1007 | 			c.cycles += 2;
1008 | 		break;
1009 | 		case 0x2B: 	/* DEC HL */
1010 | 			set_HL(get_HL()-1);
1011 | 			c.cycles += 2;
1012 | 		break;
1013 | 		case 0x2C:	/* INC L */
1014 | 			c.L++;
1015 | 			set_Z(!c.L);
1016 | 			set_N(0);
1017 | 			set_H((c.L & 0xF) == 0x00);
1018 | 			c.cycles += 1;
1019 | 		break;
1020 | 		case 0x2D:	/* DEC L */
1021 | 			c.L--;
1022 | 			set_Z(!c.L);
1023 | 			set_N(1);
1024 | 			set_H((c.L & 0xF) == 0xF);
1025 | 			c.cycles += 1;
1026 | 		break;
1027 | 		case 0x2E:	/* LD L, imm8 */
1028 | 			c.L = mem_get_byte(c.PC++);
1029 | 			c.cycles += 2;
1030 | 		break;
1031 | 		case 0x2F:	/* CPL */
1032 | 			c.A = ~c.A;
1033 | 			set_N(1);
1034 | 			set_H(1);
1035 | 			c.cycles += 1;
1036 | 		break;
1037 | 		case 0x30:	/* JR NC, rel8 */
1038 | 			if(flag_C == 0)
1039 | 			{
1040 | 				c.PC += (signed char)mem_get_byte(c.PC) + 1;
1041 | 				c.cycles += 3;
1042 | 			} else {
1043 | 				c.PC += 1;
1044 | 				c.cycles += 2;
1045 | 			}
1046 | 		break;
1047 | 		case 0x31:	/* LD SP, imm16 */
1048 | 			c.SP = mem_get_word(c.PC);
1049 | 			c.PC += 2;
1050 | 			c.cycles += 3;
1051 | 		break;
1052 | 		case 0x32:	/* LDD (HL), A */
1053 | 			i = get_HL();
1054 | 			mem_write_byte(i, c.A);
1055 | 			set_HL(i-1);
1056 | 			c.cycles += 2;
1057 | 		break;
1058 | 		case 0x33:	/* INC SP */
1059 | 			c.SP++;
1060 | 			c.cycles += 2;
1061 | 		break;
1062 | 		case 0x34:	/* INC (HL) */
1063 | 			t = mem_get_byte(get_HL());
1064 | 			t++;
1065 | 			mem_write_byte(get_HL(), t);
1066 | 			set_Z(!t);
1067 | 			set_N(0);
1068 | 			set_H((t & 0xF) == 0);
1069 | 			c.cycles += 3;
1070 | 		break;
1071 | 		case 0x35:	/* DEC (HL) */
1072 | 			t = mem_get_byte(get_HL());
1073 | 			t--;
1074 | 			mem_write_byte(get_HL(), t);
1075 | 			set_Z(!t);
1076 | 			set_N(1);
1077 | 			set_H((t & 0xF) == 0xF);
1078 | 			c.cycles += 3;
1079 | 		break;
1080 | 		case 0x36:	/* LD (HL), imm8 */
1081 | 			t = mem_get_byte(c.PC++);
1082 | 			mem_write_byte(get_HL(), t);
1083 | 			c.cycles += 3;
1084 | 		break;
1085 | 		case 0x37:	/* SCF */
1086 | 			set_N(0);
1087 | 			set_H(0);
1088 | 			set_C(1);
1089 | 			c.cycles += 1;
1090 | 		break;
1091 | 		case 0x38:  /* JR C, rel8 */
1092 | 			if(flag_C == 1)
1093 | 			{
1094 | 				c.PC += (signed char)mem_get_byte(c.PC) + 1;
1095 | 				c.cycles += 3;
1096 | 			} else {
1097 | 				c.PC += 1;
1098 | 				c.cycles += 2;
1099 | 			}
1100 | 		break;
1101 | 		case 0x39:	/* ADD HL, SP */
1102 | 			i = get_HL() + c.SP;
1103 | 			set_H((i&0x7FF) < (get_HL()&0x7FF));
1104 | 			set_C(i > 0xFFFF);
1105 | 			set_N(0);
1106 | 			set_HL(i);
1107 | 			c.cycles += 2;
1108 | 		break;
1109 | 		case 0x3A:	/* LDD A, (HL) */
1110 | 			c.A = mem_get_byte(get_HL());
1111 | 			set_HL(get_HL()-1);
1112 | 			c.cycles += 2;
1113 | 		break;
1114 | 		case 0x3B:	/* DEC SP */
1115 | 			c.SP--;
1116 | 			c.cycles += 2;
1117 | 		break;
1118 | 		case 0x3C:	/* INC A */
1119 | 			c.A++;
1120 | 			set_Z(!c.A);
1121 | 			set_H((c.A&0xF) == 0);
1122 | 			set_N(0);
1123 | 			c.cycles += 1;
1124 | 		break;
1125 | 		case 0x3D:	/* DEC A */
1126 | 			c.A--;
1127 | 			set_Z(!c.A);
1128 | 			set_N(1);
1129 | 			set_H((c.A & 0xF) == 0xF);
1130 | 			c.cycles += 1;
1131 | 		break;
1132 | 		case 0x3E:	/* LD A, imm8 */
1133 | 			c.A = mem_get_byte(c.PC++);
1134 | 			c.cycles += 2;
1135 | 		break;
1136 | 		case 0x3F:	/* CCF */
1137 | 			set_N(0);
1138 | 			set_H(0);
1139 | 			set_C(!flag_C);
1140 | 			c.cycles += 1;
1141 | 		break;
1142 | 		case 0x40:	/* LD B, B */
1143 | 			c.B = c.B;
1144 | 			c.cycles += 1;
1145 | 		break;
1146 | 		case 0x41:	/* LD B, C */
1147 | 			c.B = c.C;
1148 | 			c.cycles += 1;
1149 | 		break;
1150 | 		case 0x42:	/* LD B, D */
1151 | 			c.B = c.D;
1152 | 			c.cycles += 1;
1153 | 		break;
1154 | 		case 0x43:	/* LD B, E */
1155 | 			c.B = c.E;
1156 | 			c.cycles += 1;
1157 | 		break;
1158 | 		case 0x44:	/* LD B, H */
1159 | 			c.B = c.H;
1160 | 			c.cycles += 1;
1161 | 		break;
1162 | 		case 0x45:	/* LD B, L */
1163 | 			c.B = c.L;
1164 | 			c.cycles += 1;
1165 | 		break;
1166 | 		case 0x46:	/* LD B, (HL) */
1167 | 			c.B = mem_get_byte(get_HL());
1168 | 			c.cycles += 2;
1169 | 		break;
1170 | 		case 0x47:	/* LD B, A */
1171 | 			c.B = c.A;
1172 | 			c.cycles += 1;
1173 | 		break;
1174 | 		case 0x48:	/* LD C, B */
1175 | 			c.C = c.B;
1176 | 			c.cycles += 1;
1177 | 		break;
1178 | 		case 0x49:	/* LD C, C */
1179 | 			c.C = c.C;
1180 | 			c.cycles += 1;
1181 | 		break;
1182 | 		case 0x4A:	/* LD C, D */
1183 | 			c.C = c.D;
1184 | 			c.cycles += 1;
1185 | 		break;
1186 | 		case 0x4B:	/* LD C, E */
1187 | 			c.C = c.E;
1188 | 			c.cycles += 1;
1189 | 		break;
1190 | 		case 0x4C:	/* LD C, H */
1191 | 			c.C = c.H;
1192 | 			c.cycles += 1;
1193 | 		break;
1194 | 		case 0x4D:	/* LD C, L */
1195 | 			c.C = c.L;
1196 | 			c.cycles += 1;
1197 | 		break;
1198 | 		case 0x4E:	/* LD C, (HL) */
1199 | 			c.C = mem_get_byte(get_HL());
1200 | 			c.cycles += 2;
1201 | 		break;
1202 | 		case 0x4F:	/* LD C, A */
1203 | 			c.C = c.A;
1204 | 			c.cycles += 1;
1205 | 		break;
1206 | 		case 0x50:	/* LD D, B */
1207 | 			c.D = c.B;
1208 | 			c.cycles += 1;
1209 | 		break;
1210 | 		case 0x51:	/* LD D, C */
1211 | 			c.D = c.C;
1212 | 			c.cycles += 1;
1213 | 		break;
1214 | 		case 0x52:	/* LD D, D */
1215 | 			c.D = c.D;
1216 | 			c.cycles += 1;
1217 | 		break;
1218 | 		case 0x53:	/* LD D, E */
1219 | 			c.D = c.E;
1220 | 			c.cycles += 1;
1221 | 		break;
1222 | 		case 0x54:	/* LD D, H */
1223 | 			c.D = c.H;
1224 | 			c.cycles += 1;
1225 | 		break;
1226 | 		case 0x55:	/* LD D, L */
1227 | 			c.D = c.L;
1228 | 			c.cycles += 1;
1229 | 		break;
1230 | 		case 0x56:	/* LD D, (HL) */
1231 | 			c.D = mem_get_byte(get_HL());
1232 | 			c.cycles += 2;
1233 | 		break;
1234 | 		case 0x57:	/* LD D, A */
1235 | 			c.D = c.A;
1236 | 			c.cycles += 1;
1237 | 		break;
1238 | 		case 0x58:	/* LD E, B */
1239 | 			c.E = c.B;
1240 | 			c.cycles += 1;
1241 | 		break;
1242 | 		case 0x59:	/* LD E, C */
1243 | 			c.E = c.C;
1244 | 			c.cycles += 1;
1245 | 		break;
1246 | 		case 0x5A:	/* LD E, D */
1247 | 			c.E = c.D;
1248 | 			c.cycles += 1;
1249 | 		break;
1250 | 		case 0x5B:	/* LD E, E */
1251 | 			c.E = c.E;
1252 | 			c.cycles += 1;
1253 | 		break;
1254 | 		case 0x5C:	/* LD E, H */
1255 | 			c.E = c.H;
1256 | 			c.cycles += 1;
1257 | 		break;
1258 | 		case 0x5D:	/* LD E, L */
1259 | 			c.E = c.L;
1260 | 			c.cycles += 1;
1261 | 		break;
1262 | 		case 0x5E:	/* LD E, (HL) */
1263 | 			c.E = mem_get_byte(get_HL());
1264 | 			c.cycles += 2;
1265 | 		break;
1266 | 		case 0x5F:	/* LD E, A */
1267 | 			c.E = c.A;
1268 | 			c.cycles += 1;
1269 | 		break;
1270 | 		case 0x60:	/* LD H, B */
1271 | 			c.H = c.B;
1272 | 			c.cycles += 1;
1273 | 		break;
1274 | 		case 0x61:	/* LD H, C */
1275 | 			c.H = c.C;
1276 | 			c.cycles += 1;
1277 | 		break;
1278 | 		case 0x62:	/* LD H, D */
1279 | 			c.H = c.D;
1280 | 			c.cycles += 1;
1281 | 		break;
1282 | 		case 0x63:	/* LD H, E */
1283 | 			c.H = c.E;
1284 | 			c.cycles += 1;
1285 | 		break;
1286 | 		case 0x64:	/* LD H, H */
1287 | 			c.H = c.H;
1288 | 			c.cycles += 1;
1289 | 		break;
1290 | 		case 0x65:	/* LD H, L */
1291 | 			c.H = c.L;
1292 | 			c.cycles += 1;
1293 | 		break;
1294 | 		case 0x66:	/* LD H, (HL) */
1295 | 			c.H = mem_get_byte(get_HL());
1296 | 			c.cycles += 2;
1297 | 		break;
1298 | 		case 0x67:	/* LD H, A */
1299 | 			c.H = c.A;
1300 | 			c.cycles += 1;
1301 | 		break;
1302 | 		case 0x68:	/* LD L, B */
1303 | 			c.L = c.B;
1304 | 			c.cycles += 1;
1305 | 		break;
1306 | 		case 0x69:	/* LD L, C */
1307 | 			c.L = c.C;
1308 | 			c.cycles += 1;
1309 | 		break;
1310 | 		case 0x6A:	/* LD L, D */
1311 | 			c.L = c.D;
1312 | 			c.cycles += 1;
1313 | 		break;
1314 | 		case 0x6B:	/* LD L, E */
1315 | 			c.L = c.E;
1316 | 			c.cycles += 1;
1317 | 		break;
1318 | 		case 0x6C:	/* LD L, H */
1319 | 			c.L = c.H;
1320 | 			c.cycles += 1;
1321 | 		break;
1322 | 		case 0x6D:	/* LD L, L */
1323 | 			c.L = c.L;
1324 | 			c.cycles += 1;
1325 | 		break;
1326 | 		case 0x6E:	/* LD L, (HL) */
1327 | 			c.L = mem_get_byte(get_HL());
1328 | 			c.cycles += 2;
1329 | 		break;
1330 | 		case 0x6F:	/* LD L, A */
1331 | 			c.L = c.A;
1332 | 			c.cycles += 1;
1333 | 		break;
1334 | 		case 0x70:	/* LD (HL), B */
1335 | 			mem_write_byte(get_HL(), c.B);
1336 | 			c.cycles += 2;
1337 | 		break;
1338 | 		case 0x71:	/* LD (HL), C */
1339 | 			mem_write_byte(get_HL(), c.C);
1340 | 			c.cycles += 2;
1341 | 		break;
1342 | 		case 0x72:	/* LD (HL), D */
1343 | 			mem_write_byte(get_HL(), c.D);
1344 | 			c.cycles += 2;
1345 | 		break;
1346 | 		case 0x73:	/* LD (HL), E */
1347 | 			mem_write_byte(get_HL(), c.E);
1348 | 			c.cycles += 2;
1349 | 		break;
1350 | 		case 0x74:	/* LD (HL), H */
1351 | 			mem_write_byte(get_HL(), c.H);
1352 | 			c.cycles += 2;
1353 | 		break;
1354 | 		case 0x75:	/* LD (HL), L */
1355 | 			mem_write_byte(get_HL(), c.L);
1356 | 			c.cycles += 2;
1357 | 		break;
1358 | 		case 0x76: {	/* HALT */
1359 | 			if (!IME && (IF & IE & 0x1F)) {
1360 | 				halt_bug = true;
1361 | 			} else {
1362 | 				halted = 1;
1363 | 			}
1364 | 			c.cycles += 1;
1365 | 		}
1366 | 		break;
1367 | 		case 0x77:	/* LD (HL), A */
1368 | 			mem_write_byte(get_HL(), c.A);
1369 | 			c.cycles += 2;
1370 | 		break;
1371 | 		case 0x78:	/* LD A, B */
1372 | 			c.A = c.B;
1373 | 			c.cycles += 1;
1374 | 		break;
1375 | 		case 0x79:	/* LD A, C */
1376 | 			c.A = c.C;
1377 | 			c.cycles += 1;
1378 | 		break;
1379 | 		case 0x7A:	/* LD A, D */
1380 | 			c.A = c.D;
1381 | 			c.cycles += 1;
1382 | 		break;
1383 | 		case 0x7B:	/* LD A, E */
1384 | 			c.A = c.E;
1385 | 			c.cycles += 1;
1386 | 		break;
1387 | 		case 0x7C:	/* LD A, H */
1388 | 			c.A = c.H;
1389 | 			c.cycles += 1;
1390 | 		break;
1391 | 		case 0x7D:	/* LD A, L */
1392 | 			c.A = c.L;
1393 | 			c.cycles += 1;
1394 | 		break;
1395 | 		case 0x7E:	/* LD A, (HL) */
1396 | 			c.A = mem_get_byte(get_HL());
1397 | 			c.cycles += 2;
1398 | 		break;
1399 | 		case 0x7F:	/* LD A, A */
1400 | 			c.A = c.A;
1401 | 			c.cycles += 1;
1402 | 		break;
1403 | 		case 0x80:	/* ADD B */
1404 | 			i = c.A + c.B;
1405 | 			set_H((c.A&0xF)+(c.B&0xF) > 0xF);
1406 | 			set_C(i > 0xFF);
1407 | 			set_N(0);
1408 | 			c.A = i;
1409 | 			set_Z(!c.A);
1410 | 			c.cycles += 1;
1411 | 		break;
1412 | 		case 0x81:	/* ADD C */
1413 | 			i = c.A + c.C;
1414 | 			set_H((c.A&0xF)+(c.C&0xF) > 0xF);
1415 | 			set_C(i > 0xFF);
1416 | 			set_N(0);
1417 | 			c.A = i;
1418 | 			set_Z(!c.A);
1419 | 			c.cycles += 1;
1420 | 		break;
1421 | 		case 0x82:	/* ADD D */
1422 | 			i = c.A + c.D;
1423 | 			set_H((c.A&0xF)+(c.D&0xF) > 0xF);
1424 | 			set_C(i > 0xFF);
1425 | 			set_N(0);
1426 | 			c.A = i;
1427 | 			set_Z(!c.A);
1428 | 			c.cycles += 1;
1429 | 		break;
1430 | 		case 0x83:	/* ADD E */
1431 | 			i = c.A + c.E;
1432 | 			set_H((c.A&0xF)+(c.E&0xF) > 0xF);
1433 | 			set_C(i > 0xFF);
1434 | 			set_N(0);
1435 | 			c.A = i;
1436 | 			set_Z(!c.A);
1437 | 			c.cycles += 1;
1438 | 		break;
1439 | 		case 0x84:	/* ADD H */
1440 | 			i = c.A + c.H;
1441 | 			set_H((c.A&0xF)+(c.H&0xF) > 0xF);
1442 | 			set_C(i > 0xFF);
1443 | 			set_N(0);
1444 | 			c.A = i;
1445 | 			set_Z(!c.A);
1446 | 			c.cycles += 1;
1447 | 		break;
1448 | 		case 0x85:	/* ADD L */
1449 | 			i = c.A + c.L;
1450 | 			set_H((c.A&0xF)+(c.L&0xF) > 0xF);
1451 | 			set_C(i > 0xFF);
1452 | 			set_N(0);
1453 | 			c.A = i;
1454 | 			set_Z(!c.A);
1455 | 			c.cycles += 1;
1456 | 		break;
1457 | 		case 0x86:	/* ADD (HL) */
1458 | 			i = c.A + mem_get_byte(get_HL());
1459 | 			set_H((i&0xF) < (c.A&0xF));
1460 | 			set_C(i > 0xFF);
1461 | 			set_N(0);
1462 | 			c.A = i;
1463 | 			set_Z(!c.A);
1464 | 			c.cycles += 2;
1465 | 		break;
1466 | 		case 0x87:	/* ADD A */
1467 | 			i = c.A + c.A;
1468 | 			set_H((c.A&0xF)+(c.A&0xF) > 0xF);
1469 | 			set_C(i > 0xFF);
1470 | 			set_N(0);
1471 | 			c.A = i;
1472 | 			set_Z(!c.A);
1473 | 			c.cycles += 1;
1474 | 		break;
1475 | 		case 0x88:	/* ADC B */
1476 | 			i = c.A + c.B + flag_C >= 0x100;
1477 | 			set_N(0);
1478 | 			set_H(((c.A&0xF) + (c.B&0xF) + flag_C) >= 0x10);
1479 | 			c.A = c.A + c.B + flag_C;
1480 | 			set_C(i);
1481 | 			set_Z(!c.A);
1482 | 			c.cycles += 1;
1483 | 		break;
1484 | 		case 0x89:	/* ADC C */
1485 | 			i = c.A + c.C + flag_C >= 0x100;
1486 | 			set_N(0);
1487 | 			set_H(((c.A&0xF) + (c.C&0xF) + flag_C) >= 0x10);
1488 | 			c.A = c.A + c.C + flag_C;
1489 | 			set_C(i);
1490 | 			set_Z(!c.A);
1491 | 			c.cycles += 1;
1492 | 		break;
1493 | 		case 0x8A:	/* ADC D */
1494 | 			i = c.A + c.D + flag_C >= 0x100;
1495 | 			set_N(0);
1496 | 			set_H(((c.A&0xF) + (c.D&0xF) + flag_C) >= 0x10);
1497 | 			c.A = c.A + c.D + flag_C;
1498 | 			set_C(i);
1499 | 			set_Z(!c.A);
1500 | 			c.cycles += 1;
1501 | 		break;
1502 | 		case 0x8B:	/* ADC E */
1503 | 			i = c.A + c.E + flag_C >= 0x100;
1504 | 			set_N(0);
1505 | 			set_H(((c.A&0xF) + (c.E&0xF) + flag_C) >= 0x10);
1506 | 			c.A = c.A + c.E + flag_C;
1507 | 			set_C(i);
1508 | 			set_Z(!c.A);
1509 | 			c.cycles += 1;
1510 | 		break;
1511 | 		case 0x8C:	/* ADC H */
1512 | 			i = c.A + c.H + flag_C >= 0x100;
1513 | 			set_N(0);
1514 | 			set_H(((c.A&0xF) + (c.H&0xF) + flag_C) >= 0x10);
1515 | 			c.A = c.A + c.H + flag_C;
1516 | 			set_C(i);
1517 | 			set_Z(!c.A);
1518 | 			c.cycles += 1;
1519 | 		break;
1520 | 		case 0x8D:	/* ADC L */
1521 | 			i = c.A + c.L + flag_C >= 0x100;
1522 | 			set_N(0);
1523 | 			set_H(((c.A&0xF) + (c.L&0xF) + flag_C) >= 0x10);
1524 | 			c.A = c.A + c.L + flag_C;
1525 | 			set_C(i);
1526 | 			set_Z(!c.A);
1527 | 			c.cycles += 1;
1528 | 		break;
1529 | 		case 0x8E:	/* ADC (HL) */
1530 | 			t = mem_get_byte(get_HL());
1531 | 			i = c.A + t + flag_C >= 0x100;
1532 | 			set_N(0);
1533 | 			set_H(((c.A&0xF) + (t&0xF) + flag_C) >= 0x10);
1534 | 			c.A = c.A + t + flag_C;
1535 | 			set_C(i);
1536 | 			set_Z(!c.A);
1537 | 			c.cycles += 2;
1538 | 		break;
1539 | 		case 0x8F:	/* ADC A */
1540 | 			i = c.A + c.A + flag_C >= 0x100;
1541 | 			set_N(0);
1542 | 			set_H(((c.A&0xF) + (c.A&0xF) + flag_C) >= 0x10);
1543 | 			c.A = c.A + c.A + flag_C;
1544 | 			set_C(i);
1545 | 			set_Z(!c.A);
1546 | 			c.cycles += 1;
1547 | 		break;
1548 | 		case 0x90:	/* SUB B */
1549 | 			set_C((c.A - c.B) < 0);
1550 | 			set_H(((c.A - c.B)&0xF) > (c.A&0xF));
1551 | 			c.A -= c.B;
1552 | 			set_Z(!c.A);
1553 | 			set_N(1);
1554 | 			c.cycles += 1;
1555 | 		break;
1556 | 		case 0x91:	/* SUB C */
1557 | 			set_C((c.A - c.C) < 0);
1558 | 			set_H(((c.A - c.C)&0xF) > (c.A&0xF));
1559 | 			c.A -= c.C;
1560 | 			set_Z(!c.A);
1561 | 			set_N(1);
1562 | 			c.cycles += 1;
1563 | 		break;
1564 | 		case 0x92:	/* SUB D */
1565 | 			set_C((c.A - c.D) < 0);
1566 | 			set_H(((c.A - c.D)&0xF) > (c.A&0xF));
1567 | 			c.A -= c.D;
1568 | 			set_Z(!c.A);
1569 | 			set_N(1);
1570 | 			c.cycles += 1;
1571 | 		break;
1572 | 		case 0x93:	/* SUB E */
1573 | 			set_C((c.A - c.E) < 0);
1574 | 			set_H(((c.A - c.E)&0xF) > (c.A&0xF));
1575 | 			c.A -= c.E;
1576 | 			set_Z(!c.A);
1577 | 			set_N(1);
1578 | 			c.cycles += 1;
1579 | 		break;
1580 | 		case 0x94:	/* SUB H */
1581 | 			set_C((c.A - c.H) < 0);
1582 | 			set_H(((c.A - c.H)&0xF) > (c.A&0xF));
1583 | 			c.A -= c.H;
1584 | 			set_Z(!c.A);
1585 | 			set_N(1);
1586 | 			c.cycles += 1;
1587 | 		break;
1588 | 		case 0x95:	/* SUB L */
1589 | 			set_C((c.A - c.L) < 0);
1590 | 			set_H(((c.A - c.L)&0xF) > (c.A&0xF));
1591 | 			c.A -= c.L;
1592 | 			set_Z(!c.A);
1593 | 			set_N(1);
1594 | 			c.cycles += 1;
1595 | 		break;
1596 | 		case 0x96:	/* SUB (HL) */
1597 | 			t = mem_get_byte(get_HL());
1598 | 			set_C((c.A - t) < 0);
1599 | 			set_H(((c.A - t)&0xF) > (c.A&0xF));
1600 | 			c.A -= t;
1601 | 			set_Z(!c.A);
1602 | 			set_N(1);
1603 | 			c.cycles += 2;
1604 | 		break;
1605 | 		case 0x97:	/* SUB A */
1606 | 			set_C(0);
1607 | 			set_H(0);
1608 | 			c.A = 0;
1609 | 			set_Z(1);
1610 | 			set_N(1);
1611 | 			c.cycles += 1;
1612 | 		break;
1613 | 		case 0x98:	/* SBC B */
1614 | 			t = flag_C + c.B;
1615 | 			set_H(((c.A&0xF) - (c.B&0xF) - flag_C) < 0);
1616 | 			set_C((c.A - c.B - flag_C) < 0);
1617 | 			set_N(1);
1618 | 			c.A -= t;
1619 | 			set_Z(!c.A);
1620 | 			c.cycles += 1;
1621 | 		break;
1622 | 		case 0x99:	/* SBC C */
1623 | 			t = flag_C + c.C;
1624 | 			set_H(((c.A&0xF) - (c.C&0xF) - flag_C) < 0);
1625 | 			set_C((c.A - c.C - flag_C) < 0);
1626 | 			set_N(1);
1627 | 			c.A -= t;
1628 | 			set_Z(!c.A);
1629 | 			c.cycles += 1;
1630 | 		break;
1631 | 		case 0x9A:	/* SBC D */
1632 | 			t = flag_C + c.D;
1633 | 			set_H(((c.A&0xF) - (c.D&0xF) - flag_C) < 0);
1634 | 			set_C((c.A - c.D - flag_C) < 0);
1635 | 			set_N(1);
1636 | 			c.A -= t;
1637 | 			set_Z(!c.A);
1638 | 			c.cycles += 1;
1639 | 		break;
1640 | 		case 0x9B:	/* SBC E */
1641 | 			t = flag_C + c.E;
1642 | 			set_H(((c.A&0xF) - (c.E&0xF) - flag_C) < 0);
1643 | 			set_C((c.A - c.E - flag_C) < 0);
1644 | 			set_N(1);
1645 | 			c.A -= t;
1646 | 			set_Z(!c.A);
1647 | 			c.cycles += 1;
1648 | 		break;
1649 | 		case 0x9C:	/* SBC H */
1650 | 			t = flag_C + c.H;
1651 | 			set_H(((c.A&0xF) - (c.H&0xF) - flag_C) < 0);
1652 | 			set_C((c.A - c.H - flag_C) < 0);
1653 | 			set_N(1);
1654 | 			c.A -= t;
1655 | 			set_Z(!c.A);
1656 | 			c.cycles += 1;
1657 | 		break;
1658 | 		case 0x9D:	/* SBC L */
1659 | 			t = flag_C + c.L;
1660 | 			set_H(((c.A&0xF) - (c.L&0xF) - flag_C) < 0);
1661 | 			set_C((c.A - c.L - flag_C) < 0);
1662 | 			set_N(1);
1663 | 			c.A -= t;
1664 | 			set_Z(!c.A);
1665 | 			c.cycles += 1;
1666 | 		break;
1667 | 		case 0x9E:	/* SBC (HL) */
1668 | 			t = mem_get_byte(get_HL());
1669 | 			b = flag_C + t;
1670 | 			set_H(((c.A&0xF) - (t&0xF) - flag_C) < 0);
1671 | 			set_C((c.A - t - flag_C) < 0);
1672 | 			set_N(1);
1673 | 			c.A -= b;
1674 | 			set_Z(!c.A);
1675 | 			c.cycles += 2;
1676 | 		break;
1677 | 		case 0x9F:	/* SBC A */
1678 | 			t = flag_C + c.A;
1679 | 			set_H(((c.A&0xF) - (c.A&0xF) - flag_C) < 0);
1680 | 			set_C((c.A - c.A - flag_C) < 0);
1681 | 			set_N(1);
1682 | 			c.A -= t;
1683 | 			set_Z(!c.A);
1684 | 			c.cycles += 1;
1685 | 		break;
1686 | 		case 0xA0:	/* AND B */
1687 | 			c.A &= c.B;
1688 | 			set_Z(!c.A);
1689 | 			set_H(1);
1690 | 			set_N(0);
1691 | 			set_C(0);
1692 | 			c.cycles += 1;
1693 | 		break;
1694 | 		case 0xA1:	/* AND C */
1695 | 			c.A &= c.C;
1696 | 			set_Z(!c.A);
1697 | 			set_H(1);
1698 | 			set_N(0);
1699 | 			set_C(0);
1700 | 			c.cycles += 1;
1701 | 		break;
1702 | 		case 0xA2:	/* AND D */
1703 | 			c.A &= c.D;
1704 | 			set_Z(!c.A);
1705 | 			set_H(1);
1706 | 			set_N(0);
1707 | 			set_C(0);
1708 | 			c.cycles += 1;
1709 | 		break;
1710 | 		case 0xA3:	/* AND E */
1711 | 			c.A &= c.E;
1712 | 			set_Z(!c.A);
1713 | 			set_H(1);
1714 | 			set_N(0);
1715 | 			set_C(0);
1716 | 			c.cycles += 1;
1717 | 		break;
1718 | 		case 0xA4:	/* AND H */
1719 | 			c.A &= c.H;
1720 | 			set_Z(!c.A);
1721 | 			set_H(1);
1722 | 			set_N(0);
1723 | 			set_C(0);
1724 | 			c.cycles += 1;
1725 | 		break;
1726 | 		case 0xA5:	/* AND L */
1727 | 			c.A &= c.L;
1728 | 			set_Z(!c.A);
1729 | 			set_H(1);
1730 | 			set_N(0);
1731 | 			set_C(0);
1732 | 			c.cycles += 1;
1733 | 		break;
1734 | 		case 0xA6:	/* AND (HL) */
1735 | 			c.A &= mem_get_byte(get_HL());
1736 | 			set_Z(!c.A);
1737 | 			set_H(1);
1738 | 			set_N(0);
1739 | 			set_C(0);
1740 | 			c.cycles += 2;
1741 | 		break;
1742 | 		case 0xA7:	/* AND A */
1743 | 			set_H(1);
1744 | 			set_N(0);
1745 | 			set_C(0);
1746 | 			set_Z(!c.A);
1747 | 			c.cycles += 1;
1748 | 		break;
1749 | 		case 0xA8:	/* XOR B */
1750 | 			c.A ^= c.B;
1751 | 			c.F = (!c.A)<<7;
1752 | 			c.cycles += 1;
1753 | 		break;
1754 | 		case 0xA9:	/* XOR C */
1755 | 			c.A ^= c.C;
1756 | 			c.F = (!c.A)<<7;
1757 | 			c.cycles += 1;
1758 | 		break;
1759 | 		case 0xAA:	/* XOR D */
1760 | 			c.A ^= c.D;
1761 | 			c.F = (!c.A)<<7;
1762 | 			c.cycles += 1;
1763 | 		break;
1764 | 		case 0xAB:	/* XOR E */
1765 | 			c.A ^= c.E;
1766 | 			c.F = (!c.A)<<7;
1767 | 			c.cycles += 1;
1768 | 		break;
1769 | 		case 0xAC:	/* XOR H */
1770 | 			c.A ^= c.H;
1771 | 			c.F = (!c.A)<<7;
1772 | 			c.cycles += 1;
1773 | 		break;
1774 | 		case 0xAD:	/* XOR L */
1775 | 			c.A ^= c.L;
1776 | 			c.F = (!c.A)<<7;
1777 | 			c.cycles += 1;
1778 | 		break;
1779 | 		case 0xAE:	/* XOR (HL) */
1780 | 			c.A ^= mem_get_byte(get_HL());
1781 | 			c.F = (!c.A)<<7;
1782 | 			c.cycles += 2;
1783 | 		break;
1784 | 		case 0xAF:	/* XOR A */
1785 | 			c.A = 0;
1786 | 			c.F = 0x80;
1787 | 			c.cycles += 1;
1788 | 		break;
1789 | 		case 0xB0:	/* OR B */
1790 | 			c.A |= c.B;
1791 | 			c.F = (!c.A)<<7;
1792 | 			c.cycles += 1;
1793 | 		break;
1794 | 		case 0xB1:	/* OR C */
1795 | 			c.A |= c.C;
1796 | 			c.F = (!c.A)<<7;
1797 | 			c.cycles += 1;
1798 | 		break;
1799 | 		case 0xB2:	/* OR D */
1800 | 			c.A |= c.D;
1801 | 			c.F = (!c.A)<<7;
1802 | 			c.cycles += 1;
1803 | 		break;
1804 | 		case 0xB3:	/* OR E */
1805 | 			c.A |= c.E;
1806 | 			c.F = (!c.A)<<7;
1807 | 			c.cycles += 1;
1808 | 		break;
1809 | 		case 0xB4:	/* OR H */
1810 | 			c.A |= c.H;
1811 | 			c.F = (!c.A)<<7;
1812 | 			c.cycles += 1;
1813 | 		break;
1814 | 		case 0xB5:	/* OR L */
1815 | 			c.A |= c.L;
1816 | 			c.F = (!c.A)<<7;
1817 | 			c.cycles += 1;
1818 | 		break;
1819 | 		case 0xB6:	/* OR (HL) */
1820 | 			c.A |= mem_get_byte(get_HL());
1821 | 			c.F = (!c.A)<<7;
1822 | 			c.cycles += 2;
1823 | 		break;
1824 | 		case 0xB7:	/* OR A */
1825 | 			c.F = (!c.A)<<7;
1826 | 			c.cycles += 1;
1827 | 		break;
1828 | 		case 0xB8:	/* CP B */
1829 | 			set_C((c.A - c.B) < 0);
1830 | 			set_H(((c.A - c.B)&0xF) > (c.A&0xF));
1831 | 			set_Z(c.A == c.B);
1832 | 			set_N(1);
1833 | 			c.cycles += 1;
1834 | 		break;
1835 | 		case 0xB9:	/* CP C */
1836 | 			set_Z(c.A == c.C);
1837 | 			set_H(((c.A - c.C)&0xF) > (c.A&0xF));
1838 | 			set_N(1);
1839 | 			set_C((c.A - c.C) < 0);
1840 | 			c.cycles += 1;
1841 | 		break;
1842 | 		case 0xBA:	/* CP D */
1843 | 			set_Z(c.A == c.D);
1844 | 			set_H(((c.A - c.D)&0xF) > (c.A&0xF));
1845 | 			set_N(1);
1846 | 			set_C((c.A - c.D) < 0);
1847 | 			c.cycles += 1;
1848 | 		break;
1849 | 		case 0xBB:	/* CP E */
1850 | 			set_Z(c.A == c.E);
1851 | 			set_H(((c.A - c.E)&0xF) > (c.A&0xF));
1852 | 			set_N(1);
1853 | 			set_C((c.A - c.E) < 0);
1854 | 			c.cycles += 1;
1855 | 		break;
1856 | 		case 0xBC:	/* CP H */
1857 | 			set_Z(c.A == c.H);
1858 | 			set_H(((c.A - c.H)&0xF) > (c.A&0xF));
1859 | 			set_N(1);
1860 | 			set_C((c.A - c.H) < 0);
1861 | 			c.cycles += 1;
1862 | 		break;
1863 | 		case 0xBD:	/* CP L */
1864 | 			set_Z(c.A == c.L);
1865 | 			set_H(((c.A - c.L)&0xF) > (c.A&0xF));
1866 | 			set_N(1);
1867 | 			set_C((c.A - c.L) < 0);
1868 | 			c.cycles += 1;
1869 | 		break;
1870 | 		case 0xBE:	/* CP (HL) */
1871 | 			t = mem_get_byte(get_HL());
1872 | 			set_Z(c.A == t);
1873 | 			set_H(((c.A - t)&0xF) > (c.A&0xF));
1874 | 			set_N(1);
1875 | 			set_C((c.A - t) < 0);
1876 | 			c.cycles += 2;
1877 | 		break;
1878 | 		case 0xBF:	/* CP A */
1879 | 			set_Z(1);
1880 | 			set_H(0);
1881 | 			set_N(1);
1882 | 			set_C(0);
1883 | 			c.cycles += 1;
1884 | 		break;
1885 | 		case 0xC0:	/* RET NZ */
1886 | 			if(!flag_Z)
1887 | 			{
1888 | 				c.PC = mem_get_word(c.SP);
1889 | 				c.SP += 2;
1890 | 				c.cycles += 5;
1891 | 			} else {
1892 | 				c.cycles += 2;
1893 | 			}
1894 | 		break;
1895 | 		case 0xC1:	/* POP BC */
1896 | 			s = mem_get_word(c.SP);
1897 | 			set_BC(s);
1898 | 			c.SP += 2;
1899 | 			c.cycles += 3;
1900 | 		break;
1901 | 		case 0xC2:	/* JP NZ, mem16 */
1902 | 			if(flag_Z == 0)
1903 | 			{
1904 | 				c.PC = mem_get_word(c.PC);
1905 | 				c.cycles += 4;
1906 | 			} else {
1907 | 				c.PC += 2;
1908 | 				c.cycles += 3;
1909 | 			}
1910 | 		break;
1911 | 		case 0xC3:	/* JP imm16 */
1912 | 			c.PC = mem_get_word(c.PC);
1913 | 			c.cycles += 4;
1914 | 		break;
1915 | 		case 0xC4:	/* CALL NZ, imm16 */
1916 | 			if(flag_Z == 0)
1917 | 			{
1918 | 				c.SP -= 2;
1919 | 				mem_write_word(c.SP, c.PC+2);
1920 | 				c.PC = mem_get_word(c.PC);
1921 | 				c.cycles += 6;
1922 | 			} else {
1923 | 				c.PC += 2;
1924 | 				c.cycles += 3;
1925 | 			}
1926 | 		break;
1927 | 		case 0xC5:	/* PUSH BC */
1928 | 			c.SP -= 2;
1929 | 			mem_write_word(c.SP, get_BC());
1930 | 			c.cycles += 4;
1931 | 		break;
1932 | 		case 0xC6:	/* ADD A, imm8 */
1933 | 			t = mem_get_byte(c.PC++);
1934 | 			set_C((c.A + t) >= 0x100);
1935 | 			set_H(((c.A + t)&0xF) < (c.A&0xF));
1936 | 			c.A += t;
1937 | 			set_N(0);
1938 | 			set_Z(!c.A);
1939 | 			c.cycles += 2;
1940 | 		break;
1941 | 		case 0xC7:	/* RST 00 */
1942 | 			c.SP -= 2;
1943 | 			mem_write_word(c.SP, c.PC);
1944 | 			c.PC = 0;
1945 | 			c.cycles += 4;
1946 | 		break;
1947 | 		case 0xC8:	/* RET Z */
1948 | 			if(flag_Z == 1)
1949 | 			{
1950 | 				c.PC = mem_get_word(c.SP);
1951 | 				c.SP += 2;
1952 | 				c.cycles += 5;
1953 | 			} else {
1954 | 				c.cycles += 2;
1955 | 			}
1956 | 		break;
1957 | 		case 0xC9:	/* RET */
1958 | 			c.PC = mem_get_word(c.SP);
1959 | 			c.SP += 2;
1960 | 			c.cycles += 4;
1961 | 		break;
1962 | 		case 0xCA:	/* JP z, mem16 */
1963 | 			if(flag_Z == 1)
1964 | 			{
1965 | 				c.PC = mem_get_word(c.PC);
1966 | 				c.cycles += 4;
1967 | 			} else {
1968 | 				c.PC += 2;
1969 | 				c.cycles += 3;
1970 | 			}
1971 | 		break;
1972 | 		case 0xCB:	/* RLC/RRC/RL/RR/SLA/SRA/SWAP/SRL/BIT/RES/SET */
1973 | 			decode_CB(mem_get_byte(c.PC++));
1974 | 			c.cycles += 1;
1975 | 		break;
1976 | 		case 0xCC:	/* CALL Z, imm16 */
1977 | 			if(flag_Z == 1)
1978 | 			{
1979 | 				c.SP -= 2;
1980 | 				mem_write_word(c.SP, c.PC+2);
1981 | 				c.PC = mem_get_word(c.PC);
1982 | 				c.cycles += 6;
1983 | 			} else {
1984 | 				c.PC += 2;
1985 | 				c.cycles += 3;
1986 | 			}
1987 | 		break;
1988 | 		case 0xCD:	/* call imm16 */
1989 | 			c.SP -= 2;
1990 | 			mem_write_word(c.SP, c.PC+2);
1991 | 			c.PC = mem_get_word(c.PC);
1992 | 			c.cycles += 6;
1993 | 		break;
1994 | 		case 0xCE:	/* ADC a, imm8 */
1995 | 			t = mem_get_byte(c.PC++);
1996 | 			i = c.A + t + flag_C >= 0x100;
1997 | 			set_N(0);
1998 | 			set_H(((c.A&0xF) + (t&0xF) + flag_C) >= 0x10);
1999 | 			c.A = c.A + t + flag_C;
2000 | 			set_C(i);
2001 | 			set_Z(!c.A);
2002 | 			c.cycles += 2;
2003 | 		break;
2004 | 		case 0xCF:	/* RST 08 */
2005 | 			c.SP -= 2;
2006 | 			mem_write_word(c.SP, c.PC);
2007 | 			c.PC = 0x0008;
2008 | 			c.cycles += 4;
2009 | 		break;
2010 | 		case 0xD0:	/* RET NC */
2011 | 			if(flag_C == 0)
2012 | 			{
2013 | 				c.PC = mem_get_word(c.SP);
2014 | 				c.SP += 2;
2015 | 				c.cycles += 5;
2016 | 			} else {
2017 | 				c.cycles += 2;
2018 | 			}
2019 | 		break;
2020 | 		case 0xD1:	/* POP DE */
2021 | 			s = mem_get_word(c.SP);
2022 | 			set_DE(s);
2023 | 			c.SP += 2;
2024 | 			c.cycles += 3;
2025 | 		break;
2026 | 		case 0xD2:	/* JP NC, mem16 */
2027 | 			if(flag_C == 0)
2028 | 			{
2029 | 				c.PC = mem_get_word(c.PC);
2030 | 				c.cycles += 4;
2031 | 			} else {
2032 | 				c.PC += 2;
2033 | 				c.cycles += 3;
2034 | 			}
2035 | 		break;
2036 | 		case 0xD4:	/* CALL NC, mem16 */
2037 | 			if(flag_C == 0)
2038 | 			{
2039 | 				c.SP -= 2;
2040 | 				mem_write_word(c.SP, c.PC+2);
2041 | 				c.PC = mem_get_word(c.PC);
2042 | 				c.cycles += 6;
2043 | 			} else {
2044 | 				c.PC += 2;
2045 | 				c.cycles += 3;
2046 | 			}
2047 | 		break;
2048 | 		case 0xD5:	/* PUSH DE */
2049 | 			c.SP -= 2;
2050 | 			mem_write_word(c.SP, get_DE());
2051 | 			c.cycles += 4;
2052 | 		break;
2053 | 		case 0xD6:	/* SUB A, imm8 */
2054 | 			t = mem_get_byte(c.PC++);
2055 | 			set_C((c.A - t) < 0);
2056 | 			set_H(((c.A - t)&0xF) > (c.A&0xF));
2057 | 			c.A -= t;
2058 | 			set_N(1);
2059 | 			set_Z(!c.A);
2060 | 			c.cycles += 2;
2061 | 		break;
2062 | 		case 0xD7:	/* RST 10 */
2063 | 			c.SP -= 2;
2064 | 			mem_write_word(c.SP, c.PC);
2065 | 			c.PC = 0x0010;
2066 | 			c.cycles += 4;
2067 | 		break;
2068 | 		case 0xD8:	/* RET C */
2069 | 			if(flag_C == 1)
2070 | 			{
2071 | 				c.PC = mem_get_word(c.SP);
2072 | 				c.SP += 2;
2073 | 				c.cycles += 5;
2074 | 			} else {
2075 | 				c.cycles += 2;
2076 | 			}
2077 | 		break;
2078 | 		case 0xD9:	/* RETI */
2079 | 			c.PC = mem_get_word(c.SP);
2080 | 			c.SP += 2;
2081 | 			c.cycles += 4;
2082 | 			IME = 1;
2083 | 		break;
2084 | 		case 0xDA:	/* JP C, mem16 */
2085 | 			if(flag_C)
2086 | 			{
2087 | 				c.PC = mem_get_word(c.PC);
2088 | 				c.cycles += 4;
2089 | 			} else {
2090 | 				c.PC += 2;
2091 | 				c.cycles += 3;
2092 | 			}
2093 | 		break;
2094 | 		case 0xDC:	/* CALL C, mem16 */
2095 | 			if(flag_C == 1)
2096 | 			{
2097 | 				c.SP -= 2;
2098 | 				mem_write_word(c.SP, c.PC+2);
2099 | 				c.PC = mem_get_word(c.PC);
2100 | 				c.cycles += 6;
2101 | 			} else {
2102 | 				c.PC += 2;
2103 | 				c.cycles += 3;
2104 | 			}
2105 | 		break;
2106 | 		case 0xDE:	/* SBC A, imm8 */
2107 | 			t = mem_get_byte(c.PC++);
2108 | 			b = flag_C;
2109 | 			set_H(((t&0xF) + flag_C) > (c.A&0xF));
2110 | 			set_C(t + flag_C > c.A);
2111 | 			set_N(1);
2112 | 			c.A -= (b + t);
2113 | 			set_Z(!c.A);
2114 | 			c.cycles += 2;
2115 | 		break;
2116 | 		case 0xDF:	/* RST 18 */
2117 | 			c.SP -= 2;
2118 | 			mem_write_word(c.SP, c.PC);
2119 | 			c.PC = 0x0018;
2120 | 			c.cycles += 4;
2121 | 		break;
2122 | 		case 0xE0:	/* LD (FF00 + imm8), A */
2123 | 			t = mem_get_byte(c.PC++);
2124 | 			mem_write_byte(0xFF00 + t, c.A);
2125 | 			c.cycles += 3;
2126 | 		break;
2127 | 		case 0xE1:	/* POP HL */
2128 | 			i = mem_get_word(c.SP);
2129 | 			set_HL(i);
2130 | 			c.SP += 2;
2131 | 			c.cycles += 3;
2132 | 		break;
2133 | 		case 0xE2:	/* LD (FF00 + C), A */
2134 | 			mem_write_byte(0xFF00 + c.C, c.A);
2135 | 			c.cycles += 2;
2136 | 		break;
2137 | 		case 0xE5:	/* PUSH HL */
2138 | 			c.SP -= 2;
2139 | 			mem_write_word(c.SP, get_HL());
2140 | 			c.cycles += 4;
2141 | 		break;
2142 | 		case 0xE6:	/* AND A, imm8 */
2143 | 			t = mem_get_byte(c.PC++);
2144 | 			set_N(0);
2145 | 			set_H(1);
2146 | 			set_C(0);
2147 | 			c.A = t & c.A;
2148 | 			set_Z(!c.A);
2149 | 			c.cycles += 2;
2150 | 		break;
2151 | 		case 0xE7:	/* RST 20 */
2152 | 			c.SP -= 2;
2153 | 			mem_write_word(c.SP, c.PC);
2154 | 			c.PC = 0x20;
2155 | 			c.cycles += 4;
2156 | 		break;
2157 | 		case 0xE8:	/* ADD SP, imm8 */
2158 | 			i = mem_get_byte(c.PC++);
2159 | 			set_Z(0);
2160 | 			set_N(0);
2161 | 			set_C(((c.SP+i)&0xFF) < (c.SP&0xFF));
2162 | 			set_H(((c.SP+i)&0xF) < (c.SP&0xF));
2163 | 			c.SP = c.SP + (signed char)i;
2164 | 			c.cycles += 4;
2165 | 		break;
2166 | 		case 0xE9:	/* JP HL */
2167 | 			c.PC = get_HL();
2168 | 			c.cycles += 1;
2169 | 		break;
2170 | 		case 0xEA:	/* LD (mem16), a */
2171 | 			s = mem_get_word(c.PC);
2172 | 			mem_write_byte(s, c.A);
2173 | 			c.PC += 2;
2174 | 			c.cycles += 4;
2175 | 		break;
2176 | 		case 0xEE:	/* XOR A, imm8 */
2177 | 			c.A ^= mem_get_byte(c.PC++);
2178 | 			c.F = (!c.A)<<7;
2179 | 			c.cycles += 2;
2180 | 		break;
2181 | 		case 0xEF:	/* RST 28 */
2182 | 			c.SP -= 2;
2183 | 			mem_write_word(c.SP, c.PC);
2184 | 			c.PC = 0x28;
2185 | 			c.cycles += 4;
2186 | 		break;
2187 | 		case 0xF0:	/* LD A, (FF00 + imm8) */
2188 | 			t = mem_get_byte(c.PC++);
2189 | 			c.A = mem_get_byte(0xFF00 + t);
2190 | 			c.cycles += 3;
2191 | 		break;
2192 | 		case 0xF1:	/* POP AF */
2193 | 			s = mem_get_word(c.SP);
2194 | 			set_AF(s&0xFFF0);
2195 | 			c.SP += 2;
2196 | 			c.cycles += 3;
2197 | 		break;
2198 | 		case 0xF2:	/* LD A, (FF00 + c) */
2199 | 			c.A = mem_get_byte(0xFF00 + c.C);
2200 | 			c.cycles += 2;
2201 | 		break;
2202 | 		case 0xF3:	/* DI */
2203 | 			c.cycles += 1;
2204 | 			IME = 0;
2205 | 		break;
2206 | 		case 0xF5:	/* PUSH AF */
2207 | 			c.SP -= 2;
2208 | 			mem_write_word(c.SP, get_AF());
2209 | 			c.cycles += 4;
2210 | 		break;
2211 | 		case 0xF6:	/* OR A, imm8 */
2212 | 			c.A |= mem_get_byte(c.PC++);
2213 | 			c.F = (!c.A)<<7;
2214 | 			c.cycles += 2;
2215 | 		break;
2216 | 		case 0xF7:	/* RST 30 */
2217 | 			c.SP -= 2;
2218 | 			mem_write_word(c.SP, c.PC);
2219 | 			c.PC = 0x30;
2220 | 			c.cycles += 4;
2221 | 		break;
2222 | 		case 0xF8:	/* LD HL, SP + imm8 */
2223 | 			i = mem_get_byte(c.PC++);
2224 | 			set_N(0);
2225 | 			set_Z(0);
2226 | 			set_C(((c.SP+i)&0xFF) < (c.SP&0xFF));
2227 | 			set_H(((c.SP+i)&0xF) < (c.SP&0xF));
2228 | 			set_HL(c.SP + (signed char)i);
2229 | 			c.cycles += 3;
2230 | 		break;
2231 | 		case 0xF9:	/* LD SP, HL */
2232 | 			c.SP = get_HL();
2233 | 			c.cycles += 2;
2234 | 		break;
2235 | 		case 0xFA:	/* LD A, (mem16) */
2236 | 			s = mem_get_word(c.PC);
2237 | 			c.A = mem_get_byte(s);
2238 | 			c.PC += 2;
2239 | 			c.cycles += 4;
2240 | 		break;
2241 | 		case 0xFB:	/* EI */
2242 | 			interrupt_enable();
2243 | 			c.cycles += 1;
2244 | 		break;
2245 | 		case 0xFE:	/* CP a, imm8 */
2246 | 			t = mem_get_byte(c.PC++);
2247 | 			set_Z(c.A == t);
2248 | 			set_N(1);
2249 | 			set_H(((c.A - t)&0xF) > (c.A&0xF));
2250 | 			set_C(c.A < t);
2251 | 			c.cycles += 2;
2252 | 		break;
2253 | 		case 0xFF:	/* RST 38 */
2254 | 			c.SP -= 2;
2255 | 			mem_write_word(c.SP, c.PC);
2256 | 			c.PC = 0x0038;
2257 | 			c.cycles += 4;
2258 | 		break;
2259 | 		default: {
2260 | 			static char errstr[50];
2261 | 			sprintf(errstr, "Unhandled opcode: %02X at %04X.", b, c.PC);
2262 | 			espeon_faint(errstr);
2263 | 		}
2264 | 		break;
2265 | 	}
2266 | 
2267 | 	uint32_t delta = (c.cycles - c.lastcycles);
2268 | 	c.lastcycles = c.cycles;
2269 | 	return delta;
2270 | }
2271 | 


--------------------------------------------------------------------------------
/cpu.h:
--------------------------------------------------------------------------------
 1 | #ifndef CPU_H
 2 | #define CPU_H
 3 | 
 4 | #include <stdint.h>
 5 | 
 6 | extern bool halted;
 7 | 
 8 | void cpu_init(void);
 9 | uint32_t cpu_cycle(void);
10 | uint32_t cpu_get_cycles(void);
11 | void cpu_interrupt(uint16_t);
12 | 
13 | #endif
14 | 


--------------------------------------------------------------------------------
/espeon.cpp:
--------------------------------------------------------------------------------
  1 | #include <M5Stack.h>
  2 | #include <freertos/FreeRTOS.h>
  3 | #include <freertos/timers.h>
  4 | #include <freertos/task.h>
  5 | #include <freertos/queue.h>
  6 | #include <esp_partition.h>
  7 | 
  8 | #include "espeon.h"
  9 | #include "interrupt.h"
 10 | #include "mbc.h"
 11 | #include "rom.h"
 12 | 
 13 | #define PARTITION_ROM (esp_partition_subtype_t(0x40))
 14 | #define MAX_ROM_SIZE (2*1024*1024)
 15 | 
 16 | #define JOYPAD_INPUT 5
 17 | #define JOYPAD_ADDR  0x88
 18 | 
 19 | #define GETBIT(x, b) (((x)>>(b)) & 0x01)
 20 | 
 21 | #define GAMEBOY_WIDTH 160
 22 | #define GAMEBOY_HEIGHT 144
 23 | 
 24 | #define CENTER_X ((320 - GAMEBOY_WIDTH)  >> 1)
 25 | #define CENTER_Y ((240 - GAMEBOY_HEIGHT) >> 1)
 26 | 
 27 | static fbuffer_t* pixels;
 28 | 
 29 | volatile int spi_lock = 0;
 30 | volatile bool sram_modified = false;
 31 | 
 32 | uint16_t palette[] = { 0xFFFF, 0xAAAA, 0x5555, 0x2222 };
 33 | 
 34 | void espeon_render_border(const uint8_t* img, uint32_t size)
 35 | {
 36 | 	M5.Lcd.clear();
 37 | 	//M5.Lcd.drawBitmap(0, 0, 320, 240, (const uint16_t*)gbborder);
 38 | 	
 39 | 	/* Border file always overwrites the internal border if present */
 40 | 	/* TODO: select JPEG file from settings menu */
 41 | 	File test = SD.open("/gbborder.jpg", FILE_READ);
 42 | 	if (test) {
 43 | 		test.close();
 44 | 		M5.Lcd.drawJpgFile(SD, "/gbborder.jpg", 0, 0, 320, 240);
 45 | 	} else if (img) {
 46 | 		M5.Lcd.drawJpg(img, size, 0, 0, 320, 240);
 47 | 	}
 48 | }
 49 | 
 50 | static void espeon_request_sd_write()
 51 | {
 52 | 	spi_lock = 1;
 53 | }
 54 | 
 55 | void espeon_init(void)
 56 | {
 57 | 	/* LCDEnable, SDEnable, SerialEnable, I2CEnable */
 58 | 	M5.begin(true, true, false, true);
 59 | 	M5.Lcd.setBrightness(0x7F); // 50%
 60 | 	
 61 | 	/* Stops the speaker from having a damn stroke */
 62 | 	ledcDetachPin(SPEAKER_PIN);
 63 | 	
 64 | 	pinMode(JOYPAD_INPUT, INPUT_PULLUP);
 65 | 	pinMode(BUTTON_C_PIN, INPUT_PULLUP);
 66 | 	attachInterrupt(BUTTON_C_PIN, espeon_request_sd_write, FALLING);
 67 | 	
 68 | 	pixels = (fbuffer_t*)calloc(GAMEBOY_HEIGHT * GAMEBOY_WIDTH, sizeof(fbuffer_t));
 69 | 	
 70 | 	const uint32_t pal[] = {0xEFFFDE, 0xADD794, 0x525F73, 0x183442}; // Default greenscale palette
 71 | 	espeon_set_palette(pal);
 72 | }
 73 | 
 74 | void espeon_update(void)
 75 | {
 76 | 	if(!((GPIO.in >> JOYPAD_INPUT) & 0x1)) {
 77 | 		Wire.requestFrom(JOYPAD_ADDR, 1);
 78 | 		if (Wire.available()) {
 79 | 			uint8_t btns = Wire.read();
 80 | 			btn_faces = (btns >> 4);
 81 | 			btn_directions = (GETBIT(btns, 1) << 3) | (GETBIT(btns, 0) << 2) | (GETBIT(btns, 2) << 1) | (GETBIT(btns, 3));
 82 | 			if (!btn_faces || !btn_directions)
 83 | 				interrupt(INTR_JOYPAD);
 84 | 		}
 85 | 	}
 86 | }
 87 | 
 88 | void espeon_faint(const char* msg)
 89 | {
 90 | 	M5.Lcd.clear();
 91 | 	M5.Lcd.setCursor(2, 2);
 92 | 	M5.Lcd.printf("Espeon fainted!\n%s", msg);
 93 | 	while(true);
 94 | }
 95 | 
 96 | fbuffer_t* espeon_get_framebuffer(void)
 97 | {
 98 | 	return pixels;
 99 | }
100 | 
101 | void espeon_clear_framebuffer(fbuffer_t col)
102 | {
103 | 	memset(pixels, col, sizeof(pixels));
104 | }
105 | 
106 | void espeon_clear_screen(uint16_t col)
107 | {
108 | 	M5.Lcd.fillScreen(col);
109 | }
110 | 
111 | void espeon_set_palette(const uint32_t* col)
112 | {
113 | 	/* RGB888 -> RGB565 */
114 | 	for (int i = 0; i < 4; ++i) {
115 | 		palette[i] = ((col[i]&0xFF)>>3)+((((col[i]>>8)&0xFF)>>2)<<5)+((((col[i]>>16)&0xFF)>>3)<<11);
116 | 	}
117 | }
118 | 
119 | void espeon_end_frame(void)
120 | {
121 | 	if (spi_lock) {
122 | 		const s_rominfo* rominfo = rom_get_info();
123 | 		if (rominfo->has_battery && rom_get_ram_size())
124 | 			espeon_save_sram(mbc_get_ram(), rom_get_ram_size());
125 | 		spi_lock = 0;
126 | 	}
127 | 	M5.Lcd.drawBitmap(CENTER_X, CENTER_Y, GAMEBOY_WIDTH, GAMEBOY_HEIGHT, pixels);
128 | }
129 | 
130 | void espeon_save_sram(uint8_t* ram, uint32_t size)
131 | {
132 | 	if (!ram) return;
133 | 	
134 | 	static char path[20];
135 | 	sprintf(path, "/%.8s.bin", rom_get_title());
136 | 	
137 | 	File sram = SD.open(path, FILE_WRITE);
138 | 	if (sram) {
139 | 		sram.seek(0);
140 | 		sram.write(ram, size);
141 | 		sram.close();
142 | 	}
143 | }
144 | 
145 | void espeon_load_sram(uint8_t* ram, uint32_t size)
146 | {
147 | 	if (!ram) return;
148 | 	
149 | 	static char path[20];
150 | 	sprintf(path, "/%.8s.bin", rom_get_title());
151 | 	
152 | 	File sram = SD.open(path, FILE_READ);
153 | 	if (sram) {
154 | 		sram.seek(0);
155 | 		sram.read(ram, size);
156 | 		sram.close();
157 | 	}
158 | }
159 | 
160 | const uint8_t* espeon_load_bootrom(const char* path)
161 | {
162 | 	static uint8_t bootrom[256];
163 | 	
164 | 	File bf = SD.open(path, FILE_READ);
165 | 	if (bf) {
166 | 		bf.seek(0);
167 | 		bf.read(bootrom, sizeof(bootrom));
168 | 		bf.close();
169 | 		return bootrom;
170 | 	}
171 | 	
172 | 	return nullptr;
173 | }
174 | 
175 | static inline const uint8_t* espeon_get_last_rom(const esp_partition_t* part)
176 | {
177 | 	spi_flash_mmap_handle_t hrom;
178 | 	const uint8_t* romdata;
179 | 	esp_err_t err;
180 | 	err = esp_partition_mmap(part, 0, MAX_ROM_SIZE, SPI_FLASH_MMAP_DATA, (const void**)&romdata, &hrom);
181 | 	if (err != ESP_OK)
182 | 		return nullptr;
183 | 	return romdata;
184 | }
185 | 
186 | const uint8_t* espeon_load_rom(const char* path)
187 | {
188 | 	const esp_partition_t* part;
189 | 	part = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, PARTITION_ROM, NULL);
190 | 	if (!part)
191 | 		return nullptr;
192 | 	
193 | 	if (!path)
194 | 		return espeon_get_last_rom(part);
195 | 	
196 | 	File romfile = SD.open(path, FILE_READ);
197 | 	if (!romfile)
198 | 		return nullptr;
199 | 	
200 | 	esp_err_t err;
201 | 	err = esp_partition_erase_range(part, 0, MAX_ROM_SIZE);
202 | 	if (err != ESP_OK)
203 | 		return nullptr;
204 | 	
205 | 	const size_t bufsize = 32 * 1024;
206 | 	size_t romsize = romfile.size();
207 | 	if (romsize > MAX_ROM_SIZE)
208 | 		return nullptr;
209 | 	
210 | 	uint8_t* rombuf = (uint8_t*)calloc(bufsize, 1);
211 | 	if (!rombuf)
212 | 		return nullptr;
213 | 	
214 | 	M5.Lcd.clear();
215 | 	M5.Lcd.setTextColor(TFT_WHITE);
216 | 	M5.Lcd.drawString("Flashing ROM...", 0, 0);
217 | 	size_t offset = 0;
218 | 	while(romfile.available()) {
219 | 		romfile.read(rombuf, bufsize);
220 | 		esp_partition_write(part, offset, (const void*)rombuf, bufsize);
221 | 		offset += bufsize;
222 | 		M5.Lcd.progressBar(50, 100, 200, 40, (offset*100)/romsize);
223 | 	}
224 | 	M5.Lcd.clear();
225 | 	free(rombuf);
226 | 	romfile.close();
227 | 	
228 | 	return espeon_get_last_rom(part);
229 | }
230 | 


--------------------------------------------------------------------------------
/espeon.h:
--------------------------------------------------------------------------------
 1 | #ifndef ESPEON_H
 2 | #define ESPEON_H
 3 | 
 4 | #include <Arduino.h>
 5 | 
 6 | extern volatile bool sram_modified;
 7 | extern uint8_t btn_directions;
 8 | extern uint8_t btn_faces;
 9 | 
10 | typedef uint16_t fbuffer_t;
11 | extern uint16_t palette[];
12 | 
13 | void espeon_update(void);
14 | void espeon_init(void);
15 | void espeon_faint(const char* msg);
16 | fbuffer_t* espeon_get_framebuffer(void);
17 | void espeon_clear_framebuffer(fbuffer_t col);
18 | void espeon_end_frame(void);
19 | void espeon_clear_screen(uint16_t col);
20 | void espeon_set_palette(const uint32_t* col);
21 | void espeon_render_border(const uint8_t* img, uint32_t size);
22 | void espeon_save_sram(uint8_t* ram, uint32_t size);
23 | void espeon_load_sram(uint8_t* ram, uint32_t size);
24 | const uint8_t* espeon_load_rom(const char* path);
25 | const uint8_t* espeon_load_bootrom(const char* path);
26 | 
27 | #endif
28 | 


--------------------------------------------------------------------------------
/espeon.ino:
--------------------------------------------------------------------------------
 1 | #include "timer.h"
 2 | #include "rom.h"
 3 | #include "mem.h"
 4 | #include "cpu.h"
 5 | #include "lcd.h"
 6 | #include "espeon.h"
 7 | #include "menu.h"
 8 | 
 9 | #include "gbfiles.h"
10 | 
11 | void setup()
12 | {
13 | 	espeon_init();
14 | 	
15 | 	menu_init();
16 | 	menu_loop();
17 | 	
18 | 	const uint8_t* rom = espeon_load_rom(menu_get_rompath());
19 | 	if (!rom) rom = (const uint8_t*)gb_rom;
20 | 	
21 | 	const uint8_t* bootrom = espeon_load_bootrom("/gb_bios.bin");
22 | 	if (!bootrom) bootrom = (const uint8_t*)gb_bios;
23 | 	
24 | 	if (!rom_init(rom))
25 | 		espeon_faint("rom_init failed.");
26 | 	
27 | 	if (!mmu_init(bootrom))
28 | 		espeon_faint("mmu_init failed.");
29 | 	
30 | 	if (!lcd_init())
31 | 		espeon_faint("lcd_init failed.");
32 | 	
33 | 	cpu_init();
34 | 	
35 | 	espeon_render_border((const uint8_t*)gb_border, gb_border_size);
36 | 	
37 | 	while(true) {
38 | 		uint32_t cycles = cpu_cycle();
39 | 		espeon_update();
40 | 		lcd_cycle(cycles);
41 | 		timer_cycle(cycles);
42 | 	}
43 | }
44 | 
45 | void loop()
46 | {
47 | 	uint32_t cycles = cpu_cycle();
48 | 	espeon_update();
49 | 	lcd_cycle(cycles);
50 | 	timer_cycle(cycles);
51 | }
52 | 


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/Ryuzaki-MrL/Espeon/b24e790b710102fb2f1fdc5dc6dd8f9fc7fd1676/firmwares/Espeon/boot_app0_0xe000.bin


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/Ryuzaki-MrL/Espeon/b24e790b710102fb2f1fdc5dc6dd8f9fc7fd1676/firmwares/Espeon/bootloader_0x1000.bin


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/Ryuzaki-MrL/Espeon/b24e790b710102fb2f1fdc5dc6dd8f9fc7fd1676/firmwares/Espeon/partitions_espeon_0x8000.bin


--------------------------------------------------------------------------------
/firmwares/espeon.csv:
--------------------------------------------------------------------------------
1 | # Name,   Type, SubType, Offset,  Size, Flags
2 | nvs,      data, nvs,     0x9000,  0x5000,
3 | otadata,  data, ota,     0xe000,  0x2000,
4 | app0,     app,  ota_0,   0x10000, 0x100000,
5 | romdata,  data, 0x40,    0x110000,0x200000,
6 | eeprom,   data, 0x99,    0x310000,0x1000,
7 | spiffs,   data, spiffs,  0x311000,0xEF000,
8 | 


--------------------------------------------------------------------------------
/firmwares/m5burner.json:
--------------------------------------------------------------------------------
 1 | {
 2 | 	"name": "Espeon",
 3 | 	"description": "Gameboy emulator for the ESP32",
 4 | 	"author": "zid, Ryuzaki_MrL",
 5 | 	"version": "v1.0",
 6 | 	"device": "",
 7 | 	"framework": "Arduino IDE",
 8 | 	"firmware_category": [
 9 |         {
10 |             "M5Stack": {
11 |                 "path": "Espeon",
12 |                 "device": [
13 |                     "M5Stack"
14 |                 ],
15 |                 "default_baud": 921600
16 |             }
17 |         }
18 |     ]
19 | }
20 | 


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/Ryuzaki-MrL/Espeon/b24e790b710102fb2f1fdc5dc6dd8f9fc7fd1676/gbborder.jpg


--------------------------------------------------------------------------------
/gbfiles.h:
--------------------------------------------------------------------------------
 1 | #ifndef INTERNAL_H
 2 | #define INTERNAL_H
 3 | 
 4 | /* Uncomment this to include a fallback ROM */
 5 | // #define USE_INTERNAL_ROM
 6 | 
 7 | /* Uncomment if including a bios on compile */
 8 | //#define USE_INTERNAL_BIOS
 9 | 
10 | #define USE_INTERNAL_BORDER
11 | 
12 | #ifdef USE_INTERNAL_ROM
13 | 	#include "gbrom.h"
14 | #else
15 | 	const uint8_t* gb_rom = nullptr;
16 | 	const uint32_t gb_rom_size = 0;
17 | #endif
18 | 
19 | #ifdef USE_INTERNAL_BIOS
20 | 	#include "gbbios.h"
21 | #else
22 | 	const uint8_t* gb_bios = nullptr;
23 | 	const uint32_t gb_bios_size = 0;
24 | #endif
25 | 
26 | #ifdef USE_INTERNAL_BORDER
27 | 	#include "gbborder.h"
28 | #else
29 | 	const uint8_t* gb_border = nullptr;
30 | 	const uint32_t gb_border_size = 0;
31 | #endif
32 | 
33 | #endif
34 | 


--------------------------------------------------------------------------------
/interrupt.cpp:
--------------------------------------------------------------------------------
 1 | #include "interrupt.h"
 2 | #include "cpu.h"
 3 | 
 4 | uint8_t IME;
 5 | uint8_t IF;
 6 | uint8_t IE;
 7 | 
 8 | static uint8_t ime_delay;
 9 | 
10 | bool interrupt_flush(void)
11 | {
12 | 	if(ime_delay >= 2)
13 | 	{
14 | 		ime_delay = 1;
15 | 		return 0;
16 | 	}
17 | 	if (ime_delay == 1) {
18 | 		IME = 1;
19 | 		ime_delay = 0;
20 | 	}
21 | 
22 | 	/* Returns true if the cpu should be unhalted */
23 | 	if (!IME)
24 | 		return !!(IF & IE);
25 | 
26 | 	/* Check interrupts from highest to lowest priority */
27 | 	for (int i = 0; i < 5; ++i) {
28 | 		if (IE & IF & (1 << i)) {
29 | 			IME = 0;
30 | 			IF &= ~(1 << i);
31 | 			cpu_interrupt(0x40 + i*0x08);
32 | 			return true;
33 | 		}
34 | 	}
35 | 
36 | 	return false;
37 | }
38 | 
39 | void interrupt_enable(void)
40 | {
41 | 	ime_delay = 2;
42 | }
43 | 
44 | void interrupt(uint8_t n)
45 | {
46 | 	/* Add this interrupt to pending queue */
47 | 	IF |= n;
48 | 
49 | 	/* Interrupt requested, unhalt CPU if IF and IE have a match */
50 | 	if(interrupt_flush())
51 | 		halted = 0;
52 | }
53 | 


--------------------------------------------------------------------------------
/interrupt.h:
--------------------------------------------------------------------------------
 1 | #ifndef INTERRUPT_H
 2 | #define INTERRUPT_H
 3 | 
 4 | #include <stdint.h>
 5 | 
 6 | extern uint8_t IME;
 7 | extern uint8_t IF;
 8 | extern uint8_t IE;
 9 | 
10 | void interrupt(uint8_t);
11 | void interrupt_enable(void);
12 | bool interrupt_flush(void);
13 | 
14 | enum {
15 | 	INTR_VBLANK  = 0x01,
16 | 	INTR_LCDSTAT = 0x02,
17 | 	INTR_TIMER   = 0x04,
18 | 	INTR_SERIAL  = 0x08,
19 | 	INTR_JOYPAD  = 0x10
20 | };
21 | 
22 | #endif
23 | 


--------------------------------------------------------------------------------
/lcd.cpp:
--------------------------------------------------------------------------------
  1 | #include <freertos/FreeRTOS.h>
  2 | #include <freertos/timers.h>
  3 | #include <freertos/task.h>
  4 | #include <freertos/queue.h>
  5 | 
  6 | #include "lcd.h"
  7 | #include "interrupt.h"
  8 | #include "espeon.h"
  9 | #include "mem.h"
 10 | 
 11 | #define MODE2_BOUNDS 	(204/4)
 12 | #define MODE3_BOUNDS 	(284/4)
 13 | #define MODE0_BOUNDS 	(456/4)
 14 | #define SCANLINE_CYCLES	(456/4)
 15 | 
 16 | struct sprite {
 17 | 	int16_t y, x, tile, flags;
 18 | };
 19 | 
 20 | static uint8_t lcd_line;
 21 | static uint8_t lcd_stat;
 22 | static uint8_t lcd_ly_compare;
 23 | static uint32_t lcd_cycles;
 24 | volatile uint8_t skip_frames;
 25 | 
 26 | static QueueHandle_t lcdqueue;
 27 | 
 28 | /* LCD STAT */
 29 | static uint8_t ly_int;
 30 | static uint8_t mode2_oam_int;
 31 | static uint8_t mode1_vblank_int;
 32 | static uint8_t mode0_hblank_int;
 33 | static uint8_t ly_int_flag;
 34 | static uint8_t lcd_mode;
 35 | static uint8_t lcd_stat_tracker;
 36 | 
 37 | /* LCD Context */
 38 | struct LCDC {
 39 | 	uint8_t lcd_enabled = 1;
 40 | 	uint8_t lcd_line;
 41 | 	uint8_t window_tilemap_select;
 42 | 	uint8_t window_enabled;
 43 | 	uint8_t tilemap_select;
 44 | 	uint8_t bg_tiledata_select;
 45 | 	uint8_t sprite_size;
 46 | 	uint8_t sprites_enabled;
 47 | 	uint8_t bg_enabled;
 48 | 	uint8_t bg_palette;
 49 | 	uint8_t spr_palette1;
 50 | 	uint8_t spr_palette2;
 51 | 	uint8_t scroll_x;
 52 | 	uint8_t scroll_y;
 53 | 	uint8_t window_x;
 54 | 	uint8_t window_y;
 55 | };
 56 | 
 57 | static LCDC lcdc;
 58 | 
 59 | static uint8_t bgpalette[] = {3, 2, 1, 0};
 60 | static uint8_t sprpalette1[] = {0, 1, 2, 3};
 61 | static uint8_t sprpalette2[] = {0, 1, 2, 3};
 62 | 
 63 | enum {
 64 | 	PRIO  = 0x80,
 65 | 	VFLIP = 0x40,
 66 | 	HFLIP = 0x20,
 67 | 	PNUM  = 0x10
 68 | };
 69 | 
 70 | static inline void lcd_match_lyc()
 71 | {
 72 | 	ly_int_flag = (lcd_line == lcd_ly_compare);
 73 | 	if(ly_int && ly_int_flag) {
 74 | 		interrupt(INTR_LCDSTAT);
 75 | 	}
 76 | }
 77 | 
 78 | void lcd_reset(void)
 79 | {
 80 | 	xQueueReset(lcdqueue);
 81 | 	espeon_clear_framebuffer(palette[0x00]);
 82 | 	lcd_mode = 1;
 83 | 	lcd_line = 0;
 84 | 	lcd_cycles = 0;
 85 | }
 86 | 
 87 | uint8_t lcd_get_stat(void)
 88 | {
 89 | 	return lcd_stat | (ly_int_flag<<2) | lcd_mode;
 90 | }
 91 | 
 92 | static inline void lcd_set_palettes(const LCDC& lcdc)
 93 | {
 94 | 	uint8_t n = lcdc.bg_palette;
 95 | 	bgpalette[0] = (n>>0)&3;
 96 | 	bgpalette[1] = (n>>2)&3;
 97 | 	bgpalette[2] = (n>>4)&3;
 98 | 	bgpalette[3] = (n>>6)&3;
 99 | 	n = lcdc.spr_palette1;
100 | 	sprpalette1[1] = (n>>2)&3;
101 | 	sprpalette1[2] = (n>>4)&3;
102 | 	sprpalette1[3] = (n>>6)&3;
103 | 	n = lcdc.spr_palette2;
104 | 	sprpalette2[1] = (n>>2)&3;
105 | 	sprpalette2[2] = (n>>4)&3;
106 | 	sprpalette2[3] = (n>>6)&3;
107 | }
108 | 
109 | void lcd_write_bg_palette(uint8_t n)
110 | {
111 | 	lcdc.bg_palette = n;
112 | }
113 | 
114 | void lcd_write_spr_palette1(uint8_t n)
115 | {
116 | 	lcdc.spr_palette1 = n;
117 | }
118 | 
119 | void lcd_write_spr_palette2(uint8_t n)
120 | {
121 | 	lcdc.spr_palette2 = n;
122 | }
123 | 
124 | void lcd_write_scroll_x(uint8_t n)
125 | {
126 | 	lcdc.scroll_x = n;
127 | }
128 | 
129 | void lcd_write_scroll_y(uint8_t n)
130 | {
131 | 	lcdc.scroll_y = n;
132 | }
133 | 
134 | uint8_t lcd_get_line(void)
135 | {
136 | 	return lcd_line;
137 | }
138 | 
139 | void lcd_write_stat(uint8_t c)
140 | {
141 | 	ly_int                = !!(c & 0x40);
142 | 	mode2_oam_int         = !!(c & 0x20);
143 | 	mode1_vblank_int      = !!(c & 0x10);
144 | 	mode0_hblank_int      = !!(c & 0x08);
145 | 	
146 | 	lcd_stat = (c & 0xF8);
147 | }
148 | 
149 | void lcd_write_control(uint8_t c)
150 | {
151 | 	lcdc.bg_enabled            = !!(c & 0x01);
152 | 	lcdc.sprites_enabled       = !!(c & 0x02);
153 | 	lcdc.sprite_size           = !!(c & 0x04);
154 | 	lcdc.tilemap_select        = !!(c & 0x08);
155 | 	lcdc.bg_tiledata_select    = !!(c & 0x10);
156 | 	lcdc.window_enabled        = !!(c & 0x20);
157 | 	lcdc.window_tilemap_select = !!(c & 0x40);
158 | 	lcdc.lcd_enabled           = !!(c & 0x80);
159 | 	
160 | 	if(!lcdc.lcd_enabled) {
161 | 		lcd_reset();
162 | 		skip_frames = 2;
163 | 	} else {
164 | 		lcd_match_lyc();
165 | 	}
166 | }
167 | 
168 | void lcd_set_ly_compare(uint8_t c)
169 | {
170 | 	lcd_ly_compare = c;
171 | 	if(lcdc.lcd_enabled)
172 | 		lcd_match_lyc();
173 | }
174 | 
175 | void lcd_set_window_y(uint8_t n)
176 | {
177 | 	lcdc.window_y = n;
178 | }
179 | 
180 | void lcd_set_window_x(uint8_t n)
181 | {
182 | 	lcdc.window_x = n;
183 | }
184 | 
185 | static inline void sort_sprites(struct sprite *s, int n)
186 | {
187 | 	int swapped, i;
188 | 
189 | 	do
190 | 	{
191 | 		swapped = 0;
192 | 		for(i = 0; i < n-1; i++)
193 | 		{
194 | 			if(s[i].x < s[i+1].x)
195 | 			{
196 | 				sprite c = s[i];
197 | 				s[i] = s[i+1];
198 | 				s[i+1] = c;
199 | 				swapped = 1;
200 | 			}
201 | 		}
202 | 	}
203 | 	while(swapped);
204 | }
205 | 
206 | static inline int scan_sprites(struct sprite *s, int line, int size)
207 | {
208 | 	int i, c = 0;
209 | 	for(i = 0; i<40; i++)
210 | 	{
211 | 		int y, offs = i * 4;
212 | 	
213 | 		y = mem[0xFE00 + offs++] - 16;
214 | 		if(line < y || line >= y + 8+(size*8))
215 | 			continue;
216 | 	
217 | 		s[c].y     = y;
218 | 		s[c].x     = mem[0xFE00 + offs++]-8;
219 | 		s[c].tile  = mem[0xFE00 + offs++];
220 | 		s[c].flags = mem[0xFE00 + offs++];
221 | 		c++;
222 | 	
223 | 		if(c == 10)
224 | 			break;
225 | 	}
226 | 	return c;
227 | }
228 | 
229 | static void draw_bg_and_window(fbuffer_t *b, int line, struct LCDC& lcdc)
230 | {
231 | 	int x, offset = line * 160;
232 | 	bool windowVisible = line >= lcdc.window_y && lcdc.window_enabled && line - lcdc.window_y < 144;
233 | 
234 | 	for(x = 0; x < 160; x++, offset++)
235 | 	{
236 | 		uint32_t map_select, map_offset, tile_num, tile_addr, xm, ym;
237 | 		uint8_t b1, b2, mask, colour;
238 | 
239 | 		/* Convert LCD x,y into full 256*256 style internal coords */
240 | 		if(windowVisible && x + 7 >= lcdc.window_x)
241 | 		{
242 | 			xm = x + 7 - lcdc.window_x;
243 | 			ym = line - lcdc.window_y;
244 | 			map_select = lcdc.window_tilemap_select;
245 | 		}
246 | 		else {
247 | 			if(!lcdc.bg_enabled)
248 | 			{
249 | 				b[offset] = palette[bgpalette[0]];
250 | 				continue;
251 | 			}
252 | 			xm = (x + lcdc.scroll_x) & 0xFF;
253 | 			ym = (line + lcdc.scroll_y) & 0xFF;
254 | 			map_select = lcdc.tilemap_select;
255 | 		}
256 | 
257 | 		/* Which pixel is this tile on? Find its offset. */
258 | 		/* (y/8)*32 calculates the offset of the row the y coordinate is on.
259 | 		 * As 256/32 is 8, divide by 8 to map one to the other, this is the row number.
260 | 		 * Then multiply the row number by the width of a row, 32, to find the offset.
261 | 		 * Finally, add x/(256/32) to find the offset within that row. 
262 | 		 */
263 | 		map_offset = (ym/8)*32 + xm/8;
264 | 
265 | 		tile_num = mem[0x9800 + map_select*0x400 + map_offset];
266 | 		if(lcdc.bg_tiledata_select)
267 | 			tile_addr = 0x8000 + tile_num*16;
268 | 		else
269 | 			tile_addr = 0x9000 + ((signed char)tile_num)*16;
270 | 
271 | 		b1 = mem[tile_addr+(ym&7)*2];
272 | 		b2 = mem[tile_addr+(ym&7)*2+1];
273 | 		mask = 128>>(xm&7);
274 | 		colour = (!!(b2&mask)<<1) | !!(b1&mask);
275 | 		
276 | 		b[offset] = palette[bgpalette[colour]];
277 | 	}
278 | }
279 | 
280 | static void draw_sprites(fbuffer_t *b, int line, int nsprites, struct sprite *s, struct LCDC& lcdc)
281 | {
282 | 	for(uint8_t i = 0; i < nsprites; i++)
283 | 	{
284 | 		uint32_t b1, b2, tile_addr, sprite_line, x, offset;
285 | 
286 | 		/* Sprite is offscreen */
287 | 		if(s[i].x < -7)
288 | 			continue;
289 | 
290 | 		/* Which line of the sprite (0-7) are we rendering */
291 | 		sprite_line = s[i].flags & VFLIP ? (lcdc.sprite_size ? 15 : 7)-(line - s[i].y) : line - s[i].y;
292 | 
293 | 		/* Address of the tile data for this sprite line */
294 | 		tile_addr = 0x8000 + (s[i].tile*16) + sprite_line*2;
295 | 
296 | 		/* The two bytes of data holding the palette entries */
297 | 		b1 = mem[tile_addr];
298 | 		b2 = mem[tile_addr+1];
299 | 
300 | 		/* For each pixel in the line, draw it */
301 | 		offset = s[i].x + line * 160;
302 | 		for(x = 0; x < 8; x++, offset++)
303 | 		{
304 | 			uint8_t mask, colour;
305 | 			uint8_t *pal;
306 | 
307 | 			if((s[i].x + x) >= 160)
308 | 				continue;
309 | 
310 | 			mask = s[i].flags & HFLIP ? 128>>(7-x) : 128>>x;
311 | 			colour = ((!!(b2&mask))<<1) | !!(b1&mask);
312 | 			if(colour == 0)
313 | 				continue;
314 | 
315 | 			pal = (s[i].flags & PNUM) ? sprpalette2 : sprpalette1;
316 | 			
317 | 			/* Sprite is behind BG, only render over palette entry 0 */
318 | 			if(s[i].flags & PRIO)
319 | 			{
320 | 				if(b[offset] != palette[bgpalette[0]])
321 | 					continue;
322 | 			}
323 | 			
324 | 			//b[offset] = pal[colour];
325 | 			b[offset] = palette[pal[colour]];
326 | 		}
327 | 	}
328 | }
329 | 
330 | static void render_line(void *arg)
331 | {
332 | 	struct LCDC cline;
333 | 	fbuffer_t* b = espeon_get_framebuffer();
334 | 	
335 | 	while(true) {
336 | 		if(!xQueueReceive(lcdqueue, &cline, portMAX_DELAY))
337 | 			continue;
338 | 		
339 | 		if(lcd_mode==1)
340 | 			continue;
341 | 		
342 | 		int line = cline.lcd_line;
343 | 		struct sprite s[10];
344 | 		
345 | 		lcd_set_palettes(cline);
346 | 		
347 | 		/* Draw the background layer */
348 | 		draw_bg_and_window(b, line, cline);
349 | 		
350 | 		/* Draw sprites */
351 | 		if(cline.sprites_enabled) {
352 | 			uint8_t sprcnt = scan_sprites(s, line, cline.sprite_size);
353 | 			if(sprcnt) {
354 | 				sort_sprites(s, sprcnt);
355 | 				draw_sprites(b, line, sprcnt, s, cline);
356 | 			}
357 | 		}
358 | 
359 | 		if(line == 143) {
360 | 			if (skip_frames) {
361 | 				--skip_frames;
362 | 			} else {
363 | 				espeon_end_frame();
364 | 			}
365 | 		}
366 | 	}
367 | }
368 | 
369 | void lcd_cycle(uint32_t cycles)
370 | {	
371 | 	if(!lcdc.lcd_enabled)
372 | 		return;
373 | 	
374 | 	lcd_cycles += cycles;
375 |   
376 | 	if(lcd_line >= 144) {
377 | 		if (lcd_mode != 1) {
378 | 			/* Mode 1: Vertical blanking */
379 | 			if (mode1_vblank_int) {
380 | 				interrupt(INTR_LCDSTAT);
381 | 			}
382 | 			interrupt(INTR_VBLANK);
383 | 			lcd_stat_tracker = 0;
384 | 			lcd_mode = 1;
385 | 			
386 | 			//espeon_end_frame();
387 | 		}
388 | 		if (lcd_cycles >= SCANLINE_CYCLES) {
389 | 			lcd_cycles -= SCANLINE_CYCLES;
390 | 			//lcd_cycles = 0;
391 | 			++lcd_line;
392 | 			if (lcd_line > 153) {
393 | 				lcd_line = 0;
394 | 			}
395 | 			lcd_match_lyc();
396 | 		}
397 | 	}
398 | 	else if(lcd_cycles < MODE2_BOUNDS) {
399 | 		if (lcd_mode != 2) {
400 | 			if (mode2_oam_int) {
401 | 				interrupt(INTR_LCDSTAT);
402 | 			}
403 | 			lcd_stat_tracker = 1;
404 | 			lcd_mode = 2;
405 | 			
406 | 			/* Mode 2: Scanning OAM for (X, Y) coordinates of sprites that overlap this line */
407 | 			// lcdc.sprcount = scan_sprites(lcdc.spr, lcd_line, lcdc.sprite_size);
408 | 			// if (lcdc.sprcount)
409 | 				// sort_sprites(lcdc.spr, lcdc.sprcount);
410 | 		}
411 | 	}
412 | 	else if(lcd_cycles < MODE3_BOUNDS) {
413 | 		if (lcd_mode != 3) {
414 | 			lcd_stat_tracker = 1;
415 | 			lcd_mode = 3;
416 | 			
417 | 			/* send scanline early */
418 | 			lcdc.lcd_line = lcd_line;
419 | 			xQueueSend(lcdqueue, &lcdc, 0);
420 | 			
421 | 			/* Mode 3: Reading OAM and VRAM to generate the picture */
422 | 			// fbuffer_t* b = espeon_get_framebuffer();
423 | 			// lcd_set_palettes(lcdc);
424 | 			// draw_bg_and_window(b, lcd_line, lcdc);
425 | 			// draw_sprites(b, lcd_line, sprcount, spr, lcdc);
426 | 		}
427 | 	}
428 | 	else if(lcd_cycles < MODE0_BOUNDS) {
429 | 		if (lcd_mode != 0) {
430 | 			/* Mode 0: Horizontal blanking */
431 | 			if (mode0_hblank_int) {
432 | 				interrupt(INTR_LCDSTAT);
433 | 			}
434 | 			lcd_stat_tracker = 3;
435 | 			lcd_mode = 0;
436 | 		}
437 | 	}
438 | 	else {
439 | 		++lcd_line;
440 | 		lcd_match_lyc();
441 | 		lcd_mode = 0;
442 | 		lcd_cycles -= SCANLINE_CYCLES;
443 | 		//lcd_cycles = 0;
444 | 	}
445 | }
446 | 
447 | bool lcd_init()
448 | {	
449 | 	lcdqueue = xQueueCreate(143, sizeof(LCDC));
450 | 	if(!lcdqueue)
451 | 		return false;
452 | 	
453 | 	lcd_write_control(mem[0xFF40]);
454 | 	
455 | 	xTaskCreatePinnedToCore(&render_line, "renderScanline", 4096, NULL, 5, NULL, 0);
456 | 	
457 | 	return true;
458 | }
459 | 


--------------------------------------------------------------------------------
/lcd.h:
--------------------------------------------------------------------------------
 1 | #ifndef LCD_H
 2 | #define LCD_H
 3 | 
 4 | #include <stdint.h>
 5 | 
 6 | bool lcd_init(void);
 7 | void lcd_cycle(uint32_t);
 8 | void lcd_reset(void);
 9 | uint8_t lcd_get_line(void);
10 | uint8_t lcd_get_stat();
11 | void lcd_write_control(uint8_t);
12 | void lcd_write_stat(uint8_t);
13 | void lcd_write_scroll_x(uint8_t);
14 | void lcd_write_scroll_y(uint8_t);
15 | void lcd_write_bg_palette(uint8_t);
16 | void lcd_write_spr_palette1(uint8_t);
17 | void lcd_write_spr_palette2(uint8_t);
18 | void lcd_set_window_y(uint8_t);
19 | void lcd_set_window_x(uint8_t);
20 | void lcd_set_ly_compare(uint8_t);
21 | 
22 | #endif
23 | 


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/Ryuzaki-MrL/Espeon/b24e790b710102fb2f1fdc5dc6dd8f9fc7fd1676/logo/espeon_dmg.png


--------------------------------------------------------------------------------
/logo/espeon_dmg.xcf:
--------------------------------------------------------------------------------
https://raw.githubusercontent.com/Ryuzaki-MrL/Espeon/b24e790b710102fb2f1fdc5dc6dd8f9fc7fd1676/logo/espeon_dmg.xcf


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/Ryuzaki-MrL/Espeon/b24e790b710102fb2f1fdc5dc6dd8f9fc7fd1676/logo/espeon_dmg_small.png


--------------------------------------------------------------------------------
https://raw.githubusercontent.com/Ryuzaki-MrL/Espeon/b24e790b710102fb2f1fdc5dc6dd8f9fc7fd1676/logo/espeon_logo.png


--------------------------------------------------------------------------------
/logo/espeon_logo.xcf:
--------------------------------------------------------------------------------
https://raw.githubusercontent.com/Ryuzaki-MrL/Espeon/b24e790b710102fb2f1fdc5dc6dd8f9fc7fd1676/logo/espeon_logo.xcf


--------------------------------------------------------------------------------
/makeborder.bat:
--------------------------------------------------------------------------------
1 | bin2h -cz gb_border<"gbborder.jpg" > gbborder.h
2 | 


--------------------------------------------------------------------------------
/mbc.cpp:
--------------------------------------------------------------------------------
  1 | #include "mbc.h"
  2 | #include "rom.h"
  3 | #include "espeon.h"
  4 | 
  5 | #define SET_ROM_BANK(n)		(rombank = &rom[((n) & (rom_banks - 1)) * 0x4000])
  6 | #define SET_RAM_BANK(n)		(rambank = &ram[((n) & (ram_banks - 1)) * 0x2000])
  7 | 
  8 | static uint32_t curr_rom_bank = 1;
  9 | static uint8_t rom_banks;
 10 | static uint32_t curr_ram_bank = 0;
 11 | static uint8_t ram_banks;
 12 | static bool ram_select;
 13 | static bool ram_enabled;
 14 | static const uint8_t *rom;
 15 | static uint8_t *ram;
 16 | const uint8_t *rombank;
 17 | uint8_t *rambank;
 18 | static const s_rominfo *rominfo;
 19 | 
 20 | MBCReader mbc_read_ram;
 21 | MBCWriter mbc_write_rom;
 22 | MBCWriter mbc_write_ram;
 23 | 
 24 | 
 25 | bool mbc_init()
 26 | {
 27 | 	rom = rom_getbytes();
 28 | 	rominfo = rom_get_info();
 29 | 	
 30 | 	rom_banks = rominfo->rom_banks;
 31 | 	ram_banks = rominfo->ram_banks;
 32 | 	
 33 | 	int ram_size = rom_get_ram_size();
 34 | 	ram = (uint8_t *)calloc(1, ram_size < 1024*8 ? 1024*8 : ram_size);
 35 | 	if (!ram)
 36 | 		return false;
 37 | 	
 38 | 	if (rominfo->has_battery && ram_size)
 39 | 		espeon_load_sram(ram, ram_size);
 40 | 	
 41 | 	SET_ROM_BANK(1);
 42 | 	SET_RAM_BANK(0);
 43 | 	
 44 | 	switch(rominfo->rom_mapper)
 45 | 	{
 46 | 		case MBC2:
 47 | 			mbc_write_rom = MBC3_write_ROM;
 48 | 			mbc_write_ram = MBC1_write_RAM;
 49 | 			mbc_read_ram = MBC1_read_RAM;
 50 | 		break;
 51 | 		case MBC3:
 52 | 			mbc_write_rom = MBC3_write_ROM;
 53 | 			mbc_write_ram = MBC3_write_RAM;
 54 | 			mbc_read_ram = MBC3_read_RAM;
 55 | 		break;
 56 | 		default:
 57 | 			mbc_write_rom = MBC1_write_ROM;
 58 | 			mbc_write_ram = MBC1_write_RAM;
 59 | 			mbc_read_ram = MBC1_read_RAM;
 60 | 		break;
 61 | 	}
 62 | 	
 63 | 	return true;
 64 | }
 65 | 
 66 | uint8_t* mbc_get_ram()
 67 | {
 68 | 	return ram;
 69 | }
 70 | 
 71 | 
 72 | void MBC3_write_ROM(uint16_t d, uint8_t i)
 73 | {
 74 | 	if(d < 0x2000)
 75 | 		ram_enabled = ((i & 0x0F) == 0x0A);
 76 | 	
 77 | 	else if(d < 0x4000) {
 78 | 		curr_rom_bank = i & 0x7F;
 79 | 
 80 | 		if(curr_rom_bank == 0)
 81 | 			curr_rom_bank++;
 82 | 
 83 | 		SET_ROM_BANK(curr_rom_bank);
 84 | 	}
 85 | 	
 86 | 	else if(d < 0x6000) {
 87 | 		/* TODO: select RTC */
 88 | 		curr_ram_bank = i & 0x07;
 89 | 		SET_RAM_BANK(curr_ram_bank);
 90 | 	}
 91 | }
 92 | 
 93 | void MBC3_write_RAM(uint16_t d, uint8_t i)
 94 | {
 95 | 	/* TODO: write to RTC */
 96 | 	if (!ram_enabled)
 97 | 		return;
 98 | 	rambank[d - 0xA000] = i;
 99 | 	//sram_modified = true;
100 | }
101 | 
102 | uint8_t MBC3_read_RAM(uint16_t i)
103 | {
104 | 	return ram_enabled ? rambank[i - 0xA000] : 0xFF;
105 | }
106 | 
107 | 
108 | void MBC1_write_ROM(uint16_t d, uint8_t i)
109 | {
110 | 	if(d < 0x2000)
111 | 		ram_enabled = ((i & 0x0F) == 0x0A);
112 | 	
113 | 	else if(d < 0x4000) {
114 | 		curr_rom_bank = (curr_rom_bank & 0x60) | (i & 0x1F);
115 | 
116 | 		if(curr_rom_bank == 0 || curr_rom_bank == 0x20 || curr_rom_bank == 0x40 || curr_rom_bank == 0x60)
117 | 			curr_rom_bank++;
118 | 
119 | 		SET_ROM_BANK(curr_rom_bank);
120 | 	}
121 | 	
122 | 	else if(d < 0x6000) {
123 | 		if (ram_select) {
124 | 			curr_ram_bank = i&3;
125 | 			SET_RAM_BANK(curr_ram_bank);
126 | 		}
127 | 		else {
128 | 			curr_rom_bank = ((i & 0x3)<<5) | (curr_rom_bank & 0x1F);
129 | 			SET_ROM_BANK(curr_rom_bank);
130 | 		}
131 | 	}
132 | 	
133 | 	else if(d < 0x8000) {
134 | 		ram_select = i&1;
135 | 		if (ram_select) {
136 | 			curr_rom_bank &= 0x1F;
137 | 			SET_ROM_BANK(curr_rom_bank);
138 | 		}
139 | 		else {
140 | 			curr_ram_bank = 0;
141 | 			SET_RAM_BANK(curr_ram_bank);
142 | 		}
143 | 	}
144 | }
145 | 
146 | void MBC1_write_RAM(uint16_t d, uint8_t i)
147 | {
148 | 	if (!ram_enabled)
149 | 		return;
150 | 	rambank[d - 0xA000] = i;
151 | 	//sram_modified = true;
152 | }
153 | 
154 | uint8_t MBC1_read_RAM(uint16_t i)
155 | {
156 | 	return ram_enabled ? rambank[i - 0xA000] : 0xFF;
157 | }
158 | 


--------------------------------------------------------------------------------
/mbc.h:
--------------------------------------------------------------------------------
 1 | #ifndef MBC_H
 2 | #define MBC_H
 3 | 
 4 | #include <stdint.h>
 5 | 
 6 | typedef uint8_t(*MBCReader)(uint16_t);
 7 | typedef void(*MBCWriter)(uint16_t, uint8_t);
 8 | 
 9 | extern MBCReader mbc_read_ram;
10 | extern MBCWriter mbc_write_rom;
11 | extern MBCWriter mbc_write_ram;
12 | 
13 | extern const uint8_t* rombank;
14 | extern uint8_t* rambank;
15 | 
16 | bool mbc_init();
17 | uint8_t* mbc_get_ram();
18 | 
19 | void MBC1_write_ROM(uint16_t, uint8_t);
20 | void MBC1_write_RAM(uint16_t, uint8_t);
21 | uint8_t MBC1_read_RAM(uint16_t);
22 | 
23 | void MBC3_write_ROM(uint16_t, uint8_t);
24 | void MBC3_write_RAM(uint16_t, uint8_t);
25 | uint8_t MBC3_read_RAM(uint16_t);
26 | 
27 | #endif
28 | 


--------------------------------------------------------------------------------
/mem.cpp:
--------------------------------------------------------------------------------
  1 | #include <stdlib.h>
  2 | #include <string.h>
  3 | #include <stdint.h>
  4 | #include "mem.h"
  5 | #include "rom.h"
  6 | #include "lcd.h"
  7 | #include "mbc.h"
  8 | #include "interrupt.h"
  9 | #include "timer.h"
 10 | #include "cpu.h"
 11 | 
 12 | bool usebootrom = false;
 13 | uint8_t *mem = nullptr;
 14 | static uint8_t *echo;
 15 | static uint32_t DMA_pending;
 16 | static uint8_t joypad_select_buttons, joypad_select_directions;
 17 | uint8_t btn_directions, btn_faces;
 18 | static const s_rominfo *rominfo;
 19 | static const uint8_t *rom;
 20 | 
 21 | 
 22 | uint8_t mem_get_byte(uint16_t i)
 23 | {
 24 | 	if(DMA_pending && i < 0xFF80)
 25 | 	{
 26 | 		uint32_t elapsed = cpu_get_cycles() - DMA_pending;
 27 | 		if(elapsed >= 160) {
 28 | 			DMA_pending = 0;
 29 | 		} else {
 30 | 			return mem[0xFE00+elapsed];
 31 | 		}
 32 | 	}
 33 | 
 34 | 	if(i >= 0x4000 && i < 0x8000)
 35 | 		return rombank[i - 0x4000];
 36 | 
 37 | 	else if (i >= 0xA000 && i < 0xC000)
 38 | 		return mbc_read_ram(i);
 39 | 	
 40 | 	else if (i >= 0xE000 && i < 0xFE00)
 41 | 		return echo[i];
 42 | 
 43 | 	else switch(i)
 44 | 	{
 45 | 		case 0xFF00: {	/* Joypad */
 46 | 			uint8_t mask = 0;
 47 | 			if(!joypad_select_buttons)
 48 | 				mask = btn_faces;
 49 | 			if(!joypad_select_directions)
 50 | 				mask = btn_directions;
 51 | 			return (0xC0) | (joypad_select_buttons | joypad_select_directions) | (mask);
 52 | 		}
 53 | 		case 0xFF04: return timer_get_div();
 54 | 		case 0xFF0F: return 0xE0 | IF;
 55 | 		case 0xFF41: return lcd_get_stat();
 56 | 		case 0xFF44: return lcd_get_line();
 57 | 		case 0xFF4D: return 0xFF; /* GBC speed switch */
 58 | 		case 0xFFFF: return IE;
 59 | 	}
 60 | 
 61 | 	return mem[i];
 62 | }
 63 | 
 64 | void mem_write_byte(uint16_t d, uint8_t i)
 65 | {
 66 | 	/* ROM */
 67 | 	if (d < 0x8000)
 68 | 		mbc_write_rom(d, i);
 69 | 	
 70 | 	/* SRAM */
 71 | 	else if (d >= 0xA000 && d < 0xC000)
 72 | 		mbc_write_ram(d, i);
 73 | 	
 74 | 	/* ECHO */
 75 | 	else if (d >= 0xE000 && d < 0xFE00)
 76 | 		echo[d] = i;
 77 | 
 78 | 	else switch(d)
 79 | 	{
 80 | 		case 0xFF00:	/* Joypad */
 81 | 			joypad_select_buttons = i&0x20;
 82 | 			joypad_select_directions = i&0x10;
 83 | 		break;
 84 | 		case 0xFF04: timer_reset_div(); break;
 85 | 		case 0xFF07: timer_set_tac(i); break;
 86 | 		case 0xFF0F: IF = i; break;
 87 | 		case 0xFF40: lcd_write_control(i); break;
 88 | 		case 0xFF41: lcd_write_stat(i); break;
 89 | 		case 0xFF42: lcd_write_scroll_y(i); break;
 90 | 		case 0xFF43: lcd_write_scroll_x(i); break;
 91 | 		case 0xFF44: lcd_reset(); break;
 92 | 		case 0xFF45: lcd_set_ly_compare(i); break;
 93 | 		case 0xFF46: { /* OAM DMA */
 94 | 			/* Check if address overlaps with RAM or ROM */
 95 | 			uint16_t addr = i * 0x100;
 96 | 			const uint8_t* src = mem;
 97 | 			if (addr >= 0x4000 && addr < 0x8000) {
 98 | 				src = rombank;
 99 | 				addr -= 0x4000;
100 | 			}
101 | 			else if (addr >= 0xA000 && addr < 0xC000) {
102 | 				src = rambank;
103 | 				addr -= 0xA000;
104 | 			}
105 | 			
106 | 			/* Copy 0xA0 bytes from source to OAM */
107 | 			memcpy(&mem[0xFE00], &src[addr], 0xA0);
108 | 			DMA_pending = cpu_get_cycles();
109 | 			break;
110 | 		}
111 | 		case 0xFF47: lcd_write_bg_palette(i); break;
112 | 		case 0xFF48: lcd_write_spr_palette1(i); break;
113 | 		case 0xFF49: lcd_write_spr_palette2(i); break;
114 | 		case 0xFF4A: lcd_set_window_y(i); break;
115 | 		case 0xFF4B: lcd_set_window_x(i); break;
116 | 		case 0xFF50: memcpy(&mem[0x0000], &rom[0x0000], 0x100); break; /* Lock bootROM */
117 | 		case 0xFFFF: IE = i; break;
118 | 
119 | 		default: mem[d] = i; break;
120 | 	}
121 | }
122 | 
123 | bool mmu_init(const uint8_t* bootrom)
124 | {
125 | 	mem = (uint8_t *)calloc(1, 0x10000);
126 | 	if (!mem)
127 | 		return false;
128 | 	
129 | 	if (!mbc_init())
130 | 		return false;
131 | 	
132 | 	rom = rom_getbytes();
133 | 	echo = mem + 0xC000 - 0xE000;
134 | 	
135 | 	if (bootrom) {
136 | 		memcpy(&mem[0x0000], &bootrom[0x0000], 0x100);
137 | 		memcpy(&mem[0x0100], &rom[0x0100], 0x4000 - 0x100);
138 | 		usebootrom = true;
139 | 		return true;
140 | 	}
141 | 	
142 | 	// First ROM bank is always in RAM
143 | 	memcpy(&mem[0x0000], &rom[0x0000], 0x4000);
144 | 
145 | 	// Default values if bootrom is not present
146 | 	mem[0xFF10] = 0x80;
147 | 	mem[0xFF11] = 0xBF;
148 | 	mem[0xFF12] = 0xF3;
149 | 	mem[0xFF14] = 0xBF;
150 | 	mem[0xFF16] = 0x3F;
151 | 	mem[0xFF19] = 0xBF;
152 | 	mem[0xFF1A] = 0x7F;
153 | 	mem[0xFF1B] = 0xFF;
154 | 	mem[0xFF1C] = 0x9F;
155 | 	mem[0xFF1E] = 0xBF;
156 | 	mem[0xFF20] = 0xFF;
157 | 	mem[0xFF23] = 0xBF;
158 | 	mem[0xFF24] = 0x77;
159 | 	mem[0xFF25] = 0xF3;
160 | 	mem[0xFF26] = 0xF1;
161 | 	mem[0xFF40] = 0x91;
162 | 	mem[0xFF47] = 0xFC;
163 | 	mem[0xFF48] = 0xFF;
164 | 	mem[0xFF49] = 0xFF;
165 | 	
166 | 	return true;
167 | }
168 | 


--------------------------------------------------------------------------------
/mem.h:
--------------------------------------------------------------------------------
 1 | #ifndef MEM_H
 2 | #define MEM_H
 3 | 
 4 | #include <stdint.h>
 5 | 
 6 | extern bool usebootrom;
 7 | extern uint8_t* mem;
 8 | 
 9 | bool mmu_init(const uint8_t* bootrom = nullptr);
10 | uint8_t mem_get_byte(uint16_t);
11 | inline uint16_t mem_get_word(uint16_t i) { return mem_get_byte(i) | (mem_get_byte(i+1)<<8); }
12 | void mem_write_byte(uint16_t, uint8_t);
13 | inline void mem_write_word(uint16_t d, uint16_t i) { mem_write_byte(d, i&0xFF); mem_write_byte(d+1, i>>8); }
14 | 
15 | #endif
16 | 


--------------------------------------------------------------------------------
/menu.cpp:
--------------------------------------------------------------------------------
 1 | #include <vector>
 2 | #include <M5Stack.h>
 3 | #include <M5TreeView.h>
 4 | #include <MenuItemSD.h>
 5 | 
 6 | #include "menu.h"
 7 | 
 8 | M5TreeView treeView;
 9 | 
10 | typedef std::vector<MenuItem*> vmi;
11 | 
12 | static String rompath = "";
13 | static const char* rompath_c = nullptr;
14 | static bool running;
15 | 
16 | void cb_menu_newrom(MenuItem* sender)
17 | {
18 | 	if (rompath != "") {
19 | 		rompath_c = rompath.c_str();
20 | 		running = false;
21 | 	}
22 | }
23 | 
24 | void cb_menu_loadrom(MenuItem* sender)
25 | {
26 | 	MenuItemFS* mi = static_cast<MenuItemFS*>(sender);
27 | 	if (!mi) return;
28 | 
29 | 	if (mi->isDir) return;
30 | 
31 | 	int idx = mi->path.lastIndexOf('.') + 1;
32 | 	String ext = mi->path.substring(idx);
33 | 	if (ext == "gb") {
34 | 		rompath = mi->path;
35 | 		M5.Lcd.fillRect(0, 0, M5.Lcd.width(), 10, 0);
36 | 		M5.Lcd.drawString(rompath, 0, 0);
37 | 		cb_menu_newrom(sender);
38 | 		//treeView.begin();
39 | 	}
40 | }
41 | 
42 | void cb_menu_lastrom(MenuItem* sender)
43 | {
44 | 	rompath_c = nullptr;
45 | 	running = false;
46 | }
47 | 
48 | const char* menu_get_rompath()
49 | {
50 | 	return rompath_c;
51 | }
52 | 
53 | void menu_init()
54 | {
55 | 	treeView.clientRect.x = 2;
56 | 	treeView.clientRect.y = 16;
57 | 	treeView.clientRect.w = 316;
58 | 	treeView.clientRect.h = 200;
59 | 	treeView.setTextFont(2);
60 | 	treeView.itemHeight   = 18;
61 | 	treeView.itemWidth    = 220;
62 | 
63 | 	treeView.useFACES       = true;
64 | 	treeView.useJoyStick    = true;
65 | 	treeView.usePLUSEncoder = true;
66 | 	treeView.useFACESEncoder= true;
67 | 
68 | 	treeView.setItems(vmi
69 | 		{
70 | 			new MenuItem("Last ROM (Flash)", cb_menu_lastrom),
71 | 			new MenuItemSD("Load ROM (SD Card)", cb_menu_loadrom),
72 | 			//new MenuItem("Start", cb_menu_newrom),
73 | 			new MenuItem("Settings (TODO)")
74 | 		}
75 | 	);
76 | 
77 | 	running = true;
78 | 	treeView.begin();
79 | }
80 | 
81 | void menu_loop()
82 | {
83 | 	M5.Lcd.drawString("Espeon v1.0", 0, 0);
84 | 	while(running) {
85 | 		treeView.update();
86 | 	}
87 | }
88 | 


--------------------------------------------------------------------------------
/menu.h:
--------------------------------------------------------------------------------
1 | #ifndef MENU_H
2 | #define MENU_H
3 | 
4 | void menu_init();
5 | void menu_loop();
6 | const char* menu_get_rompath();
7 | 
8 | #endif
9 | 


--------------------------------------------------------------------------------
/rom.cpp:
--------------------------------------------------------------------------------
  1 | #include <stdio.h>
  2 | #include <string.h>
  3 | #include "rom.h"
  4 | 
  5 | const uint8_t *bytes;
  6 | 
  7 | static s_rominfo rominfo;
  8 | static char romtitle[20] = "";
  9 | 
 10 | static const uint16_t rombank_count[256] = {
 11 | 	2, 4, 8, 16, 32, 64, 128, 256, 512,
 12 | 	/* 0x52 */
 13 | 	72, 80, 96
 14 | };
 15 | 
 16 | static const uint8_t rambank_count[256] = {
 17 | 	0, 1, 1, 4, 16, 8
 18 | };
 19 | 
 20 | static const uint8_t header[] = {
 21 | 	0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B,
 22 | 	0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
 23 | 	0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E,
 24 | 	0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
 25 | 	0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC,
 26 | 	0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
 27 | };
 28 | 
 29 | bool rom_init(const uint8_t* rombytes)
 30 | {
 31 | 	if(!rombytes)
 32 | 		return false;
 33 | 
 34 | 	/* Check Nintendo logo on ROM header */
 35 | 	if(memcmp(&rombytes[0x104], header, sizeof(header)) != 0)
 36 | 		return false;
 37 | 	
 38 | 	memcpy(romtitle, &rombytes[0x134], 0x143-0x134);
 39 | 
 40 | 	uint8_t cart_type  = rombytes[0x147];
 41 | 	rominfo.rom_banks  = rombytes[0x148]>=0x52 ? rombank_count[rombytes[0x148] - 0x52] : rombank_count[rombytes[0x148]];
 42 | 	rominfo.ram_banks  = rambank_count[rombytes[0x149]];
 43 | 	//rominfo.region    = rombytes[0x14A];
 44 | 	//rominfo.version   = rombytes[0x14C];
 45 | 
 46 | 	uint8_t checksum = 0;
 47 | 	for(int i = 0x134; i <= 0x14C; i++)
 48 | 		checksum = checksum - rombytes[i] - 1;
 49 | 
 50 | 	if(rombytes[0x14D] != checksum)
 51 | 		return false;
 52 | 
 53 | 	bytes = rombytes;
 54 | 
 55 | 	switch(cart_type)
 56 | 	{
 57 | 		case 0x09:
 58 | 			rominfo.has_battery = true;
 59 | 		case 0x08:
 60 | 		case 0x00:
 61 | 			rominfo.rom_mapper = NROM;
 62 | 			break;
 63 | 		case 0x03:
 64 | 			rominfo.has_battery = true;
 65 | 		case 0x02:
 66 | 		case 0x01:
 67 | 			rominfo.rom_mapper = MBC1;
 68 | 			break;
 69 | 		case 0x06:
 70 | 			rominfo.has_battery = true;
 71 | 		case 0x05:
 72 | 			rominfo.rom_mapper = MBC2;
 73 | 			break;
 74 | 		case 0x0D:
 75 | 			rominfo.has_battery = true;
 76 | 		case 0x0C:
 77 | 		case 0x0B:
 78 | 			rominfo.rom_mapper = MMM01;
 79 | 			break;
 80 | 		case 0x10:
 81 | 		case 0x0F:
 82 | 			rominfo.has_rtc = true;
 83 | 		case 0x13:
 84 | 			rominfo.has_battery = true;
 85 | 		case 0x12:
 86 | 		case 0x11:
 87 | 			rominfo.rom_mapper = MBC3;
 88 | 			break;
 89 | 		case 0x1E:
 90 | 		case 0x1B:
 91 | 			rominfo.has_battery = true;
 92 | 		case 0x1D:
 93 | 		case 0x1C:
 94 | 		case 0x1A:
 95 | 		case 0x19:
 96 | 			rominfo.rom_mapper = MBC5;
 97 | 			break;
 98 | 	}
 99 | 
100 | 	return true;
101 | }
102 | 
103 | const s_rominfo *rom_get_info(void)
104 | {
105 | 	return &rominfo;
106 | }
107 | 
108 | uint32_t rom_get_ram_size()
109 | {
110 | 	if (rominfo.rom_mapper == MBC2)
111 | 		return 512;
112 | 	return rominfo.ram_banks * 1024 * 8;
113 | }
114 | 
115 | const char* rom_get_title()
116 | {
117 | 	return romtitle;
118 | }
119 | 
120 | const uint8_t *rom_getbytes(void)
121 | {
122 | 	return bytes;
123 | }
124 | 


--------------------------------------------------------------------------------
/rom.h:
--------------------------------------------------------------------------------
 1 | #ifndef ROM_H
 2 | #define ROM_H
 3 | 
 4 | #include <stdint.h>
 5 | 
 6 | struct s_rominfo {
 7 | 	uint16_t rom_banks;
 8 | 	uint8_t ram_banks;
 9 | 	uint8_t rom_mapper;
10 | 	uint8_t has_battery;
11 | 	uint8_t has_rtc;
12 | };
13 | 
14 | bool rom_init(const uint8_t *);
15 | const uint8_t *rom_getbytes(void);
16 | const s_rominfo *rom_get_info(void);
17 | uint32_t rom_get_ram_size();
18 | const char* rom_get_title();
19 | 
20 | enum {
21 | 	NROM,
22 | 	MBC1,
23 | 	MBC2,
24 | 	MMM01,
25 | 	MBC3,
26 | 	MBC5,
27 | };
28 | 
29 | #endif
30 | 


--------------------------------------------------------------------------------
/rom2h.bat:
--------------------------------------------------------------------------------
1 | bin2h -cz gb_rom<"%1" > gbrom.h
2 | 


--------------------------------------------------------------------------------
/timer.cpp:
--------------------------------------------------------------------------------
 1 | #include <stdint.h>
 2 | #include "timer.h"
 3 | #include "interrupt.h"
 4 | #include "mem.h"
 5 | 
 6 | #define DIV  0xFF04
 7 | #define TIMA 0xFF05
 8 | #define TMA  0xFF06
 9 | #define TAC  0xFF07
10 | 
11 | static uint32_t ticks;
12 | static uint8_t started;
13 | static uint32_t speed = 1024;
14 | static uint16_t divider;
15 | 
16 | void timer_reset_div(void)
17 | {
18 | 	divider = 0;
19 | }
20 | 
21 | uint8_t timer_get_div(void)
22 | {
23 | 	return (divider >> 8);
24 | }
25 | 
26 | void timer_set_tac(uint8_t v)
27 | {
28 | 	const int speeds[] = {1024, 16, 64, 256};
29 | 	mem[TAC] = v;
30 | 	started = v&4;
31 | 	speed = speeds[v&3];
32 | }
33 | 
34 | void timer_cycle(uint32_t delta)
35 | {
36 | 	delta *= 4;
37 | 	divider += delta;
38 | 	if(started) {
39 | 		ticks += delta;
40 | 		if(ticks >= speed) {
41 | 			//ticks -= speed;
42 | 			ticks = 0;
43 | 			if(++mem[TIMA] >= 0x100) {
44 | 				interrupt(INTR_TIMER);
45 | 				mem[TIMA] = mem[TMA];
46 | 			}
47 | 		}
48 | 	}
49 | }
50 | 


--------------------------------------------------------------------------------
/timer.h:
--------------------------------------------------------------------------------
 1 | #ifndef TIMER_H
 2 | #define TIMER_H
 3 | 
 4 | #include <stdint.h>
 5 | 
 6 | void timer_set_tac(uint8_t);
 7 | void timer_cycle(uint32_t);
 8 | uint8_t timer_get_div(void);
 9 | uint8_t timer_get_counter(void);
10 | uint8_t timer_get_modulo(void);
11 | uint8_t timer_get_tac(void);
12 | void timer_reset_div(void);
13 | void timer_set_counter(uint8_t);
14 | void timer_set_modulo(uint8_t);
15 | 
16 | #endif
17 | 


---------------------------------------------------------