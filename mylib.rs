#![crate_type = "staticlib"]
#![feature(lang_items)]
#![no_std]

#[no_mangle]
pub extern fn add(lhs: u32, rhs: u32) -> u32 {
  lhs + rhs
}

fn crash() -> ! {
    let null = 0 as *const i32;
    unsafe { *null };
    loop {}
}

#[lang = "eh_personality"] fn eh_personality() -> ! { crash() }
#[lang = "eh_unwind_resume"] fn eh_unwind_resume() -> ! { crash() }
#[lang = "panic_fmt"] fn panic_fmt() -> ! { crash() }