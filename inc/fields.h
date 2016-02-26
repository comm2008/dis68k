// Instruction Field Structs // 

#define OP_SIZE_BYTE 0
#define OP_SIZE_WORD 1
#define OP_SIZE_LONG 2

typedef struct i68k_abcd {
	// reg_or_mem:
	//   0 => ABCD -(Ay), -(Ax)
	//   1 => ABCD Dy, Dx
	char reg_or_mem;
	char reg_x;
	char reg_y;
} i68k_abcd;

static int encode_abcd(i68k_abcd i, char *buf, size_t count)
{
	if(count < 2)
	{
		return -1;
	}

	buf[0] = 0xC1 | ( ( i.reg_x & 0x7 ) << 1 );
	buf[1] = 0x00 | ( ( i.reg_or_mem & 0x1 ) << 3 ) | ( i.reg_y & 0x7 );

	return 2;
}

static int decode_abcd(char *buf, size_t count, i68k_abcd *i)
{
	return 2;
}

typedef struct i68k_add {
	char reg;
	char opmode;
	char effective_address;
} i68k_add;

typedef struct i68k_adda {
	char reg;
	char opmode;
	char effective_address;
} i68k_adda;

typedef struct i68k_addi {
	char reg;
	char opmode;
	char effective_address;
} i68k_addi;

typedef struct i68k_addq {
} i68k_addq;

typedef struct i68k_addx {
} i68k_addx;

typedef struct i68k_and {
} i68k_and;

typedef struct i68k_andi {
} i68k_andi;

typedef struct i68k_asl {
} i68k_asl;

typedef struct i68k_asr {
} i68k_asr;

typedef struct i68k_bchg {
} i68k_bchg;

typedef struct i68k_bclr {
} i68k_bclr;

typedef struct i68k_bra {
} i68k_bra;

typedef struct i68k_bset {
} i68k_bset;

typedef struct i68k_bsr {
} i68k_bsr;

typedef struct i68k_btst {
} i68k_btst;

typedef struct i68k_chk {
} i68k_chk;

typedef struct i68k_clr {
} i68k_clr;

typedef struct i68k_cmp {
} i68k_cmp;

typedef struct i68k_cmpi {
} i68k_cmpi;

typedef struct i68k_cmpm {
} i68k_cmpm;

typedef struct i68k_divs {
} i68k_divs;

typedef struct i68k_divu {
} i68k_divu;

typedef struct i68k_eor {
} i68k_eor;

typedef struct i68k_eori {
} i68k_eori;

typedef struct i68k_exg {
} i68k_exg;

typedef struct i68k_ext {
} i68k_ext;

typedef struct i68k_illegal {
} i68k_illegal;

typedef struct i68k_jmp {
} i68k_jmp;

typedef struct i68k_jsr {
} i68k_jsr;

typedef struct i68k_lea {
} i68k_lea;

typedef struct i68k_link {
} i68k_link;

typedef struct i68k_lsl {
} i68k_lsl;

typedef struct i68k_lsr {
} i68k_lsr;

typedef struct i68k_move {
} i68k_move;

typedef struct i68k_movea {
} i68k_movea;

typedef struct i68k_movem {
} i68k_movem;

typedef struct i68k_movep {
} i68k_movep;

typedef struct i68k_moveq {
} i68k_moveq;

typedef struct i68k_move_usp {
} i68k_move_usp;

typedef struct i68k_nbcd {
} i68k_nbcd;

typedef struct i68k_neg {
} i68k_neg;

typedef struct i68k_negx {
} i68k_negx;

typedef struct i68k_nop {
} i68k_nop;

typedef struct i68k_not {
} i68k_not;

typedef struct i68k_ori {
} i68k_ori;

typedef struct i68k_pea {
} i68k_pea;

typedef struct i68k_reset {
} i68k_reset;

typedef struct i68k_rol {
} i68k_rol;

typedef struct i68k_ror {
} i68k_ror;

typedef struct i68k_roxl {
} i68k_roxl;

typedef struct i68k_roxr {
} i68k_roxr;

typedef struct i68k_rte {
} i68k_rte;

typedef struct i68k_rtr {
} i68k_rtr;

typedef struct i68k_rts {
} i68k_rts;

typedef struct i68k_sbcd {
} i68k_sbcd;

typedef struct i68k_stop {
} i68k_stop;

typedef struct i68k_sub {
} i68k_sub;

typedef struct i68k_subi {
} i68k_subi;

typedef struct i68k_subq {
} i68k_subq;

typedef struct i68k_subx {
} i68k_subx;

typedef struct i68k_swap {
} i68k_swap;

typedef struct i68k_tas {
} i68k_tas;

typedef struct i68k_trapv {
} i68k_trapv;

typedef struct i68k_tst {
} i68k_tst;

typedef struct i68k_unlk {
} i68k_unlk;

union i68k_fields {
	i68k_abcd     abcd;
	i68k_add      add;
	i68k_adda     adda;
	i68k_addi     addi;
	i68k_addq     addq;
	i68k_addx     addx;
	i68k_and      and;
	i68k_andi     andi;
	i68k_asl      asl;
	i68k_asr      asr;
	i68k_bchg     bchg;
	i68k_bclr     bclr;
	i68k_bra      bra;
	i68k_bset     bset;
	i68k_bsr      bsr;
	i68k_btst     btst;
	i68k_chk      chk;
	i68k_clr      clr;
	i68k_cmp      cmp;
	i68k_cmpi     cmpi;
	i68k_cmpm     cmpm;
	i68k_divs     divs;
	i68k_divu     divu;
	i68k_eor      eor;
	i68k_eori     eori;
	i68k_exg      exg;
	i68k_ext      ext;
	i68k_illegal  illegal;
	i68k_jmp      jmp;
	i68k_jsr      jsr;
	i68k_lea      lea;
	i68k_link     link;
	i68k_lsl      lsl;
	i68k_lsr      lsr;
	i68k_move     move;
	i68k_movea    movea;
	i68k_movem    movem;
	i68k_movep    movep;
	i68k_moveq    moveq;
	i68k_move_usp move_usp;
	i68k_nbcd     nbcd;
	i68k_neg      neg;
	i68k_negx     negx;
	i68k_nop      nop;
	i68k_not      not;
	i68k_ori      ori;
	i68k_pea      pea;
	i68k_reset    reset;
	i68k_rol      rol;
	i68k_ror      ror;
	i68k_roxl     roxl;
	i68k_roxr     roxr;
	i68k_rte      rte;
	i68k_rtr      rtr;
	i68k_rts      rts;
	i68k_sbcd     sbcd;
	i68k_stop     stop;
	i68k_sub      sub;
	i68k_subi     subi;
	i68k_subq     subq;
	i68k_subx     subx;
	i68k_swap     swap;
	i68k_tas      tas;
	i68k_trapv    trapv;
	i68k_tst      tst;
	i68k_unlk     unlk;
};
