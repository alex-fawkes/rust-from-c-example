#![crate_type = "staticlib"]
#![feature(lang_items)]
#![no_std]

#[no_mangle]
pub extern fn add(lhs: u32, rhs: u32) -> u32 {
    lhs + rhs
}

#[no_mangle]
pub extern fn fib(n: u32) -> u32 {
    if n == 0 { return 0 }
    if n == 1 { return 1 }
    fib(n - 1) + fib(n - 2)
}

fn crash() -> ! {
    let null = 0 as *const i32;
    unsafe { *null };
    loop {}
}

#[lang = "eh_personality"] fn eh_personality() -> ! { crash() }
#[lang = "eh_unwind_resume"] fn eh_unwind_resume() -> ! { crash() }
#[lang = "panic_fmt"] fn panic_fmt() -> ! { crash() }