#ifndef SC__SESSION_H__
#define SC__SESSION_H__
/**
 * \file
 * Session C runtime library (libsc)
 * session handling module.
 *
 * This includes initialisation and finalisation routines
 * for Session C programming.
 */

#include "sc/types.h"

/**
 * \brief Initialise a sesssion.
 *
 * @param[in,out] argc     Command line argument count
 * @param[in,out] argv     Command line argument list
 * @param[out]    s        Pointer to session varible to create
 * @param[in]     scribble Endpoint Scribble file path for this session
 *                         (Must be constant string)
 */
void session_init(int *argc, char ***argv, session **s, const char *scribble);


/**
 * \brief Create a role group.
 *
 * @param[in,out] s     Session the new role group to create in.
 * @param[in]     name  Name of the new role group.
 * @param[in]     nrole Number of roles to group together.
 * @param[in]     ...   The handles to existing roles to group together. 
 *
 * \returns Handle to the newly created role group.
 */
role *session_group(session *s, const char *name, int nrole, ...);


/**
 * \brief Terminate a session.
 *
 * @param[in] s Session to terminate
 */
void session_end(session *s);


/**
 * \brief Dump content of an established session.
 *  
 * @param[in] s Session to dump
 */
void session_dump(const session *s);


#endif // SC__SESSION_H__
