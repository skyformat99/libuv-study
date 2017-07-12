/** Copyright luoxiangyong. E-mail: solo_lxy@126.com
 * 
 * ѧϰlibnv�Ĳ��Գ���ʹ��nodejs������е�libuvԴ��������ԡ�nodejs����ȡ֮
 * ����:https://github.com/nodejs/node ,��ʹ�õ���nodejs-8.x��
 *
 * ���̹���ʹ��CMake(http://www.cmake.org)��
 *
 * libuv�Ľ̳̲ο���http://luohaha.github.io/Chinese-uvbook
 */

// ������׼���ļ�
#include <stdio.h>

// �������������ļ�
#include <uv.h>

// ��������Ŀ���ļ�
// ..

uv_loop_t *loop;
uv_tty_t tty;


int wmain(int argc, wchar_t *wargv[]) {
    printf("libuv auxi tools test...\n");
    
	loop = uv_default_loop();
	uv_tty_init(loop, &tty, 1, 0);
	uv_tty_set_mode(&tty, UV_TTY_MODE_NORMAL);

	if (uv_guess_handle(1) == UV_TTY) {
		uv_write_t req;
		uv_buf_t buf;
		buf.base = "\033[41;37m";
		buf.len = strlen(buf.base);
		uv_write(&req, (uv_stream_t*)&tty, &buf, 1, NULL);
	}

	uv_write_t req;
	uv_buf_t buf;
	buf.base = "Hello TTY\n";
	buf.len = strlen(buf.base);
	uv_write(&req, (uv_stream_t*)&tty, &buf, 1, NULL);
	uv_tty_reset_mode();
	
	return uv_run(loop, UV_RUN_DEFAULT);
}
