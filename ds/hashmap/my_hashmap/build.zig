const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // 1. Define the unit test step

    const unit_tests = b.addTest(.{
        .root_module = b.createModule(.{
            // root source file
            .root_source_file = b.path("test/test_map.zig"),
            .target = target,
            .optimize = optimize,
            .link_libc = true,
        }),
    });

    // 2. Tell zig to compile our c file and include the header path

    unit_tests.root_module.addCSourceFile(.{
        .file = b.path("src/hashmap.c"),
        // Pass compiler flags down to Clang under the hood
        .flags = &[_][]const u8{ "-Wall", "-Wextra", "-std=c99" },
    });

    // Call addIncludePath on the root module
    unit_tests.root_module.addIncludePath(b.path("src"));

    const run_unit_tests = b.addRunArtifact(unit_tests);

    const test_step = b.step("test", "Run hashmap library tests");
    test_step.dependOn(&run_unit_tests.step);
}
