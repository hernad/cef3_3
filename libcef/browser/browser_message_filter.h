// Copyright (c) 2012 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CEF_LIBCEF_BROWSER_BROWSER_MESSAGE_FILTER_H_
#define CEF_LIBCEF_BROWSER_BROWSER_MESSAGE_FILTER_H_

#include <string>
#include "ipc/ipc_channel_proxy.h"

namespace content {
class RenderProcessHost;
}

struct CefProcessHostMsg_GetNewBrowserInfo_Params;
struct CefProcessHostMsg_GetNewRenderThreadInfo_Params;

// This class sends and receives control messages on the browser process.
class CefBrowserMessageFilter : public IPC::ChannelProxy::MessageFilter {
 public:
  explicit CefBrowserMessageFilter(content::RenderProcessHost* host);
  virtual ~CefBrowserMessageFilter();

  // IPC::ChannelProxy::MessageFilter implementation.
  virtual void OnFilterAdded(IPC::Channel* channel) OVERRIDE;
  virtual void OnFilterRemoved() OVERRIDE;
  virtual bool OnMessageReceived(const IPC::Message& message) OVERRIDE;

  bool Send(IPC::Message* message);

 private:
  // Message handlers.
  void OnGetNewRenderThreadInfo(
      CefProcessHostMsg_GetNewRenderThreadInfo_Params* params);
  void OnGetNewBrowserInfo(int routing_id,
                           CefProcessHostMsg_GetNewBrowserInfo_Params* params);

  content::RenderProcessHost* host_;
  IPC::Channel* channel_;

  DISALLOW_COPY_AND_ASSIGN(CefBrowserMessageFilter);
};


#endif  // CEF_LIBCEF_BROWSER_BROWSER_MESSAGE_FILTER_H_
