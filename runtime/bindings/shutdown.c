/***********************************************************************/
/*                                                                     */
/*                           Objective Caml                            */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 1996 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

/* $Id: shutdown.c,v 1.11 2005/03/24 17:20:53 doligez Exp $ */

#include <fail.h>
#include <mlvalues.h>
#include "unixsupport.h"

#include <sys/socket.h>

static int shutdown_command_table[] = {
  0, 1, 2
};

CAMLprim value unix_shutdown(value sock, value cmd)
{
  if (shutdown(Int_val(sock), shutdown_command_table[Int_val(cmd)]) == -1)
    uerror("shutdown", Nothing);
  return Val_unit;
}