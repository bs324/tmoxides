/* This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You may use it, redistribute it and/or modify
 * it, in whole or in part, provided that you do so at your own risk and do not
 * hold the developers or copyright holders liable for any claim, damages, or
 * other liabilities arising in connection with the software.
 * 
 * Developed by Gerald Knizia, 2010--2012.
 */

#include "CxTypes.h"
//#include <boost/math/special_functions/binomial.hpp>
// ^- gna.. old boost version installed here doesn't have it yet.

typedef unsigned int
   uint;

// c/p'd from AicKernels.cpp; don't have binomial_coefficient from
// boost here due to old boost version.

// uint64_t NoverK_(uint n_, uint k_)
// {
//    // FIXME: FUNCTION IS HIGHLY DOUBIOUS!! INVESTIGATE THIS FIRST
//    //        WHEN TF INTEGRALS DONT WORK!
//    // should probably use boost::binomial_coefficient. But current
//    // boost version installed here doesn't have it yet.
//    // Also note the high chance of overflow..
//    // FIXME: add checking code for high angular momenta here!!
//    //
//    if ( k_ == 0 || k_ == n_ )
//       return 1;
//    if ( k_ == 1 || k_ == n_-1 )
//       return n_;
//    uint64_t
//       n = n_ + 1,
//       k = k_ + 1;
// //    if ( k > n )
// //       return 0;
//    uint64_t
//       num = 1,
//       denom = 1;
//    for ( uint64_t i = 1; i < k; ++ i )
//       denom *= i;
//    for ( uint64_t i = n-k+1; i < n; ++ i )
//       num *= i;
//    return num/denom;
// }

#define LU(x) UINT64_C(x)
// address with comb(N,k) = Tab[N*(N-1)/2 + k]
const uint MAX_NoverK = 64;
static uint64_t s_NoverK_Tab[2081] = {
   LU(1), LU(1), LU(2), LU(1), LU(3), LU(3), LU(1), LU(4), LU(6), LU(4), LU(1),
   LU(5), LU(10), LU(10), LU(5), LU(1), LU(6), LU(15), LU(20), LU(15), LU(6),
   LU(1), LU(7), LU(21), LU(35), LU(35), LU(21), LU(7), LU(1), LU(8), LU(28),
   LU(56), LU(70), LU(56), LU(28), LU(8), LU(1), LU(9), LU(36), LU(84), LU(126),
   LU(126), LU(84), LU(36), LU(9), LU(1), LU(10), LU(45), LU(120), LU(210),
   LU(252), LU(210), LU(120), LU(45), LU(10), LU(1), LU(11), LU(55), LU(165),
   LU(330), LU(462), LU(462), LU(330), LU(165), LU(55), LU(11), LU(1), LU(12),
   LU(66), LU(220), LU(495), LU(792), LU(924), LU(792), LU(495), LU(220), LU(66),
   LU(12), LU(1), LU(13), LU(78), LU(286), LU(715), LU(1287), LU(1716), LU(1716),
   LU(1287), LU(715), LU(286), LU(78), LU(13), LU(1), LU(14), LU(91), LU(364),
   LU(1001), LU(2002), LU(3003), LU(3432), LU(3003), LU(2002), LU(1001), LU(364),
   LU(91), LU(14), LU(1), LU(15), LU(105), LU(455), LU(1365), LU(3003), LU(5005),
   LU(6435), LU(6435), LU(5005), LU(3003), LU(1365), LU(455), LU(105), LU(15),
   LU(1), LU(16), LU(120), LU(560), LU(1820), LU(4368), LU(8008), LU(11440),
   LU(12870), LU(11440), LU(8008), LU(4368), LU(1820), LU(560), LU(120), LU(16),
   LU(1), LU(17), LU(136), LU(680), LU(2380), LU(6188), LU(12376), LU(19448),
   LU(24310), LU(24310), LU(19448), LU(12376), LU(6188), LU(2380), LU(680),
   LU(136), LU(17), LU(1), LU(18), LU(153), LU(816), LU(3060), LU(8568), LU(18564),
   LU(31824), LU(43758), LU(48620), LU(43758), LU(31824), LU(18564), LU(8568),
   LU(3060), LU(816), LU(153), LU(18), LU(1), LU(19), LU(171), LU(969), LU(3876),
   LU(11628), LU(27132), LU(50388), LU(75582), LU(92378), LU(92378), LU(75582),
   LU(50388), LU(27132), LU(11628), LU(3876), LU(969), LU(171), LU(19), LU(1),
   LU(20), LU(190), LU(1140), LU(4845), LU(15504), LU(38760), LU(77520),
   LU(125970), LU(167960), LU(184756), LU(167960), LU(125970), LU(77520),
   LU(38760), LU(15504), LU(4845), LU(1140), LU(190), LU(20), LU(1), LU(21),
   LU(210), LU(1330), LU(5985), LU(20349), LU(54264), LU(116280), LU(203490),
   LU(293930), LU(352716), LU(352716), LU(293930), LU(203490), LU(116280),
   LU(54264), LU(20349), LU(5985), LU(1330), LU(210), LU(21), LU(1), LU(22),
   LU(231), LU(1540), LU(7315), LU(26334), LU(74613), LU(170544), LU(319770),
   LU(497420), LU(646646), LU(705432), LU(646646), LU(497420), LU(319770),
   LU(170544), LU(74613), LU(26334), LU(7315), LU(1540), LU(231), LU(22), LU(1),
   LU(23), LU(253), LU(1771), LU(8855), LU(33649), LU(100947), LU(245157),
   LU(490314), LU(817190), LU(1144066), LU(1352078), LU(1352078), LU(1144066),
   LU(817190), LU(490314), LU(245157), LU(100947), LU(33649), LU(8855), LU(1771),
   LU(253), LU(23), LU(1), LU(24), LU(276), LU(2024), LU(10626), LU(42504),
   LU(134596), LU(346104), LU(735471), LU(1307504), LU(1961256), LU(2496144),
   LU(2704156), LU(2496144), LU(1961256), LU(1307504), LU(735471), LU(346104),
   LU(134596), LU(42504), LU(10626), LU(2024), LU(276), LU(24), LU(1), LU(25),
   LU(300), LU(2300), LU(12650), LU(53130), LU(177100), LU(480700), LU(1081575),
   LU(2042975), LU(3268760), LU(4457400), LU(5200300), LU(5200300), LU(4457400),
   LU(3268760), LU(2042975), LU(1081575), LU(480700), LU(177100), LU(53130),
   LU(12650), LU(2300), LU(300), LU(25), LU(1), LU(26), LU(325), LU(2600),
   LU(14950), LU(65780), LU(230230), LU(657800), LU(1562275), LU(3124550),
   LU(5311735), LU(7726160), LU(9657700), LU(10400600), LU(9657700), LU(7726160),
   LU(5311735), LU(3124550), LU(1562275), LU(657800), LU(230230), LU(65780),
   LU(14950), LU(2600), LU(325), LU(26), LU(1), LU(27), LU(351), LU(2925),
   LU(17550), LU(80730), LU(296010), LU(888030), LU(2220075), LU(4686825),
   LU(8436285), LU(13037895), LU(17383860), LU(20058300), LU(20058300),
   LU(17383860), LU(13037895), LU(8436285), LU(4686825), LU(2220075), LU(888030),
   LU(296010), LU(80730), LU(17550), LU(2925), LU(351), LU(27), LU(1), LU(28),
   LU(378), LU(3276), LU(20475), LU(98280), LU(376740), LU(1184040), LU(3108105),
   LU(6906900), LU(13123110), LU(21474180), LU(30421755), LU(37442160),
   LU(40116600), LU(37442160), LU(30421755), LU(21474180), LU(13123110),
   LU(6906900), LU(3108105), LU(1184040), LU(376740), LU(98280), LU(20475),
   LU(3276), LU(378), LU(28), LU(1), LU(29), LU(406), LU(3654), LU(23751),
   LU(118755), LU(475020), LU(1560780), LU(4292145), LU(10015005), LU(20030010),
   LU(34597290), LU(51895935), LU(67863915), LU(77558760), LU(77558760),
   LU(67863915), LU(51895935), LU(34597290), LU(20030010), LU(10015005),
   LU(4292145), LU(1560780), LU(475020), LU(118755), LU(23751), LU(3654), LU(406),
   LU(29), LU(1), LU(30), LU(435), LU(4060), LU(27405), LU(142506), LU(593775),
   LU(2035800), LU(5852925), LU(14307150), LU(30045015), LU(54627300),
   LU(86493225), LU(119759850), LU(145422675), LU(155117520), LU(145422675),
   LU(119759850), LU(86493225), LU(54627300), LU(30045015), LU(14307150),
   LU(5852925), LU(2035800), LU(593775), LU(142506), LU(27405), LU(4060), LU(435),
   LU(30), LU(1), LU(31), LU(465), LU(4495), LU(31465), LU(169911), LU(736281),
   LU(2629575), LU(7888725), LU(20160075), LU(44352165), LU(84672315),
   LU(141120525), LU(206253075), LU(265182525), LU(300540195), LU(300540195),
   LU(265182525), LU(206253075), LU(141120525), LU(84672315), LU(44352165),
   LU(20160075), LU(7888725), LU(2629575), LU(736281), LU(169911), LU(31465),
   LU(4495), LU(465), LU(31), LU(1), LU(32), LU(496), LU(4960), LU(35960),
   LU(201376), LU(906192), LU(3365856), LU(10518300), LU(28048800), LU(64512240),
   LU(129024480), LU(225792840), LU(347373600), LU(471435600), LU(565722720),
   LU(601080390), LU(565722720), LU(471435600), LU(347373600), LU(225792840),
   LU(129024480), LU(64512240), LU(28048800), LU(10518300), LU(3365856),
   LU(906192), LU(201376), LU(35960), LU(4960), LU(496), LU(32), LU(1), LU(33),
   LU(528), LU(5456), LU(40920), LU(237336), LU(1107568), LU(4272048),
   LU(13884156), LU(38567100), LU(92561040), LU(193536720), LU(354817320),
   LU(573166440), LU(818809200), LU(1037158320), LU(1166803110), LU(1166803110),
   LU(1037158320), LU(818809200), LU(573166440), LU(354817320), LU(193536720),
   LU(92561040), LU(38567100), LU(13884156), LU(4272048), LU(1107568), LU(237336),
   LU(40920), LU(5456), LU(528), LU(33), LU(1), LU(34), LU(561), LU(5984),
   LU(46376), LU(278256), LU(1344904), LU(5379616), LU(18156204), LU(52451256),
   LU(131128140), LU(286097760), LU(548354040), LU(927983760), LU(1391975640),
   LU(1855967520), LU(2203961430), LU(2333606220), LU(2203961430), LU(1855967520),
   LU(1391975640), LU(927983760), LU(548354040), LU(286097760), LU(131128140),
   LU(52451256), LU(18156204), LU(5379616), LU(1344904), LU(278256), LU(46376),
   LU(5984), LU(561), LU(34), LU(1), LU(35), LU(595), LU(6545), LU(52360),
   LU(324632), LU(1623160), LU(6724520), LU(23535820), LU(70607460), LU(183579396),
   LU(417225900), LU(834451800), LU(1476337800), LU(2319959400), LU(3247943160),
   LU(4059928950), LU(4537567650), LU(4537567650), LU(4059928950), LU(3247943160),
   LU(2319959400), LU(1476337800), LU(834451800), LU(417225900), LU(183579396),
   LU(70607460), LU(23535820), LU(6724520), LU(1623160), LU(324632), LU(52360),
   LU(6545), LU(595), LU(35), LU(1), LU(36), LU(630), LU(7140), LU(58905),
   LU(376992), LU(1947792), LU(8347680), LU(30260340), LU(94143280), LU(254186856),
   LU(600805296), LU(1251677700), LU(2310789600), LU(3796297200), LU(5567902560),
   LU(7307872110), LU(8597496600), LU(9075135300), LU(8597496600), LU(7307872110),
   LU(5567902560), LU(3796297200), LU(2310789600), LU(1251677700), LU(600805296),
   LU(254186856), LU(94143280), LU(30260340), LU(8347680), LU(1947792), LU(376992),
   LU(58905), LU(7140), LU(630), LU(36), LU(1), LU(37), LU(666), LU(7770),
   LU(66045), LU(435897), LU(2324784), LU(10295472), LU(38608020), LU(124403620),
   LU(348330136), LU(854992152), LU(1852482996), LU(3562467300), LU(6107086800),
   LU(9364199760), LU(12875774670), LU(15905368710), LU(17672631900),
   LU(17672631900), LU(15905368710), LU(12875774670), LU(9364199760),
   LU(6107086800), LU(3562467300), LU(1852482996), LU(854992152), LU(348330136),
   LU(124403620), LU(38608020), LU(10295472), LU(2324784), LU(435897), LU(66045),
   LU(7770), LU(666), LU(37), LU(1), LU(38), LU(703), LU(8436), LU(73815),
   LU(501942), LU(2760681), LU(12620256), LU(48903492), LU(163011640),
   LU(472733756), LU(1203322288), LU(2707475148), LU(5414950296), LU(9669554100),
   LU(15471286560), LU(22239974430), LU(28781143380), LU(33578000610),
   LU(35345263800), LU(33578000610), LU(28781143380), LU(22239974430),
   LU(15471286560), LU(9669554100), LU(5414950296), LU(2707475148), LU(1203322288),
   LU(472733756), LU(163011640), LU(48903492), LU(12620256), LU(2760681),
   LU(501942), LU(73815), LU(8436), LU(703), LU(38), LU(1), LU(39), LU(741),
   LU(9139), LU(82251), LU(575757), LU(3262623), LU(15380937), LU(61523748),
   LU(211915132), LU(635745396), LU(1676056044), LU(3910797436), LU(8122425444),
   LU(15084504396), LU(25140840660), LU(37711260990), LU(51021117810),
   LU(62359143990), LU(68923264410), LU(68923264410), LU(62359143990),
   LU(51021117810), LU(37711260990), LU(25140840660), LU(15084504396),
   LU(8122425444), LU(3910797436), LU(1676056044), LU(635745396), LU(211915132),
   LU(61523748), LU(15380937), LU(3262623), LU(575757), LU(82251), LU(9139),
   LU(741), LU(39), LU(1), LU(40), LU(780), LU(9880), LU(91390), LU(658008),
   LU(3838380), LU(18643560), LU(76904685), LU(273438880), LU(847660528),
   LU(2311801440), LU(5586853480), LU(12033222880), LU(23206929840),
   LU(40225345056), LU(62852101650), LU(88732378800), LU(113380261800),
   LU(131282408400), LU(137846528820), LU(131282408400), LU(113380261800),
   LU(88732378800), LU(62852101650), LU(40225345056), LU(23206929840),
   LU(12033222880), LU(5586853480), LU(2311801440), LU(847660528), LU(273438880),
   LU(76904685), LU(18643560), LU(3838380), LU(658008), LU(91390), LU(9880),
   LU(780), LU(40), LU(1), LU(41), LU(820), LU(10660), LU(101270), LU(749398),
   LU(4496388), LU(22481940), LU(95548245), LU(350343565), LU(1121099408),
   LU(3159461968), LU(7898654920), LU(17620076360), LU(35240152720),
   LU(63432274896), LU(103077446706), LU(151584480450), LU(202112640600),
   LU(244662670200), LU(269128937220), LU(269128937220), LU(244662670200),
   LU(202112640600), LU(151584480450), LU(103077446706), LU(63432274896),
   LU(35240152720), LU(17620076360), LU(7898654920), LU(3159461968),
   LU(1121099408), LU(350343565), LU(95548245), LU(22481940), LU(4496388),
   LU(749398), LU(101270), LU(10660), LU(820), LU(41), LU(1), LU(42), LU(861),
   LU(11480), LU(111930), LU(850668), LU(5245786), LU(26978328), LU(118030185),
   LU(445891810), LU(1471442973), LU(4280561376), LU(11058116888), LU(25518731280),
   LU(52860229080), LU(98672427616), LU(166509721602), LU(254661927156),
   LU(353697121050), LU(446775310800), LU(513791607420), LU(538257874440),
   LU(513791607420), LU(446775310800), LU(353697121050), LU(254661927156),
   LU(166509721602), LU(98672427616), LU(52860229080), LU(25518731280),
   LU(11058116888), LU(4280561376), LU(1471442973), LU(445891810), LU(118030185),
   LU(26978328), LU(5245786), LU(850668), LU(111930), LU(11480), LU(861), LU(42),
   LU(1), LU(43), LU(903), LU(12341), LU(123410), LU(962598), LU(6096454),
   LU(32224114), LU(145008513), LU(563921995), LU(1917334783), LU(5752004349),
   LU(15338678264), LU(36576848168), LU(78378960360), LU(151532656696),
   LU(265182149218), LU(421171648758), LU(608359048206), LU(800472431850),
   LU(960566918220), LU(1052049481860), LU(1052049481860), LU(960566918220),
   LU(800472431850), LU(608359048206), LU(421171648758), LU(265182149218),
   LU(151532656696), LU(78378960360), LU(36576848168), LU(15338678264),
   LU(5752004349), LU(1917334783), LU(563921995), LU(145008513), LU(32224114),
   LU(6096454), LU(962598), LU(123410), LU(12341), LU(903), LU(43), LU(1), LU(44),
   LU(946), LU(13244), LU(135751), LU(1086008), LU(7059052), LU(38320568),
   LU(177232627), LU(708930508), LU(2481256778), LU(7669339132), LU(21090682613),
   LU(51915526432), LU(114955808528), LU(229911617056), LU(416714805914),
   LU(686353797976), LU(1029530696964), LU(1408831480056), LU(1761039350070),
   LU(2012616400080), LU(2104098963720), LU(2012616400080), LU(1761039350070),
   LU(1408831480056), LU(1029530696964), LU(686353797976), LU(416714805914),
   LU(229911617056), LU(114955808528), LU(51915526432), LU(21090682613),
   LU(7669339132), LU(2481256778), LU(708930508), LU(177232627), LU(38320568),
   LU(7059052), LU(1086008), LU(135751), LU(13244), LU(946), LU(44), LU(1), LU(45),
   LU(990), LU(14190), LU(148995), LU(1221759), LU(8145060), LU(45379620),
   LU(215553195), LU(886163135), LU(3190187286), LU(10150595910), LU(28760021745),
   LU(73006209045), LU(166871334960), LU(344867425584), LU(646626422970),
   LU(1103068603890), LU(1715884494940), LU(2438362177020), LU(3169870830126),
   LU(3773655750150), LU(4116715363800), LU(4116715363800), LU(3773655750150),
   LU(3169870830126), LU(2438362177020), LU(1715884494940), LU(1103068603890),
   LU(646626422970), LU(344867425584), LU(166871334960), LU(73006209045),
   LU(28760021745), LU(10150595910), LU(3190187286), LU(886163135), LU(215553195),
   LU(45379620), LU(8145060), LU(1221759), LU(148995), LU(14190), LU(990), LU(45),
   LU(1), LU(46), LU(1035), LU(15180), LU(163185), LU(1370754), LU(9366819),
   LU(53524680), LU(260932815), LU(1101716330), LU(4076350421), LU(13340783196),
   LU(38910617655), LU(101766230790), LU(239877544005), LU(511738760544),
   LU(991493848554), LU(1749695026860), LU(2818953098830), LU(4154246671960),
   LU(5608233007146), LU(6943526580276), LU(7890371113950), LU(8233430727600),
   LU(7890371113950), LU(6943526580276), LU(5608233007146), LU(4154246671960),
   LU(2818953098830), LU(1749695026860), LU(991493848554), LU(511738760544),
   LU(239877544005), LU(101766230790), LU(38910617655), LU(13340783196),
   LU(4076350421), LU(1101716330), LU(260932815), LU(53524680), LU(9366819),
   LU(1370754), LU(163185), LU(15180), LU(1035), LU(46), LU(1), LU(47), LU(1081),
   LU(16215), LU(178365), LU(1533939), LU(10737573), LU(62891499), LU(314457495),
   LU(1362649145), LU(5178066751), LU(17417133617), LU(52251400851),
   LU(140676848445), LU(341643774795), LU(751616304549), LU(1503232609098),
   LU(2741188875414), LU(4568648125690), LU(6973199770790), LU(9762479679106),
   LU(12551759587422), LU(14833897694226), LU(16123801841550), LU(16123801841550),
   LU(14833897694226), LU(12551759587422), LU(9762479679106), LU(6973199770790),
   LU(4568648125690), LU(2741188875414), LU(1503232609098), LU(751616304549),
   LU(341643774795), LU(140676848445), LU(52251400851), LU(17417133617),
   LU(5178066751), LU(1362649145), LU(314457495), LU(62891499), LU(10737573),
   LU(1533939), LU(178365), LU(16215), LU(1081), LU(47), LU(1), LU(48), LU(1128),
   LU(17296), LU(194580), LU(1712304), LU(12271512), LU(73629072), LU(377348994),
   LU(1677106640), LU(6540715896), LU(22595200368), LU(69668534468),
   LU(192928249296), LU(482320623240), LU(1093260079344), LU(2254848913647),
   LU(4244421484512), LU(7309837001104), LU(11541847896480), LU(16735679449896),
   LU(22314239266528), LU(27385657281648), LU(30957699535776), LU(32247603683100),
   LU(30957699535776), LU(27385657281648), LU(22314239266528), LU(16735679449896),
   LU(11541847896480), LU(7309837001104), LU(4244421484512), LU(2254848913647),
   LU(1093260079344), LU(482320623240), LU(192928249296), LU(69668534468),
   LU(22595200368), LU(6540715896), LU(1677106640), LU(377348994), LU(73629072),
   LU(12271512), LU(1712304), LU(194580), LU(17296), LU(1128), LU(48), LU(1),
   LU(49), LU(1176), LU(18424), LU(211876), LU(1906884), LU(13983816),
   LU(85900584), LU(450978066), LU(2054455634), LU(8217822536), LU(29135916264),
   LU(92263734836), LU(262596783764), LU(675248872536), LU(1575580702584),
   LU(3348108992991), LU(6499270398159), LU(11554258485616), LU(18851684897584),
   LU(28277527346376), LU(39049918716424), LU(49699896548176), LU(58343356817424),
   LU(63205303218876), LU(63205303218876), LU(58343356817424), LU(49699896548176),
   LU(39049918716424), LU(28277527346376), LU(18851684897584), LU(11554258485616),
   LU(6499270398159), LU(3348108992991), LU(1575580702584), LU(675248872536),
   LU(262596783764), LU(92263734836), LU(29135916264), LU(8217822536),
   LU(2054455634), LU(450978066), LU(85900584), LU(13983816), LU(1906884),
   LU(211876), LU(18424), LU(1176), LU(49), LU(1), LU(50), LU(1225), LU(19600),
   LU(230300), LU(2118760), LU(15890700), LU(99884400), LU(536878650),
   LU(2505433700), LU(10272278170), LU(37353738800), LU(121399651100),
   LU(354860518600), LU(937845656300), LU(2250829575120), LU(4923689695575),
   LU(9847379391150), LU(18053528883775), LU(30405943383200), LU(47129212243960),
   LU(67327446062800), LU(88749815264600), LU(108043253365600),
   LU(121548660036300), LU(126410606437752), LU(121548660036300),
   LU(108043253365600), LU(88749815264600), LU(67327446062800), LU(47129212243960),
   LU(30405943383200), LU(18053528883775), LU(9847379391150), LU(4923689695575),
   LU(2250829575120), LU(937845656300), LU(354860518600), LU(121399651100),
   LU(37353738800), LU(10272278170), LU(2505433700), LU(536878650), LU(99884400),
   LU(15890700), LU(2118760), LU(230300), LU(19600), LU(1225), LU(50), LU(1),
   LU(51), LU(1275), LU(20825), LU(249900), LU(2349060), LU(18009460),
   LU(115775100), LU(636763050), LU(3042312350), LU(12777711870), LU(47626016970),
   LU(158753389900), LU(476260169700), LU(1292706174900), LU(3188675231420),
   LU(7174519270695), LU(14771069086725), LU(27900908274925), LU(48459472266975),
   LU(77535155627160), LU(114456658306760), LU(156077261327400),
   LU(196793068630200), LU(229591913401900), LU(247959266474052),
   LU(247959266474052), LU(229591913401900), LU(196793068630200),
   LU(156077261327400), LU(114456658306760), LU(77535155627160),
   LU(48459472266975), LU(27900908274925), LU(14771069086725), LU(7174519270695),
   LU(3188675231420), LU(1292706174900), LU(476260169700), LU(158753389900),
   LU(47626016970), LU(12777711870), LU(3042312350), LU(636763050), LU(115775100),
   LU(18009460), LU(2349060), LU(249900), LU(20825), LU(1275), LU(51), LU(1),
   LU(52), LU(1326), LU(22100), LU(270725), LU(2598960), LU(20358520),
   LU(133784560), LU(752538150), LU(3679075400), LU(15820024220), LU(60403728840),
   LU(206379406870), LU(635013559600), LU(1768966344600), LU(4481381406320),
   LU(10363194502115), LU(21945588357420), LU(42671977361650), LU(76360380541900),
   LU(125994627894135), LU(191991813933920), LU(270533919634160),
   LU(352870329957600), LU(426384982032100), LU(477551179875952),
   LU(495918532948104), LU(477551179875952), LU(426384982032100),
   LU(352870329957600), LU(270533919634160), LU(191991813933920),
   LU(125994627894135), LU(76360380541900), LU(42671977361650), LU(21945588357420),
   LU(10363194502115), LU(4481381406320), LU(1768966344600), LU(635013559600),
   LU(206379406870), LU(60403728840), LU(15820024220), LU(3679075400),
   LU(752538150), LU(133784560), LU(20358520), LU(2598960), LU(270725), LU(22100),
   LU(1326), LU(52), LU(1), LU(53), LU(1378), LU(23426), LU(292825), LU(2869685),
   LU(22957480), LU(154143080), LU(886322710), LU(4431613550), LU(19499099620),
   LU(76223753060), LU(266783135710), LU(841392966470), LU(2403979904200),
   LU(6250347750920), LU(14844575908435), LU(32308782859535), LU(64617565719070),
   LU(119032357903550), LU(202355008436035), LU(317986441828055),
   LU(462525733568080), LU(623404249591760), LU(779255311989700),
   LU(903936161908052), LU(973469712824056), LU(973469712824056),
   LU(903936161908052), LU(779255311989700), LU(623404249591760),
   LU(462525733568080), LU(317986441828055), LU(202355008436035),
   LU(119032357903550), LU(64617565719070), LU(32308782859535), LU(14844575908435),
   LU(6250347750920), LU(2403979904200), LU(841392966470), LU(266783135710),
   LU(76223753060), LU(19499099620), LU(4431613550), LU(886322710), LU(154143080),
   LU(22957480), LU(2869685), LU(292825), LU(23426), LU(1378), LU(53), LU(1),
   LU(54), LU(1431), LU(24804), LU(316251), LU(3162510), LU(25827165),
   LU(177100560), LU(1040465790), LU(5317936260), LU(23930713170), LU(95722852680),
   LU(343006888770), LU(1108176102180), LU(3245372870670), LU(8654327655120),
   LU(21094923659355), LU(47153358767970), LU(96926348578605), LU(183649923622620),
   LU(321387366339585), LU(520341450264090), LU(780512175396135),
   LU(1085929983159840), LU(1402659561581460), LU(1683191473897752),
   LU(1877405874732108), LU(1946939425648112), LU(1877405874732108),
   LU(1683191473897752), LU(1402659561581460), LU(1085929983159840),
   LU(780512175396135), LU(520341450264090), LU(321387366339585),
   LU(183649923622620), LU(96926348578605), LU(47153358767970), LU(21094923659355),
   LU(8654327655120), LU(3245372870670), LU(1108176102180), LU(343006888770),
   LU(95722852680), LU(23930713170), LU(5317936260), LU(1040465790), LU(177100560),
   LU(25827165), LU(3162510), LU(316251), LU(24804), LU(1431), LU(54), LU(1),
   LU(55), LU(1485), LU(26235), LU(341055), LU(3478761), LU(28989675),
   LU(202927725), LU(1217566350), LU(6358402050), LU(29248649430),
   LU(119653565850), LU(438729741450), LU(1451182990950), LU(4353548972850),
   LU(11899700525790), LU(29749251314475), LU(68248282427325), LU(144079707346575),
   LU(280576272201225), LU(505037289962205), LU(841728816603675),
   LU(1300853625660225), LU(1866442158555975), LU(2488589544741300),
   LU(3085851035479212), LU(3560597348629860), LU(3824345300380220),
   LU(3824345300380220), LU(3560597348629860), LU(3085851035479212),
   LU(2488589544741300), LU(1866442158555975), LU(1300853625660225),
   LU(841728816603675), LU(505037289962205), LU(280576272201225),
   LU(144079707346575), LU(68248282427325), LU(29749251314475), LU(11899700525790),
   LU(4353548972850), LU(1451182990950), LU(438729741450), LU(119653565850),
   LU(29248649430), LU(6358402050), LU(1217566350), LU(202927725), LU(28989675),
   LU(3478761), LU(341055), LU(26235), LU(1485), LU(55), LU(1), LU(56), LU(1540),
   LU(27720), LU(367290), LU(3819816), LU(32468436), LU(231917400), LU(1420494075),
   LU(7575968400), LU(35607051480), LU(148902215280), LU(558383307300),
   LU(1889912732400), LU(5804731963800), LU(16253249498640), LU(41648951840265),
   LU(97997533741800), LU(212327989773900), LU(424655979547800),
   LU(785613562163430), LU(1346766106565880), LU(2142582442263900),
   LU(3167295784216200), LU(4355031703297275), LU(5574440580220512),
   LU(6646448384109072), LU(7384942649010080), LU(7648690600760440),
   LU(7384942649010080), LU(6646448384109072), LU(5574440580220512),
   LU(4355031703297275), LU(3167295784216200), LU(2142582442263900),
   LU(1346766106565880), LU(785613562163430), LU(424655979547800),
   LU(212327989773900), LU(97997533741800), LU(41648951840265), LU(16253249498640),
   LU(5804731963800), LU(1889912732400), LU(558383307300), LU(148902215280),
   LU(35607051480), LU(7575968400), LU(1420494075), LU(231917400), LU(32468436),
   LU(3819816), LU(367290), LU(27720), LU(1540), LU(56), LU(1), LU(57), LU(1596),
   LU(29260), LU(395010), LU(4187106), LU(36288252), LU(264385836), LU(1652411475),
   LU(8996462475), LU(43183019880), LU(184509266760), LU(707285522580),
   LU(2448296039700), LU(7694644696200), LU(22057981462440), LU(57902201338905),
   LU(139646485582065), LU(310325523515700), LU(636983969321700),
   LU(1210269541711230), LU(2132379668729310), LU(3489348548829780),
   LU(5309878226480100), LU(7522327487513475), LU(9929472283517787),
   LU(12220888964329584), LU(14031391033119152), LU(15033633249770520),
   LU(15033633249770520), LU(14031391033119152), LU(12220888964329584),
   LU(9929472283517787), LU(7522327487513475), LU(5309878226480100),
   LU(3489348548829780), LU(2132379668729310), LU(1210269541711230),
   LU(636983969321700), LU(310325523515700), LU(139646485582065),
   LU(57902201338905), LU(22057981462440), LU(7694644696200), LU(2448296039700),
   LU(707285522580), LU(184509266760), LU(43183019880), LU(8996462475),
   LU(1652411475), LU(264385836), LU(36288252), LU(4187106), LU(395010), LU(29260),
   LU(1596), LU(57), LU(1), LU(58), LU(1653), LU(30856), LU(424270), LU(4582116),
   LU(40475358), LU(300674088), LU(1916797311), LU(10648873950), LU(52179482355),
   LU(227692286640), LU(891794789340), LU(3155581562280), LU(10142940735900),
   LU(29752626158640), LU(79960182801345), LU(197548686920970),
   LU(449972009097765), LU(947309492837400), LU(1847253511032930),
   LU(3342649210440540), LU(5621728217559090), LU(8799226775309880),
   LU(12832205713993575), LU(17451799771031262), LU(22150361247847371),
   LU(26252279997448736), LU(29065024282889672), LU(30067266499541040),
   LU(29065024282889672), LU(26252279997448736), LU(22150361247847371),
   LU(17451799771031262), LU(12832205713993575), LU(8799226775309880),
   LU(5621728217559090), LU(3342649210440540), LU(1847253511032930),
   LU(947309492837400), LU(449972009097765), LU(197548686920970),
   LU(79960182801345), LU(29752626158640), LU(10142940735900), LU(3155581562280),
   LU(891794789340), LU(227692286640), LU(52179482355), LU(10648873950),
   LU(1916797311), LU(300674088), LU(40475358), LU(4582116), LU(424270), LU(30856),
   LU(1653), LU(58), LU(1), LU(59), LU(1711), LU(32509), LU(455126), LU(5006386),
   LU(45057474), LU(341149446), LU(2217471399), LU(12565671261), LU(62828356305),
   LU(279871768995), LU(1119487075980), LU(4047376351620), LU(13298522298180),
   LU(39895566894540), LU(109712808959985), LU(277508869722315),
   LU(647520696018735), LU(1397281501935165), LU(2794563003870330),
   LU(5189902721473470), LU(8964377427999630), LU(14420954992868970),
   LU(21631432489303455), LU(30284005485024837), LU(39602161018878633),
   LU(48402641245296107), LU(55317304280338408), LU(59132290782430712),
   LU(59132290782430712), LU(55317304280338408), LU(48402641245296107),
   LU(39602161018878633), LU(30284005485024837), LU(21631432489303455),
   LU(14420954992868970), LU(8964377427999630), LU(5189902721473470),
   LU(2794563003870330), LU(1397281501935165), LU(647520696018735),
   LU(277508869722315), LU(109712808959985), LU(39895566894540),
   LU(13298522298180), LU(4047376351620), LU(1119487075980), LU(279871768995),
   LU(62828356305), LU(12565671261), LU(2217471399), LU(341149446), LU(45057474),
   LU(5006386), LU(455126), LU(32509), LU(1711), LU(59), LU(1), LU(60), LU(1770),
   LU(34220), LU(487635), LU(5461512), LU(50063860), LU(386206920), LU(2558620845),
   LU(14783142660), LU(75394027566), LU(342700125300), LU(1399358844975),
   LU(5166863427600), LU(17345898649800), LU(53194089192720), LU(149608375854525),
   LU(387221678682300), LU(925029565741050), LU(2044802197953900),
   LU(4191844505805495), LU(7984465725343800), LU(14154280149473100),
   LU(23385332420868600), LU(36052387482172425), LU(51915437974328292),
   LU(69886166503903470), LU(88004802264174740), LU(103719945525634515),
   LU(114449595062769120), LU(118264581564861424), LU(114449595062769120),
   LU(103719945525634515), LU(88004802264174740), LU(69886166503903470),
   LU(51915437974328292), LU(36052387482172425), LU(23385332420868600),
   LU(14154280149473100), LU(7984465725343800), LU(4191844505805495),
   LU(2044802197953900), LU(925029565741050), LU(387221678682300),
   LU(149608375854525), LU(53194089192720), LU(17345898649800), LU(5166863427600),
   LU(1399358844975), LU(342700125300), LU(75394027566), LU(14783142660),
   LU(2558620845), LU(386206920), LU(50063860), LU(5461512), LU(487635), LU(34220),
   LU(1770), LU(60), LU(1), LU(61), LU(1830), LU(35990), LU(521855), LU(5949147),
   LU(55525372), LU(436270780), LU(2944827765), LU(17341763505), LU(90177170226),
   LU(418094152866), LU(1742058970275), LU(6566222272575), LU(22512762077400),
   LU(70539987842520), LU(202802465047245), LU(536830054536825),
   LU(1312251244423350), LU(2969831763694950), LU(6236646703759395),
   LU(12176310231149295), LU(22138745874816900), LU(37539612570341700),
   LU(59437719903041025), LU(87967825456500717), LU(121801604478231762),
   LU(157890968768078210), LU(191724747789809255), LU(218169540588403635),
   LU(232714176627630544), LU(232714176627630544), LU(218169540588403635),
   LU(191724747789809255), LU(157890968768078210), LU(121801604478231762),
   LU(87967825456500717), LU(59437719903041025), LU(37539612570341700),
   LU(22138745874816900), LU(12176310231149295), LU(6236646703759395),
   LU(2969831763694950), LU(1312251244423350), LU(536830054536825),
   LU(202802465047245), LU(70539987842520), LU(22512762077400), LU(6566222272575),
   LU(1742058970275), LU(418094152866), LU(90177170226), LU(17341763505),
   LU(2944827765), LU(436270780), LU(55525372), LU(5949147), LU(521855), LU(35990),
   LU(1830), LU(61), LU(1), LU(62), LU(1891), LU(37820), LU(557845), LU(6471002),
   LU(61474519), LU(491796152), LU(3381098545), LU(20286591270), LU(107518933731),
   LU(508271323092), LU(2160153123141), LU(8308281242850), LU(29078984349975),
   LU(93052749919920), LU(273342452889765), LU(739632519584070),
   LU(1849081298960175), LU(4282083008118300), LU(9206478467454345),
   LU(18412956934908690), LU(34315056105966195), LU(59678358445158600),
   LU(96977332473382725), LU(147405545359541742), LU(209769429934732479),
   LU(279692573246309972), LU(349615716557887465), LU(409894288378212890),
   LU(450883717216034179), LU(465428353255261088), LU(450883717216034179),
   LU(409894288378212890), LU(349615716557887465), LU(279692573246309972),
   LU(209769429934732479), LU(147405545359541742), LU(96977332473382725),
   LU(59678358445158600), LU(34315056105966195), LU(18412956934908690),
   LU(9206478467454345), LU(4282083008118300), LU(1849081298960175),
   LU(739632519584070), LU(273342452889765), LU(93052749919920),
   LU(29078984349975), LU(8308281242850), LU(2160153123141), LU(508271323092),
   LU(107518933731), LU(20286591270), LU(3381098545), LU(491796152), LU(61474519),
   LU(6471002), LU(557845), LU(37820), LU(1891), LU(62), LU(1), LU(63), LU(1953),
   LU(39711), LU(595665), LU(7028847), LU(67945521), LU(553270671), LU(3872894697),
   LU(23667689815), LU(127805525001), LU(615790256823), LU(2668424446233),
   LU(10468434365991), LU(37387265592825), LU(122131734269895),
   LU(366395202809685), LU(1012974972473835), LU(2588713818544245),
   LU(6131164307078475), LU(13488561475572645), LU(27619435402363035),
   LU(52728013040874885), LU(93993414551124795), LU(156655690918541325),
   LU(244382877832924467), LU(357174975294274221), LU(489462003181042451),
   LU(629308289804197437), LU(759510004936100355), LU(860778005594247069),
   LU(916312070471295267), LU(916312070471295267), LU(860778005594247069),
   LU(759510004936100355), LU(629308289804197437), LU(489462003181042451),
   LU(357174975294274221), LU(244382877832924467), LU(156655690918541325),
   LU(93993414551124795), LU(52728013040874885), LU(27619435402363035),
   LU(13488561475572645), LU(6131164307078475), LU(2588713818544245),
   LU(1012974972473835), LU(366395202809685), LU(122131734269895),
   LU(37387265592825), LU(10468434365991), LU(2668424446233), LU(615790256823),
   LU(127805525001), LU(23667689815), LU(3872894697), LU(553270671), LU(67945521),
   LU(7028847), LU(595665), LU(39711), LU(1953), LU(63), LU(1), LU(64), LU(2016),
   LU(41664), LU(635376), LU(7624512), LU(74974368), LU(621216192), LU(4426165368),
   LU(27540584512), LU(151473214816), LU(743595781824), LU(3284214703056),
   LU(13136858812224), LU(47855699958816), LU(159518999862720),
   LU(488526937079580), LU(1379370175283520), LU(3601688791018080),
   LU(8719878125622720), LU(19619725782651120), LU(41107996877935680),
   LU(80347448443237920), LU(146721427591999680), LU(250649105469666120),
   LU(401038568751465792), LU(601557853127198688), LU(846636978475316672),
   LU(1118770292985239888), LU(1388818294740297792), LU(1620288010530347424),
   LU(1777090076065542336), LU(1832624140942590534), LU(1777090076065542336),
   LU(1620288010530347424), LU(1388818294740297792), LU(1118770292985239888),
   LU(846636978475316672), LU(601557853127198688), LU(401038568751465792),
   LU(250649105469666120), LU(146721427591999680), LU(80347448443237920),
   LU(41107996877935680), LU(19619725782651120), LU(8719878125622720),
   LU(3601688791018080), LU(1379370175283520), LU(488526937079580),
   LU(159518999862720), LU(47855699958816), LU(13136858812224), LU(3284214703056),
   LU(743595781824), LU(151473214816), LU(27540584512), LU(4426165368),
   LU(621216192), LU(74974368), LU(7624512), LU(635376), LU(41664), LU(2016),
   LU(64), LU(1)
}; // 16.65 kb.
#undef LU

inline uint64_t NoverK(uint n_, uint k_){
   assert_rt( n_ <= MAX_NoverK );
   assert( k_ <= n_ );
   return s_NoverK_Tab[n_*(n_-1)/2 + k_];
//    if ( n_ < MAX_NoverK )
//       return s_NoverK_Tab[n_*(n_-1)/2 + k_];
//    else
//       return NoverK_(n_, k_);
}

uint64_t binomial_coefficient(uint N, uint k){
    return NoverK(N,k);
}
