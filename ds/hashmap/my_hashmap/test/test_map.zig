const std = @import("std");
const expect = std.testing.expect;
const expectEqual = std.testing.expectEqual;

// Import our C header file directly

const c = @cImport({
    @cInclude("hashmap.h");
});

test "Hash Map - Basic Initialization and Put/Get" {

    // map initialization should succeed by returning a non null pointer
    const map: ?*c.map_t = c.map_create(100);
    try expect(map != null);

    // given an empty map, map_put should succeed by returning status 0, and size should increment
    const key: ?*anyopaque = @ptrCast(@constCast("key"));
    const value: ?*anyopaque = @ptrCast(@constCast("value"));

    if (map) |valid_map| {
        try expectEqual(100, valid_map.cap);
        try expectEqual(0, valid_map.size);

        const status = c.map_put(valid_map, key, value);
        try expectEqual(0, status);
        try expectEqual(1, valid_map.size);
    }

    defer c.map_destroy(map);
}
