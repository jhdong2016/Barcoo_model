/*** svn $Id: barcoo.h 139 2008-01-10 00:17:29Z robertson $
*******************************************************************************
** Copyright (c) 2002-2008 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options for Vertical Mixing Parameterization Evaluation
**
** Application flag:   Barcoo
** Input script:       barc_??.in
*/
#define ROBIN_MODEL
#define NONLINEAR

#define ROBIN
#define SOLVE3D
#define SALINITY
#define CURVGRID
#define SPHERICAL
#define SPLINES
#define LARGE
#define BV_FREQUENCY
#undef PERFECT_RESTART

#undef AVERAGES
#undef ICESHELF
#undef SEAICE
#undef BTSEAICE
#undef MASKING
#undef TSUNAMI

#undef STATIONS
#define NO_SURFACE_HEAT_FLUX

/************************************************/
/* Diagnostics Switches. Set Diagnostics on     */
/* Upper Level. Submodules activated below      */
/************************************************/
/*#undef DIAGNOSTICS
#undef DIAGNOSTICS_UV
#undef DIAGNOSTICS_TS*/
/*#define DIAGNOSTIC_TIDES&/ 

/* Robin's FLUX Reporting Variables                        */
/* First define FLUX then define the FLUX Varuables You Want Reported */

#define BULK_FLUXES
#undef FLUX
#undef TRANSPORTS 
#define ENERGY_AVERAGES

/*************************************************/
/* Advection Term Switches                       */
/*************************************************/
#define UV_ADV
/*#define UV_C4ADVECTION*/
#define UV_U3ADV_SPLIT
#undef UV_C2ADVECTION
#undef TS_C2ADVECTION
#define TS_A4HADVECTION
#define TS_A4VADVECTION
/*#define TS_C4HADVECTION                           
#define TS_C4VADVECTION*/

/*************************************************/
/* Diffusion Terms                               */
/*************************************************/
#define VISC_3DCOEF
#define UV_VIS2
#define MIX_S_UV
#define TS_DIF2
#define MIX_GEO_TS


/*************************************************/
/* Pressure Gradient and Equation of State       */
/*************************************************/
#define DJ_GRADPS
/*#define PJ_GRADP*/
/*#define PJ_GRADPQ2
#define NEUMANN*/
/*#define PJ_GRADPQ4
#define NEUMANN */ /* There is also a NEUMANN option here */
#undef SASHA_GRADPS

#define NONLIN_EOS
#undef SASHA_EOS
#undef SPLIT_EOS

/**************************************************/
/* Coriolis Term                                  */
/**************************************************/
#define UV_COR

/**************************************************/
/* Bottom Drag. Applied to Bottom cell i          */
/**************************************************/
#define UV_QDRAG

/*************************************************/
/* Vertical Mixing Parameterizations             */
/* Pick One. Some subswitches included           */
/*************************************************/
#undef NN_MIXING  /* Naka... Ninno  MY replacement */
#undef JK_MIXING  /* Jody Klymak's internal mixing */
#undef RR_MIXING   /* Robin Robertson's internal mixing */
#undef POLZIN_MIXING
#define MY25_MIXING
#undef LMD_MIXING
#undef GOM_MIXING
#undef GLS_MIXING
#undef BVF_MIXING
#ifdef MY25_MIXING
# define TKE_MIXING
#elif defined GLS_MIXING 
# define TKE_MIXING
#elif defined NN_MIXING 
# define TKE_MIXING
#elif defined POLZIN_MIXING 
# define TKE_MIXING
#endif

#ifdef MY25_MIXING
# define N2S2_HORAVG
# define K_C4ADVECTION

#elif defined  LMD_MIXING
# define SHORTWAVE
# define LONGWAVE
# define ANA_SRFLUX
# define LMD_CONVEC 
# undef LMD_DDMIX 
# define LMD_RIMIX
# define LMD_SKPP
# define LMD_BKPP
#endif

/*************************************************/
/*     Ice Shelf  Switches                       */
/*************************************************/
#ifdef ICESHELF
# define JM2006_EOS
# undef ICESHELF_NOTHERMO
# undef ISOMIP
# undef HOLLANDJENKINS
# define HOLLANDJENKINS_RR
# undef ICE_THERMO
#endif

/*************************************************/
/* Tides Defines to Enable Some Tidal            */
/* Features.                                     */
/*************************************************/

#define ROBINTIDES
#define SSH_TIDES
#define UV_TIDES
#ifdef SSH_TIDES 
# define FSOBC_REDUCED
# undef ZCLIMATOLOGY
# undef ADD_FSOBC
#endif
#ifdef UV_TIDES
# undef M2CLIMATOLOGY
# undef ADD_M2OBC
#endif
#define RAMP_TIDES
#undef AVERAGES_DETIDE

/**************************************************/
/* Boundary Conditions                            */
/**************************************************/
#define OBC
#define ANA_FSOBC
#define ANA_M2OBC
#define ANA_M3OBC
#define RADIATION_2D
#define NORTH_FSCHAPMAN
#define NORTH_M2FLATHER

#define SOUTH_FSCHAPMAN
#define SOUTH_M2FLATHER

#undef SOUTHERN_WALL
#define EAST_FSCHAPMAN
#define EAST_M2FLATHER
#undef EAST_M2CLAMPED

#define WEST_FSCHAPMAN
#define WEST_M2FLATHER

# define WEST_M3OBC       /* These Boundary defines create needed */
# define EAST_M3OBC       /* Fields for Flow Relaxation to work   */
# define NORTH_M3OBC
# define SOUTH_M3OBC

# define ANA_TOBC
# define WEST_TOBC
# define EAST_TOBC
# define NORTH_TOBC
# define SOUTH_TOBC

#undef FLOW_RELAX     /* Here is Robin'sFlow Relaxation Boundary */
/*   It will only work with   UV_U3ADV_SPLIT   at least now */

#ifdef FLOW_RELAX
# define WEST_TFLOWRELAXATION
# define EAST_TFLOWRELAXATION
# define SOUTH_TFLOWRELAXATION
# define NORTH_TFLOWRELAXATION

# define WEST_M3FLOWRELAXATION
# define EAST_M3FLOWRELAXATION
# define SOUTH_M3FLOWRELAXATION
# define NORTH_M3FLOWRELAXATION

#else                     /* Other Open Boundary conditions */

# define NORTH_M3RADIATION
# define NORTH_TRADIATION
# undef NORTH_TCLAMPED
# define SOUTH_M3RADIATION
# define SOUTH_TRADIATION
# undef SOUTH_TCLAMPED
# define WEST_M3RADIATION
# define WEST_TRADIATION
# undef WEST_TCLAMPED
# define EAST_M3RADIATION
# undef EAST_M3CLAMPED
# define EAST_TRADIATION
# undef EAST_TCLAMPED
#endif


#ifdef SSH_TIDES
/*# define ANA_SSH */
#endif
#ifdef UV_TIDES
# define ANA_M2CLIMA
#endif
#define ANA_TCLIMA

#define TEMP_SALINITY

#ifdef TEMP_SALINITY

/* Here are fluxes for a basic run with just temp and salinity */


/***************************************************/
/* Various Functional Modules. Some interdepencies */
/* Outlined in the analytical idefs below.         */
/****************************************************/

#define ANA_WINDS
#define ANA_HUMIDITY
#define ANA_CLOUD
#define ANA_TAIR
#define ANA_PAIR
#define ANA_RAIN
#define ANA_SRFLUX
#define ANA_SSFLUX
#define ANA_SMFLUX
#define ANA_BTFLUX
#define ANA_SSFLUX
#define ANA_BSFLUX
#define SHORTWAVE
#define LONGWAVE
#endif

#undef RADFLUX
#ifdef RADFLUX

/*After LONGWAVE defined we need cloud Cover */

/* in the ANA_CLOUD Functional module                           */
# define ANA_CLOUD        /* Check What Value                   */
# define ANA_TAIR         /* tair 35 C                          */
# define ANA_HUMIDITY     /* .8, 80%  humidity at surface       */
# define ANA_PAIR
# define ANA_RAIN         / * No rain                           */

#endif



/******************************/
/* Bruno's functionals Below  */
/******************************/

/* #define BTSEAICE */

/* Done with diagnostices Bruno's Stuff Below */ 

#ifdef BTSEAICE
# undef SI_DYNAMIC
# define SI_THERMODYN
# undef SI_FREEDRIFT     /* Without sea ice interactions */
# undef SI_CAVITATING    /* With only resistance in compression - Flato Hibler*/
# undef SI_GRANULAR     /* With resistance in compression and shear - Tremblay Mysak */
# define ANA_HUMIDITY
# define ANA_CLOUD
# define ANA_TAIR
# define ANA_PAIR
# define ANA_RAIN
# define ANA_SRFLUX
# define ANA_SSFLUX
# define ANA_SMFLUX
/*# define ANA_STFLUX*/
# define ANA_BSFLUX
# define ANA_BTFLUX
# define LONGWAVE
# define ANA_WINDS
#endif

