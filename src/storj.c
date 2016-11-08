#include "storj.h"

struct json_object* fetch_json(char *proto, char *host, int port, char *method, char *path)
{
    ne_session *sess = ne_session_create(proto, host, port);
    ne_ssl_trust_default_ca(sess);

    ne_request *req = ne_request_create(sess, method, path);

    json_object *obj;

    if (ne_begin_request(req) != NE_OK) {
        printf("Request failed: %s\n", ne_get_error(sess));
        return obj;
    }

    char *body = malloc(NE_BUFSIZ * 4);
    char *buf = malloc(NE_BUFSIZ);
    ssize_t bytes = 0;
    ssize_t total = 0;

    while ((bytes = ne_read_response_block(req, buf, NE_BUFSIZ)) > 0) {
        if (total + bytes > sizeof(body)) {
            body = (char *) realloc(body, total + bytes + 1);
        }

        memcpy(&body[total], buf, bytes);
        total += bytes;
    }

    ne_request_destroy(req);

    obj = json_tokener_parse(body);

    return obj;
}

struct json_object* storj_bridge_get_info()
{
    json_object *obj = fetch_json("https", "api.storj.io", 443, "GET", "/");

    return obj;
}

struct json_object* storj_bridge_get_buckets()
{

}

struct json_object* storj_bridge_create_bucket()
{

}

struct json_object* storj_bridge_delete_bucket()
{

}

struct json_object* storj_bridge_list_files()
{

}

struct json_object* storj_bridge_create_bucket_token()
{

}

struct json_object* storj_bridge_delete_file()
{

}

struct json_object* storj_bridge_create_frame()
{

}

struct json_object* storj_bridge_get_frames()
{

}

struct json_object* storj_bridge_get_file_info()
{

}

struct json_object* storj_bridge_get_frame()
{

}

struct json_object* storj_bridge_delete_frame()
{

}

struct json_object* storj_bridge_add_shard_to_frame()
{

}

struct json_object* storj_bridge_replicate_file()
{

}

struct json_object* storj_bridge_store_file()
{

}

struct json_object* storj_bridge_get_file_pointers()
{

}

struct json_object* storj_bridge_resolve_file()
{

}
