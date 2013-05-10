/*
   Copyright (c) 2013 Andrew Hatfield <andrew.hatfield@cynosureservices.com>
   This file is part of GlusterFS.

   This file is licensed to you under your choice of the GNU Lesser
   General Public License, version 3 or any later version (LGPLv3 or
   later), or the GNU General Public License, version 2 (GPLv2), in all
   cases as published by the Free Software Foundation.
*/
#include <ctype.h>
#ifndef _CONFIG_H
#define _CONFIG_H
#include "config.h"
#endif

#include "glusterfs.h"
#include "xlator.h"
#include "logging.h"

#include "vs.h"

/*
 * This is the vs ``volume-set'' xlator. It creates
 * volume set of existing volumes to allow for auto-tiering
 * NOT FOR PRODUCTION USE ;) (hence no error-checking)
 */

int32_t
vs_readv_cbk (call_frame_t *frame,
                 void *cookie,
                 xlator_t *this,
                 int32_t op_ret,
                 int32_t op_errno,
                 struct iovec *vector,
                 int32_t count,
		 struct iatt *stbuf,
                 struct iobref *iobref, dict_t *xdata)
{
	/*rot_13_private_t *priv = (rot_13_private_t *)this->private;

	if (priv->decrypt_read)
		rot13_iovec (vector, count);

	STACK_UNWIND_STRICT (readv, frame, op_ret, op_errno, vector, count,
                             stbuf, iobref, xdata);
	*/
	return 0;
}

int32_t
vs_readv (call_frame_t *frame,
             xlator_t *this,
             fd_t *fd,
             size_t size,
             off_t offset, uint32_t flags, dict_t *xdata)
{
	/*
	STACK_WIND (frame,
		    rot13_readv_cbk,
		    FIRST_CHILD (this),
		    FIRST_CHILD (this)->fops->readv,
		    fd, size, offset, flags, xdata);
	*/
	return 0;
}


int32_t
init (xlator_t *this)
{
	data_t *data = NULL;
	vs_private_t *priv = NULL;

/* mine */
	int            child_count = 0;

    if (!this->children) {
            gf_log (this->name, GF_LOG_ERROR,
                    "vs translator needs more than one "
                    "subvolume defined.");
            return -1;
    }


    child_count = xlator_subvolume_count (this);
    if (child_count > 3) {
    	gf_log ("vs", GF_LOG_ERROR,
    			"FATAL: vs should have no more than 3 sub-volumes");
    	return -1;
    }

	if (!this->parents) {
		gf_log (this->name, GF_LOG_WARNING,
			"dangling volume. check volfile ");
	}


/* end mind */
/*
	if (!this->children || this->children->next) {
		gf_log ("rot13", GF_LOG_ERROR,
			"FATAL: rot13 should have exactly one child");
		return -1;
	}


	priv = GF_CALLOC (sizeof (rot_13_private_t), 1, 0);
        if (!priv)
                return -1;

	priv->decrypt_read = 1;
	priv->encrypt_write = 1;

	data = dict_get (this->options, "encrypt-write");
	if (data) {
		if (gf_string2boolean (data->data, &priv->encrypt_write) == -1) {
			gf_log (this->name, GF_LOG_ERROR,
				"encrypt-write takes only boolean options");
			return -1;
		}
	}

	data = dict_get (this->options, "decrypt-read");
	if (data) {
		if (gf_string2boolean (data->data, &priv->decrypt_read) == -1) {
			gf_log (this->name, GF_LOG_ERROR,
				"decrypt-read takes only boolean options");
			return -1;
		}
	}
*/
	this->private = priv;
	gf_log ("vs", GF_LOG_DEBUG, "vs xlator loaded");
	return 0;
}

void
fini (xlator_t *this)
{
	/*rot_13_private_t *priv = this->private;

        if (!priv)
                return;
        this->private = NULL;
	GF_FREE (priv);
*/
	return;
}

struct xlator_cbks cbks;

struct xlator_fops fops = {
  /*      .lookup      = vs_lookup,
        .mknod       = vs_mknod,
        .create      = vs_create,

        .open        = vs_open,
        .statfs      = vs_statfs,
        .opendir     = vs_opendir,
        .readdir     = vs_readdir,
        .readdirp    = vs_readdirp,
        .fsyncdir    = vs_fsyncdir,
        .symlink     = vs_symlink,
        .unlink      = vs_unlink,
        .link        = vs_link,
        .mkdir       = vs_mkdir,
        .rmdir       = vs_rmdir,
        .rename      = vs_rename,
        .entrylk     = vs_entrylk,
        .fentrylk    = vs_fentrylk,
 */

        /* Inode read operations */
/*        .stat        = vs_stat,
        .fstat       = vs_fstat,
        .access      = vs_access,
        .readlink    = vs_readlink,
        .getxattr    = vs_getxattr,
        .fgetxattr    = vs_fgetxattr,
        .readv       = vs_readv,
        .flush       = vs_flush,
        .fsync       = vs_fsync,
        .inodelk     = vs_inodelk,
        .finodelk    = vs_finodelk,
        .lk          = vs_lk,
*/

        /* Inode write operations */
/*        .fremovexattr = vs_fremovexattr,
        .removexattr = vs_removexattr,
        .setxattr    = vs_setxattr,
        .fsetxattr   = vs_fsetxattr,
        .truncate    = vs_truncate,
        .ftruncate   = vs_ftruncate,
        .writev      = vs_writev,
        .xattrop     = vs_xattrop,
        .fxattrop    = vs_fxattrop,
        .setattr     = vs_setattr,
        .fsetattr    = vs_fsetattr,
*/
};

struct volume_options options[] = {
	{ .key  = {"policy"},
	          .value = {"lru", "content", "off"},
	          .type = GF_OPTION_TYPE_STR,
	          .default_value = "off",
	          .description = "This option sets the auto-tier policy type "
	          "lru - least recently used "
	          "content - file type based "
	 }
};
