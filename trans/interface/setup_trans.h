INTERFACE
SUBROUTINE SETUP_TRANS(KSMAX,KDGL,KLOEN,LDLINEAR_GRID,LDSPLIT,PSTRET,&
&KTMAX,KRESOL,PWEIGHT,LDGRIDONLY,LDUSERPNM,LDKEEPRPNM,LDUSEFLT,&
&LDSPSETUPONLY,LDPNMONLY,LDUSEFFT992,LDUSEFFTW)

!**** *SETUP_TRANS* - Setup transform package for specific resolution

!     Purpose.
!     --------
!     To setup for making spectral transforms. Each call to this routine
!     creates a new resolution up to a maximum of NMAX_RESOL set up in
!     SETUP_TRANS0. You need to call SETUP_TRANS0 before this routine can
!     be called.

!**   Interface.
!     ----------
!     CALL SETUP_TRANS(...)

!     Explicit arguments : KLOEN,LDLINEAR_GRID,LDSPLIT are optional arguments
!     -------------------- 
!     KSMAX - spectral truncation required
!     KDGL  - number of Gaussian latitudes
!     KLOEN(:) - number of points on each Gaussian latitude [2*KDGL]
!     LDSPLIT - true if split latitudes in grid-point space [false]
!     LDLINEAR_GRID - true if linear grid
!     KTMAX - truncation order for tendencies?
!     KRESOL - the resolution identifier
!     PWEIGHT - the weight per grid-point (for a weighted distribution)
!     LDGRIDONLY - true if only grid space is required

!     KSMAX,KDGL,KTMAX and KLOEN are GLOBAL variables desribing the resolution
!     in spectral and grid-point space

!     LDSPLIT describe the distribution among processors of grid-point data and
!     has no relevance if you are using a single processor

!     LDUSEFLT   - use Fast Legandre Transform (Butterfly algorithm)
!     LDUSERPNM  - Use Belusov to compute legendre pol. (else new alg.)
!     LDKEEPRPNM - Keep Legendre Polynomials (only applicable when using
!                  FLT, otherwise always kept)
!     LDPNMONLY  - Compute the Legendre polynomialsonly, not the FFTs.
!     LDUSEFFT992 - Use FF992 for FFTs (default)
!     LDUSEFFTW   - Use FFTW for FFTs
 
!     Method.
!     -------

!     Externals.  SET_RESOL   - set resolution
!     ----------  SETUP_DIMS  - setup distribution independent dimensions
!                 SUMP_TRANS_PRELEG - first part of setup of distr. environment
!                 SULEG - Compute Legandre polonomial and Gaussian 
!                         Latitudes and Weights
!                 SETUP_GEOM - Compute arrays related to grid-point geometry
!                 SUMP_TRANS - Second part of setup of distributed environment
!                 SUFFT - setup for FFT

!     Author.
!     -------
!        Mats Hamrud *ECMWF*

!     Modifications.
!     --------------
!        Original : 00-03-03

!     ------------------------------------------------------------------

USE PARKIND1  ,ONLY : JPIM     ,JPRB


IMPLICIT NONE

! Dummy arguments

INTEGER(KIND=JPIM) ,INTENT(IN) :: KSMAX,KDGL
INTEGER(KIND=JPIM) ,OPTIONAL,INTENT(IN) :: KLOEN(:)
LOGICAL   ,OPTIONAL,INTENT(IN) :: LDLINEAR_GRID
LOGICAL   ,OPTIONAL,INTENT(IN) :: LDSPLIT
INTEGER(KIND=JPIM) ,OPTIONAL,INTENT(IN) :: KTMAX
INTEGER(KIND=JPIM) ,OPTIONAL,INTENT(OUT):: KRESOL
REAL(KIND=JPRB)    ,OPTIONAL,INTENT(IN) :: PWEIGHT(:)
REAL(KIND=JPRB)    ,OPTIONAL,INTENT(IN) :: PSTRET
LOGICAL   ,OPTIONAL,INTENT(IN):: LDGRIDONLY
LOGICAL   ,OPTIONAL,INTENT(IN):: LDUSEFLT
LOGICAL   ,OPTIONAL,INTENT(IN):: LDUSERPNM
LOGICAL   ,OPTIONAL,INTENT(IN):: LDKEEPRPNM
LOGICAL   ,OPTIONAL,INTENT(IN):: LDPNMONLY
LOGICAL   ,OPTIONAL,INTENT(IN):: LDSPSETUPONLY
LOGICAL   ,OPTIONAL,INTENT(IN):: LDUSEFFT992
LOGICAL   ,OPTIONAL,INTENT(IN):: LDUSEFFTW


END SUBROUTINE SETUP_TRANS


END INTERFACE
