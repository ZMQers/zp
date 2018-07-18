/*  =========================================================================
    zp_proto - class description

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of the ZeroMQ Pipes Project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef ZP_PROTO_H_INCLUDED
#define ZP_PROTO_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/zp_proto.api" to make changes.
//  @interface
//  This is a stable class, and may not change except for emergencies. It
//  is provided in stable builds.
#define ZP_PROTO_CONNECTION_OPEN 1          //
#define ZP_PROTO_CONNECTION_CLOSE 2         //
#define ZP_PROTO_PING 3                     //
#define ZP_PROTO_PONG 4                     //
#define ZP_PROTO_OK 5                       //
#define ZP_PROTO_ERROR 6                    //

//  Create a new empty zp_proto
ZP_EXPORT zp_proto_t *
    zp_proto_new (void);

//  Create a new zp_proto from zpl/zconfig_t *
ZP_EXPORT zp_proto_t *
    zp_proto_new_zpl (zconfig_t *config);

//  Destroy a zp_proto instance
ZP_EXPORT void
    zp_proto_destroy (zp_proto_t **self_p);

//  Create a deep copy of a zp_proto instance
//  Caller owns return value and must destroy it when done.
ZP_EXPORT zp_proto_t *
    zp_proto_dup (zp_proto_t *self);

//  Receive a zp_proto from the socket. Returns 0 if OK, -1 if
//  there was an error. Blocks if there is no message waiting.
ZP_EXPORT int
    zp_proto_recv (zp_proto_t *self, zsock_t *input);

//  Send the zp_proto to the output socket, does not destroy it
ZP_EXPORT int
    zp_proto_send (zp_proto_t *self, zsock_t *output);

//  Print contents of message to stdout
ZP_EXPORT void
    zp_proto_print (zp_proto_t *self);

//  Export class as zconfig_t*. Caller is responsibe for destroying the instance
//  Caller owns return value and must destroy it when done.
ZP_EXPORT zconfig_t *
    zp_proto_zpl (zp_proto_t *self, zconfig_t *parent);

//  Get the message routing id, as a frame
ZP_EXPORT zframe_t *
    zp_proto_routing_id (zp_proto_t *self);

//  Set the message routing id from a frame
ZP_EXPORT void
    zp_proto_set_routing_id (zp_proto_t *self, zframe_t *routing_id);

//  Get the zp_proto message id
ZP_EXPORT int
    zp_proto_id (zp_proto_t *self);

//  Set the zp_proto message id
ZP_EXPORT void
    zp_proto_set_id (zp_proto_t *self, int id);

//  Get the zp_proto message id as printable text
ZP_EXPORT const char *
    zp_proto_command (zp_proto_t *self);

//  Get the uuid field
ZP_EXPORT zuuid_t *
    zp_proto_uuid (zp_proto_t *self);

//  Get the uuid field and transfer ownership to caller
ZP_EXPORT zuuid_t *
    zp_proto_get_uuid (zp_proto_t *self);

//  Set the uuid field
ZP_EXPORT void
    zp_proto_set_uuid (zp_proto_t *self, zuuid_t *uuid_p);

//  Self test of this class.
ZP_EXPORT void
    zp_proto_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
