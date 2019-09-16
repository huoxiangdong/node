/* ***** BEGIN LICENSE BLOCK *****
 * Distributed under the BSD license:
 *
 * Copyright (c) 2015, xuewen.chu
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of xuewen.chu nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL xuewen.chu BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef __ngui__node__
#define __ngui__node__

#ifdef _WIN32
# define NODE_EXPORT __declspec(dllexport)
#else
# define NODE_EXPORT __attribute__((visibility("default")))
#endif

namespace ngui {
	namespace js {
		class Worker;
	}
}

namespace node {

	using ngui::js::Worker;

	class Environment;

	class NODE_EXPORT NguiEnvironment {
	 public:
		NguiEnvironment(Environment* env);
		~NguiEnvironment();
		inline Worker* worker() { return m_worker; }
		inline Environment* env() { return m_env; }
		static void run_loop();
		static bool is_exited();
		static char* encoding_to_utf8(const uint16_t* src, int length, int* out_len);
		static uint16_t* decoding_utf8_to_uint16(const char* src, int length, int* out_len);
	 private:
		Worker* m_worker;
		Environment* m_env;
	};

	class NODE_EXPORT NodeAPI {
	 public:
		virtual int Start(int argc, char *argv[]) = 0;
		virtual void* binding_node_module(const char* name) = 0;
	};

	NODE_EXPORT extern NguiEnvironment* ngui_env;
	NODE_EXPORT extern NodeAPI* ngui_node_api;
}

#endif
