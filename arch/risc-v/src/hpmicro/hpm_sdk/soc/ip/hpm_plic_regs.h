/*
 * Copyright (c) 2021-2022 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#ifndef HPM_PLIC_H
#define HPM_PLIC_H

typedef struct {
    __RW uint32_t FEATURE;                     /* 0x0: Feature enable register */
    __RW uint32_t PRIORITY[127];               /* 0x4 - 0x1FC: Source priority */
    __R  uint8_t  RESERVED0[3584];             /* 0x200 - 0xFFF: Reserved */
    __RW uint32_t PENDING[4];                  /* 0x1000 - 0x100C: Pending status */
    __R  uint8_t  RESERVED1[112];              /* 0x1010 - 0x107F: Reserved */
    __R  uint32_t TRIGGER[4];                  /* 0x1080 - 0x108C: Trigger type */
    __R  uint8_t  RESERVED2[112];              /* 0x1090 - 0x10FF: Reserved */
    __R  uint32_t NUMBER;                      /* 0x1100: Number of supported interrupt sources and targets */
    __R  uint32_t INFO;                        /* 0x1104: Version and the maximum priority */
    __R  uint8_t  RESERVED3[3832];             /* 0x1108 - 0x1FFF: Reserved */
    struct {
        __RW uint32_t INTEN[4];                /* 0x2000 - 0x200C: machine interrupt enable */
        __R  uint8_t  RESERVED0[112];          /* 0x2010 - 0x207F: Reserved */
    } TARGETINT[2];
    __R  uint8_t  RESERVED4[2088704];          /* 0x2100 - 0x1FFFFF: Reserved */
    struct {
        __RW uint32_t THRESHOLD;               /* 0x200000: Target0 priority threshold */
        __RW uint32_t CLAIM;                   /* 0x200004: Target claim and complete */
        __R  uint8_t  RESERVED0[1016];         /* 0x200008 - 0x2003FF: Reserved */
        __RW uint32_t PPS;                     /* 0x200400: Preempted priority stack */
        __R  uint8_t  RESERVED1[3068];         /* 0x200404 - 0x200FFF: Reserved */
    } TARGETCONFIG[2];
} PLIC_Type;


/* Bitfield definition for register: FEATURE */
/*
 * VECTORED (RW)
 *
 * Vector mode enable
 * 0: Disabled
 * 1: Enabled
 */
#define PLIC_FEATURE_VECTORED_MASK (0x2U)
#define PLIC_FEATURE_VECTORED_SHIFT (1U)
#define PLIC_FEATURE_VECTORED_SET(x) (((uint32_t)(x) << PLIC_FEATURE_VECTORED_SHIFT) & PLIC_FEATURE_VECTORED_MASK)
#define PLIC_FEATURE_VECTORED_GET(x) (((uint32_t)(x) & PLIC_FEATURE_VECTORED_MASK) >> PLIC_FEATURE_VECTORED_SHIFT)

/*
 * PREEMPT (RW)
 *
 * Preemptive priority interrupt enable
 * 0: Disabled
 * 1: Enabled
 */
#define PLIC_FEATURE_PREEMPT_MASK (0x1U)
#define PLIC_FEATURE_PREEMPT_SHIFT (0U)
#define PLIC_FEATURE_PREEMPT_SET(x) (((uint32_t)(x) << PLIC_FEATURE_PREEMPT_SHIFT) & PLIC_FEATURE_PREEMPT_MASK)
#define PLIC_FEATURE_PREEMPT_GET(x) (((uint32_t)(x) & PLIC_FEATURE_PREEMPT_MASK) >> PLIC_FEATURE_PREEMPT_SHIFT)

/* Bitfield definition for register array: PRIORITY */
/*
 * PRIORITY (RW)
 *
 * Interrupt source priority. The valid range of this field is 0-7.
 * 0: Never interrupt
 * 1-7: Interrupt source priority. The larger the value, the higher the priority.
 */
#define PLIC_PRIORITY_PRIORITY_MASK (0xFFFFFFFFUL)
#define PLIC_PRIORITY_PRIORITY_SHIFT (0U)
#define PLIC_PRIORITY_PRIORITY_SET(x) (((uint32_t)(x) << PLIC_PRIORITY_PRIORITY_SHIFT) & PLIC_PRIORITY_PRIORITY_MASK)
#define PLIC_PRIORITY_PRIORITY_GET(x) (((uint32_t)(x) & PLIC_PRIORITY_PRIORITY_MASK) >> PLIC_PRIORITY_PRIORITY_SHIFT)

/* Bitfield definition for register array: PENDING */
/*
 * INTERRUPT (RW)
 *
 * The interrupt pending status of inpterrupt sources. Every interrupt source occupies 1 bit.
 */
#define PLIC_PENDING_INTERRUPT_MASK (0xFFFFFFFFUL)
#define PLIC_PENDING_INTERRUPT_SHIFT (0U)
#define PLIC_PENDING_INTERRUPT_SET(x) (((uint32_t)(x) << PLIC_PENDING_INTERRUPT_SHIFT) & PLIC_PENDING_INTERRUPT_MASK)
#define PLIC_PENDING_INTERRUPT_GET(x) (((uint32_t)(x) & PLIC_PENDING_INTERRUPT_MASK) >> PLIC_PENDING_INTERRUPT_SHIFT)

/* Bitfield definition for register array: TRIGGER */
/*
 * INTERRUPT (RO)
 *
 * The interrupt trigger type of interrupt sources. Every interrupt source occupies 1 bit.
 * 0: Level-triggered interrupt
 * 1: Edge-triggered interrupt
 */
#define PLIC_TRIGGER_INTERRUPT_MASK (0xFFFFFFFFUL)
#define PLIC_TRIGGER_INTERRUPT_SHIFT (0U)
#define PLIC_TRIGGER_INTERRUPT_GET(x) (((uint32_t)(x) & PLIC_TRIGGER_INTERRUPT_MASK) >> PLIC_TRIGGER_INTERRUPT_SHIFT)

/* Bitfield definition for register: NUMBER */
/*
 * NUM_TARGET (RO)
 *
 * The number of supported targets
 */
#define PLIC_NUMBER_NUM_TARGET_MASK (0xFFFF0000UL)
#define PLIC_NUMBER_NUM_TARGET_SHIFT (16U)
#define PLIC_NUMBER_NUM_TARGET_GET(x) (((uint32_t)(x) & PLIC_NUMBER_NUM_TARGET_MASK) >> PLIC_NUMBER_NUM_TARGET_SHIFT)

/*
 * NUM_INTERRUPT (RO)
 *
 * The number of supported interrupt sources
 */
#define PLIC_NUMBER_NUM_INTERRUPT_MASK (0xFFFFU)
#define PLIC_NUMBER_NUM_INTERRUPT_SHIFT (0U)
#define PLIC_NUMBER_NUM_INTERRUPT_GET(x) (((uint32_t)(x) & PLIC_NUMBER_NUM_INTERRUPT_MASK) >> PLIC_NUMBER_NUM_INTERRUPT_SHIFT)

/* Bitfield definition for register: INFO */
/*
 * MAX_PRIORITY (RO)
 *
 * The maximum priority supported
 */
#define PLIC_INFO_MAX_PRIORITY_MASK (0xFFFF0000UL)
#define PLIC_INFO_MAX_PRIORITY_SHIFT (16U)
#define PLIC_INFO_MAX_PRIORITY_GET(x) (((uint32_t)(x) & PLIC_INFO_MAX_PRIORITY_MASK) >> PLIC_INFO_MAX_PRIORITY_SHIFT)

/*
 * VERSION (RO)
 *
 * The version of the PLIC design
 */
#define PLIC_INFO_VERSION_MASK (0xFFFFU)
#define PLIC_INFO_VERSION_SHIFT (0U)
#define PLIC_INFO_VERSION_GET(x) (((uint32_t)(x) & PLIC_INFO_VERSION_MASK) >> PLIC_INFO_VERSION_SHIFT)

/* Bitfield definition for register of struct array TARGETINT: INTEN0 */
/*
 * INTERRUPT (RW)
 *
 * The interrupt enable bit for interrupt. Every interrupt source occupies 1 bit.
 */
#define PLIC_TARGETINT_INTEN_INTERRUPT_MASK (0xFFFFFFFFUL)
#define PLIC_TARGETINT_INTEN_INTERRUPT_SHIFT (0U)
#define PLIC_TARGETINT_INTEN_INTERRUPT_SET(x) (((uint32_t)(x) << PLIC_TARGETINT_INTEN_INTERRUPT_SHIFT) & PLIC_TARGETINT_INTEN_INTERRUPT_MASK)
#define PLIC_TARGETINT_INTEN_INTERRUPT_GET(x) (((uint32_t)(x) & PLIC_TARGETINT_INTEN_INTERRUPT_MASK) >> PLIC_TARGETINT_INTEN_INTERRUPT_SHIFT)

/* Bitfield definition for register of struct array TARGETCONFIG: THRESHOLD */
/*
 * THRESHOLD (RW)
 *
 * Interrupt priority threshold.
 */
#define PLIC_TARGETCONFIG_THRESHOLD_THRESHOLD_MASK (0xFFFFFFFFUL)
#define PLIC_TARGETCONFIG_THRESHOLD_THRESHOLD_SHIFT (0U)
#define PLIC_TARGETCONFIG_THRESHOLD_THRESHOLD_SET(x) (((uint32_t)(x) << PLIC_TARGETCONFIG_THRESHOLD_THRESHOLD_SHIFT) & PLIC_TARGETCONFIG_THRESHOLD_THRESHOLD_MASK)
#define PLIC_TARGETCONFIG_THRESHOLD_THRESHOLD_GET(x) (((uint32_t)(x) & PLIC_TARGETCONFIG_THRESHOLD_THRESHOLD_MASK) >> PLIC_TARGETCONFIG_THRESHOLD_THRESHOLD_SHIFT)

/* Bitfield definition for register of struct array TARGETCONFIG: CLAIM */
/*
 * INTERRUPT_ID (RW)
 *
 * On reads, indicating the interrupt source that has being claimed. On writes, indicating the interrupt source that has been handled (completed).
 */
#define PLIC_TARGETCONFIG_CLAIM_INTERRUPT_ID_MASK (0x3FFU)
#define PLIC_TARGETCONFIG_CLAIM_INTERRUPT_ID_SHIFT (0U)
#define PLIC_TARGETCONFIG_CLAIM_INTERRUPT_ID_SET(x) (((uint32_t)(x) << PLIC_TARGETCONFIG_CLAIM_INTERRUPT_ID_SHIFT) & PLIC_TARGETCONFIG_CLAIM_INTERRUPT_ID_MASK)
#define PLIC_TARGETCONFIG_CLAIM_INTERRUPT_ID_GET(x) (((uint32_t)(x) & PLIC_TARGETCONFIG_CLAIM_INTERRUPT_ID_MASK) >> PLIC_TARGETCONFIG_CLAIM_INTERRUPT_ID_SHIFT)

/* Bitfield definition for register of struct array TARGETCONFIG: PPS */
/*
 * PRIORITY_PREEMPTED (RW)
 *
 * Each bit indicates if the corresponding priority level has been preempted by a higher-priority interrupt.
 */
#define PLIC_TARGETCONFIG_PPS_PRIORITY_PREEMPTED_MASK (0xFFFFFFFFUL)
#define PLIC_TARGETCONFIG_PPS_PRIORITY_PREEMPTED_SHIFT (0U)
#define PLIC_TARGETCONFIG_PPS_PRIORITY_PREEMPTED_SET(x) (((uint32_t)(x) << PLIC_TARGETCONFIG_PPS_PRIORITY_PREEMPTED_SHIFT) & PLIC_TARGETCONFIG_PPS_PRIORITY_PREEMPTED_MASK)
#define PLIC_TARGETCONFIG_PPS_PRIORITY_PREEMPTED_GET(x) (((uint32_t)(x) & PLIC_TARGETCONFIG_PPS_PRIORITY_PREEMPTED_MASK) >> PLIC_TARGETCONFIG_PPS_PRIORITY_PREEMPTED_SHIFT)



/* PRIORITY register group index macro definition */
#define PLIC_PRIORITY_PRIORITY1 (0UL)
#define PLIC_PRIORITY_PRIORITY2 (1UL)
#define PLIC_PRIORITY_PRIORITY3 (2UL)
#define PLIC_PRIORITY_PRIORITY4 (3UL)
#define PLIC_PRIORITY_PRIORITY5 (4UL)
#define PLIC_PRIORITY_PRIORITY6 (5UL)
#define PLIC_PRIORITY_PRIORITY7 (6UL)
#define PLIC_PRIORITY_PRIORITY8 (7UL)
#define PLIC_PRIORITY_PRIORITY9 (8UL)
#define PLIC_PRIORITY_PRIORITY10 (9UL)
#define PLIC_PRIORITY_PRIORITY11 (10UL)
#define PLIC_PRIORITY_PRIORITY12 (11UL)
#define PLIC_PRIORITY_PRIORITY13 (12UL)
#define PLIC_PRIORITY_PRIORITY14 (13UL)
#define PLIC_PRIORITY_PRIORITY15 (14UL)
#define PLIC_PRIORITY_PRIORITY16 (15UL)
#define PLIC_PRIORITY_PRIORITY17 (16UL)
#define PLIC_PRIORITY_PRIORITY18 (17UL)
#define PLIC_PRIORITY_PRIORITY19 (18UL)
#define PLIC_PRIORITY_PRIORITY20 (19UL)
#define PLIC_PRIORITY_PRIORITY21 (20UL)
#define PLIC_PRIORITY_PRIORITY22 (21UL)
#define PLIC_PRIORITY_PRIORITY23 (22UL)
#define PLIC_PRIORITY_PRIORITY24 (23UL)
#define PLIC_PRIORITY_PRIORITY25 (24UL)
#define PLIC_PRIORITY_PRIORITY26 (25UL)
#define PLIC_PRIORITY_PRIORITY27 (26UL)
#define PLIC_PRIORITY_PRIORITY28 (27UL)
#define PLIC_PRIORITY_PRIORITY29 (28UL)
#define PLIC_PRIORITY_PRIORITY30 (29UL)
#define PLIC_PRIORITY_PRIORITY31 (30UL)
#define PLIC_PRIORITY_PRIORITY32 (31UL)
#define PLIC_PRIORITY_PRIORITY33 (32UL)
#define PLIC_PRIORITY_PRIORITY34 (33UL)
#define PLIC_PRIORITY_PRIORITY35 (34UL)
#define PLIC_PRIORITY_PRIORITY36 (35UL)
#define PLIC_PRIORITY_PRIORITY37 (36UL)
#define PLIC_PRIORITY_PRIORITY38 (37UL)
#define PLIC_PRIORITY_PRIORITY39 (38UL)
#define PLIC_PRIORITY_PRIORITY40 (39UL)
#define PLIC_PRIORITY_PRIORITY41 (40UL)
#define PLIC_PRIORITY_PRIORITY42 (41UL)
#define PLIC_PRIORITY_PRIORITY43 (42UL)
#define PLIC_PRIORITY_PRIORITY44 (43UL)
#define PLIC_PRIORITY_PRIORITY45 (44UL)
#define PLIC_PRIORITY_PRIORITY46 (45UL)
#define PLIC_PRIORITY_PRIORITY47 (46UL)
#define PLIC_PRIORITY_PRIORITY48 (47UL)
#define PLIC_PRIORITY_PRIORITY49 (48UL)
#define PLIC_PRIORITY_PRIORITY50 (49UL)
#define PLIC_PRIORITY_PRIORITY51 (50UL)
#define PLIC_PRIORITY_PRIORITY52 (51UL)
#define PLIC_PRIORITY_PRIORITY53 (52UL)
#define PLIC_PRIORITY_PRIORITY54 (53UL)
#define PLIC_PRIORITY_PRIORITY55 (54UL)
#define PLIC_PRIORITY_PRIORITY56 (55UL)
#define PLIC_PRIORITY_PRIORITY57 (56UL)
#define PLIC_PRIORITY_PRIORITY58 (57UL)
#define PLIC_PRIORITY_PRIORITY59 (58UL)
#define PLIC_PRIORITY_PRIORITY60 (59UL)
#define PLIC_PRIORITY_PRIORITY61 (60UL)
#define PLIC_PRIORITY_PRIORITY62 (61UL)
#define PLIC_PRIORITY_PRIORITY63 (62UL)
#define PLIC_PRIORITY_PRIORITY64 (63UL)
#define PLIC_PRIORITY_PRIORITY65 (64UL)
#define PLIC_PRIORITY_PRIORITY66 (65UL)
#define PLIC_PRIORITY_PRIORITY67 (66UL)
#define PLIC_PRIORITY_PRIORITY68 (67UL)
#define PLIC_PRIORITY_PRIORITY69 (68UL)
#define PLIC_PRIORITY_PRIORITY70 (69UL)
#define PLIC_PRIORITY_PRIORITY71 (70UL)
#define PLIC_PRIORITY_PRIORITY72 (71UL)
#define PLIC_PRIORITY_PRIORITY73 (72UL)
#define PLIC_PRIORITY_PRIORITY74 (73UL)
#define PLIC_PRIORITY_PRIORITY75 (74UL)
#define PLIC_PRIORITY_PRIORITY76 (75UL)
#define PLIC_PRIORITY_PRIORITY77 (76UL)
#define PLIC_PRIORITY_PRIORITY78 (77UL)
#define PLIC_PRIORITY_PRIORITY79 (78UL)
#define PLIC_PRIORITY_PRIORITY80 (79UL)
#define PLIC_PRIORITY_PRIORITY81 (80UL)
#define PLIC_PRIORITY_PRIORITY82 (81UL)
#define PLIC_PRIORITY_PRIORITY83 (82UL)
#define PLIC_PRIORITY_PRIORITY84 (83UL)
#define PLIC_PRIORITY_PRIORITY85 (84UL)
#define PLIC_PRIORITY_PRIORITY86 (85UL)
#define PLIC_PRIORITY_PRIORITY87 (86UL)
#define PLIC_PRIORITY_PRIORITY88 (87UL)
#define PLIC_PRIORITY_PRIORITY89 (88UL)
#define PLIC_PRIORITY_PRIORITY90 (89UL)
#define PLIC_PRIORITY_PRIORITY91 (90UL)
#define PLIC_PRIORITY_PRIORITY92 (91UL)
#define PLIC_PRIORITY_PRIORITY93 (92UL)
#define PLIC_PRIORITY_PRIORITY94 (93UL)
#define PLIC_PRIORITY_PRIORITY95 (94UL)
#define PLIC_PRIORITY_PRIORITY96 (95UL)
#define PLIC_PRIORITY_PRIORITY97 (96UL)
#define PLIC_PRIORITY_PRIORITY98 (97UL)
#define PLIC_PRIORITY_PRIORITY99 (98UL)
#define PLIC_PRIORITY_PRIORITY100 (99UL)
#define PLIC_PRIORITY_PRIORITY101 (100UL)
#define PLIC_PRIORITY_PRIORITY102 (101UL)
#define PLIC_PRIORITY_PRIORITY103 (102UL)
#define PLIC_PRIORITY_PRIORITY104 (103UL)
#define PLIC_PRIORITY_PRIORITY105 (104UL)
#define PLIC_PRIORITY_PRIORITY106 (105UL)
#define PLIC_PRIORITY_PRIORITY107 (106UL)
#define PLIC_PRIORITY_PRIORITY108 (107UL)
#define PLIC_PRIORITY_PRIORITY109 (108UL)
#define PLIC_PRIORITY_PRIORITY110 (109UL)
#define PLIC_PRIORITY_PRIORITY111 (110UL)
#define PLIC_PRIORITY_PRIORITY112 (111UL)
#define PLIC_PRIORITY_PRIORITY113 (112UL)
#define PLIC_PRIORITY_PRIORITY114 (113UL)
#define PLIC_PRIORITY_PRIORITY115 (114UL)
#define PLIC_PRIORITY_PRIORITY116 (115UL)
#define PLIC_PRIORITY_PRIORITY117 (116UL)
#define PLIC_PRIORITY_PRIORITY118 (117UL)
#define PLIC_PRIORITY_PRIORITY119 (118UL)
#define PLIC_PRIORITY_PRIORITY120 (119UL)
#define PLIC_PRIORITY_PRIORITY121 (120UL)
#define PLIC_PRIORITY_PRIORITY122 (121UL)
#define PLIC_PRIORITY_PRIORITY123 (122UL)
#define PLIC_PRIORITY_PRIORITY124 (123UL)
#define PLIC_PRIORITY_PRIORITY125 (124UL)
#define PLIC_PRIORITY_PRIORITY126 (125UL)
#define PLIC_PRIORITY_PRIORITY127 (126UL)

/* PENDING register group index macro definition */
#define PLIC_PENDING_PENDING0 (0UL)
#define PLIC_PENDING_PENDING1 (1UL)
#define PLIC_PENDING_PENDING2 (2UL)
#define PLIC_PENDING_PENDING3 (3UL)

/* TRIGGER register group index macro definition */
#define PLIC_TRIGGER_TRIGGER0 (0UL)
#define PLIC_TRIGGER_TRIGGER1 (1UL)
#define PLIC_TRIGGER_TRIGGER2 (2UL)
#define PLIC_TRIGGER_TRIGGER3 (3UL)

/* INTEN register group index macro definition */
#define PLIC_TARGETINT_INTEN_INTEN0 (0UL)
#define PLIC_TARGETINT_INTEN_INTEN1 (1UL)
#define PLIC_TARGETINT_INTEN_INTEN2 (2UL)
#define PLIC_TARGETINT_INTEN_INTEN3 (3UL)

/* TARGETINT register group index macro definition */
#define PLIC_TARGETINT_TARGET0 (0UL)
#define PLIC_TARGETINT_TARGET1 (1UL)

/* TARGETCONFIG register group index macro definition */
#define PLIC_TARGETCONFIG_TARGET0 (0UL)
#define PLIC_TARGETCONFIG_TARGET1 (1UL)


#endif /* HPM_PLIC_H */