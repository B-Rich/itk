    { "glClearIndex", "<(GLfloat) c>", TclGL_glClearIndexCmd } ,
    { "glClearColor", "<(GLclampf) red> <(GLclampf) green> <(GLclampf) blue> <(GLclampf) alpha>", TclGL_glClearColorCmd } ,
    { "glClear", "<(GLbitfield) mask> !not yet!", TclGL_glClearCmd } ,
    { "glIndexMask", "<(GLuint) mask>", TclGL_glIndexMaskCmd } ,
    { "glColorMask", "<(GLboolean) red> <(GLboolean) green> <(GLboolean) blue> <(GLboolean) alpha>", TclGL_glColorMaskCmd } ,
    { "glAlphaFunc", "<(GLenum) func> <(GLclampf) ref> !not yet!", TclGL_glAlphaFuncCmd } ,
    { "glBlendFunc", "<(GLenum) sfactor> <(GLenum) dfactor> !not yet!", TclGL_glBlendFuncCmd } ,
    { "glLogicOp", "<(GLenum) opcode> !not yet!", TclGL_glLogicOpCmd } ,
    { "glCullFace", "<(GLenum) mode> !not yet!", TclGL_glCullFaceCmd } ,
    { "glFrontFace", "<(GLenum) mode> !not yet!", TclGL_glFrontFaceCmd } ,
    { "glPointSize", "<(GLfloat) size>", TclGL_glPointSizeCmd } ,
    { "glLineWidth", "<(GLfloat) width>", TclGL_glLineWidthCmd } ,
    { "glLineStipple", "<(GLint) factor> <(GLushort) pattern>", TclGL_glLineStippleCmd } ,
    { "glPolygonMode", "<(GLenum) face> <(GLenum) mode> !not yet!", TclGL_glPolygonModeCmd } ,
    { "glPolygonOffset", "<(GLfloat) factor> <(GLfloat) units>", TclGL_glPolygonOffsetCmd } ,
    { "glPolygonStipple", "<(GLubyte) mask> !not yet!", TclGL_glPolygonStippleCmd } ,
    { "glGetPolygonStipple", "<(GLubyte) mask> !not yet!", TclGL_glGetPolygonStippleCmd } ,
    { "glEdgeFlag", "<(GLboolean) flag>", TclGL_glEdgeFlagCmd } ,
    { "glEdgeFlagv", "<(GLboolean) flag> !not yet!", TclGL_glEdgeFlagvCmd } ,
    { "glScissor", "<(GLint) x> <(GLint) y> <(GLsizei) width> <(GLsizei) height>", TclGL_glScissorCmd } ,
    { "glClipPlane", "<(GLenum) plane> <(GLdouble) equation> !not yet!", TclGL_glClipPlaneCmd } ,
    { "glGetClipPlane", "<(GLenum) plane> <(GLdouble) equation> !not yet!", TclGL_glGetClipPlaneCmd } ,
    { "glDrawBuffer", "<(GLenum) mode> !not yet!", TclGL_glDrawBufferCmd } ,
    { "glReadBuffer", "<(GLenum) mode> !not yet!", TclGL_glReadBufferCmd } ,
    { "glEnable", "<(GLenum) cap> !not yet!", TclGL_glEnableCmd } ,
    { "glDisable", "<(GLenum) cap> !not yet!", TclGL_glDisableCmd } ,
    { "glIsEnabled", "<(GLenum) cap> !not yet!", TclGL_glIsEnabledCmd } ,
    { "glEnableClientState", "<(GLenum) cap> !not yet!", TclGL_glEnableClientStateCmd } ,
    { "glDisableClientState", "<(GLenum) cap> !not yet!", TclGL_glDisableClientStateCmd } ,
    { "glGetBooleanv", "<(GLenum) pname> <(GLboolean) params> !not yet!", TclGL_glGetBooleanvCmd } ,
    { "glGetDoublev", "<(GLenum) pname> <(GLdouble) params> !not yet!", TclGL_glGetDoublevCmd } ,
    { "glGetFloatv", "<(GLenum) pname> <(GLfloat) params> !not yet!", TclGL_glGetFloatvCmd } ,
    { "glGetIntegerv", "<(GLenum) pname> <(GLint) params> !not yet!", TclGL_glGetIntegervCmd } ,
    { "glPushAttrib", "<(GLbitfield) mask> !not yet!", TclGL_glPushAttribCmd } ,
    { "glPopAttrib", "", TclGL_glPopAttribCmd } ,
    { "glPushClientAttrib", "<(GLbitfield) mask> !not yet!", TclGL_glPushClientAttribCmd } ,
    { "glPopClientAttrib", "", TclGL_glPopClientAttribCmd } ,
    { "glRenderMode", "<(GLenum) mode> !not yet!", TclGL_glRenderModeCmd } ,
    { "glGetError", "", TclGL_glGetErrorCmd } ,
    { "glFinish", "", TclGL_glFinishCmd } ,
    { "glFlush", "", TclGL_glFlushCmd } ,
    { "glHint", "<(GLenum) target> <(GLenum) mode> !not yet!", TclGL_glHintCmd } ,
    { "glClearDepth", "<(GLclampd) depth>", TclGL_glClearDepthCmd } ,
    { "glDepthFunc", "<(GLenum) func> !not yet!", TclGL_glDepthFuncCmd } ,
    { "glDepthMask", "<(GLboolean) flag>", TclGL_glDepthMaskCmd } ,
    { "glDepthRange", "<(GLclampd) near_val> <(GLclampd) far_val>", TclGL_glDepthRangeCmd } ,
    { "glClearAccum", "<(GLfloat) red> <(GLfloat) green> <(GLfloat) blue> <(GLfloat) alpha>", TclGL_glClearAccumCmd } ,
    { "glAccum", "<(GLenum) op> <(GLfloat) value> !not yet!", TclGL_glAccumCmd } ,
    { "glMatrixMode", "<(GLenum) mode> !not yet!", TclGL_glMatrixModeCmd } ,
    { "glPushMatrix", "", TclGL_glPushMatrixCmd } ,
    { "glPopMatrix", "", TclGL_glPopMatrixCmd } ,
    { "glLoadIdentity", "", TclGL_glLoadIdentityCmd } ,
    { "glLoadMatrixd", "<(GLdouble) m> !not yet!", TclGL_glLoadMatrixdCmd } ,
    { "glLoadMatrixf", "<(GLfloat) m> !not yet!", TclGL_glLoadMatrixfCmd } ,
    { "glMultMatrixd", "<(GLdouble) m> !not yet!", TclGL_glMultMatrixdCmd } ,
    { "glMultMatrixf", "<(GLfloat) m> !not yet!", TclGL_glMultMatrixfCmd } ,
    { "glScaled", "<(GLdouble) x> <(GLdouble) y> <(GLdouble) z>", TclGL_glScaledCmd } ,
    { "glScalef", "<(GLfloat) x> <(GLfloat) y> <(GLfloat) z>", TclGL_glScalefCmd } ,
    { "glTranslated", "<(GLdouble) x> <(GLdouble) y> <(GLdouble) z>", TclGL_glTranslatedCmd } ,
    { "glTranslatef", "<(GLfloat) x> <(GLfloat) y> <(GLfloat) z>", TclGL_glTranslatefCmd } ,
    { "glIsList", "<(GLuint) list>", TclGL_glIsListCmd } ,
    { "glDeleteLists", "<(GLuint) list> <(GLsizei) range>", TclGL_glDeleteListsCmd } ,
    { "glGenLists", "<(GLsizei) range>", TclGL_glGenListsCmd } ,
    { "glNewList", "<(GLuint) list> <(GLenum) mode> !not yet!", TclGL_glNewListCmd } ,
    { "glEndList", "", TclGL_glEndListCmd } ,
    { "glCallList", "<(GLuint) list>", TclGL_glCallListCmd } ,
    { "glListBase", "<(GLuint) base>", TclGL_glListBaseCmd } ,
    { "glBegin", "<(GLenum) mode> !not yet!", TclGL_glBeginCmd } ,
    { "glEnd", "", TclGL_glEndCmd } ,
    { "glVertex2d", "<(GLdouble) x> <(GLdouble) y>", TclGL_glVertex2dCmd } ,
    { "glVertex2f", "<(GLfloat) x> <(GLfloat) y>", TclGL_glVertex2fCmd } ,
    { "glVertex2i", "<(GLint) x> <(GLint) y>", TclGL_glVertex2iCmd } ,
    { "glVertex2s", "<(GLshort) x> <(GLshort) y>", TclGL_glVertex2sCmd } ,
    { "glVertex3d", "<(GLdouble) x> <(GLdouble) y> <(GLdouble) z>", TclGL_glVertex3dCmd } ,
    { "glVertex3f", "<(GLfloat) x> <(GLfloat) y> <(GLfloat) z>", TclGL_glVertex3fCmd } ,
    { "glVertex3i", "<(GLint) x> <(GLint) y> <(GLint) z>", TclGL_glVertex3iCmd } ,
    { "glVertex3s", "<(GLshort) x> <(GLshort) y> <(GLshort) z>", TclGL_glVertex3sCmd } ,
    { "glVertex4d", "<(GLdouble) x> <(GLdouble) y> <(GLdouble) z> <(GLdouble) w>", TclGL_glVertex4dCmd } ,
    { "glVertex4f", "<(GLfloat) x> <(GLfloat) y> <(GLfloat) z> <(GLfloat) w>", TclGL_glVertex4fCmd } ,
    { "glVertex4i", "<(GLint) x> <(GLint) y> <(GLint) z> <(GLint) w>", TclGL_glVertex4iCmd } ,
    { "glVertex4s", "<(GLshort) x> <(GLshort) y> <(GLshort) z> <(GLshort) w>", TclGL_glVertex4sCmd } ,
    { "glVertex2dv", "<(GLdouble) v> !not yet!", TclGL_glVertex2dvCmd } ,
    { "glVertex2fv", "<(GLfloat) v> !not yet!", TclGL_glVertex2fvCmd } ,
    { "glVertex2iv", "<(GLint) v> !not yet!", TclGL_glVertex2ivCmd } ,
    { "glVertex2sv", "<(GLshort) v> !not yet!", TclGL_glVertex2svCmd } ,
    { "glVertex3dv", "<(GLdouble) v> !not yet!", TclGL_glVertex3dvCmd } ,
    { "glVertex3fv", "<(GLfloat) v> !not yet!", TclGL_glVertex3fvCmd } ,
    { "glVertex3iv", "<(GLint) v> !not yet!", TclGL_glVertex3ivCmd } ,
    { "glVertex3sv", "<(GLshort) v> !not yet!", TclGL_glVertex3svCmd } ,
    { "glVertex4dv", "<(GLdouble) v> !not yet!", TclGL_glVertex4dvCmd } ,
    { "glVertex4fv", "<(GLfloat) v> !not yet!", TclGL_glVertex4fvCmd } ,
    { "glVertex4iv", "<(GLint) v> !not yet!", TclGL_glVertex4ivCmd } ,
    { "glVertex4sv", "<(GLshort) v> !not yet!", TclGL_glVertex4svCmd } ,
    { "glNormal3b", "<(GLbyte) nx> <(GLbyte) ny> <(GLbyte) nz>", TclGL_glNormal3bCmd } ,
    { "glNormal3d", "<(GLdouble) nx> <(GLdouble) ny> <(GLdouble) nz>", TclGL_glNormal3dCmd } ,
    { "glNormal3f", "<(GLfloat) nx> <(GLfloat) ny> <(GLfloat) nz>", TclGL_glNormal3fCmd } ,
    { "glNormal3i", "<(GLint) nx> <(GLint) ny> <(GLint) nz>", TclGL_glNormal3iCmd } ,
    { "glNormal3s", "<(GLshort) nx> <(GLshort) ny> <(GLshort) nz>", TclGL_glNormal3sCmd } ,
    { "glNormal3bv", "<(GLbyte) v> !not yet!", TclGL_glNormal3bvCmd } ,
    { "glNormal3dv", "<(GLdouble) v> !not yet!", TclGL_glNormal3dvCmd } ,
    { "glNormal3fv", "<(GLfloat) v> !not yet!", TclGL_glNormal3fvCmd } ,
    { "glNormal3iv", "<(GLint) v> !not yet!", TclGL_glNormal3ivCmd } ,
    { "glNormal3sv", "<(GLshort) v> !not yet!", TclGL_glNormal3svCmd } ,
    { "glIndexd", "<(GLdouble) c>", TclGL_glIndexdCmd } ,
    { "glIndexf", "<(GLfloat) c>", TclGL_glIndexfCmd } ,
    { "glIndexi", "<(GLint) c>", TclGL_glIndexiCmd } ,
    { "glIndexs", "<(GLshort) c>", TclGL_glIndexsCmd } ,
    { "glIndexub", "<(GLubyte) c>", TclGL_glIndexubCmd } ,
    { "glIndexdv", "<(GLdouble) c> !not yet!", TclGL_glIndexdvCmd } ,
    { "glIndexfv", "<(GLfloat) c> !not yet!", TclGL_glIndexfvCmd } ,
    { "glIndexiv", "<(GLint) c> !not yet!", TclGL_glIndexivCmd } ,
    { "glIndexsv", "<(GLshort) c> !not yet!", TclGL_glIndexsvCmd } ,
    { "glIndexubv", "<(GLubyte) c> !not yet!", TclGL_glIndexubvCmd } ,
    { "glColor3b", "<(GLbyte) red> <(GLbyte) green> <(GLbyte) blue>", TclGL_glColor3bCmd } ,
    { "glColor3d", "<(GLdouble) red> <(GLdouble) green> <(GLdouble) blue>", TclGL_glColor3dCmd } ,
    { "glColor3f", "<(GLfloat) red> <(GLfloat) green> <(GLfloat) blue>", TclGL_glColor3fCmd } ,
    { "glColor3i", "<(GLint) red> <(GLint) green> <(GLint) blue>", TclGL_glColor3iCmd } ,
    { "glColor3s", "<(GLshort) red> <(GLshort) green> <(GLshort) blue>", TclGL_glColor3sCmd } ,
    { "glColor3ub", "<(GLubyte) red> <(GLubyte) green> <(GLubyte) blue>", TclGL_glColor3ubCmd } ,
    { "glColor3ui", "<(GLuint) red> <(GLuint) green> <(GLuint) blue>", TclGL_glColor3uiCmd } ,
    { "glColor3us", "<(GLushort) red> <(GLushort) green> <(GLushort) blue>", TclGL_glColor3usCmd } ,
    { "glColor3bv", "<(GLbyte) v> !not yet!", TclGL_glColor3bvCmd } ,
    { "glColor3dv", "<(GLdouble) v> !not yet!", TclGL_glColor3dvCmd } ,
    { "glColor3fv", "<(GLfloat) v> !not yet!", TclGL_glColor3fvCmd } ,
    { "glColor3iv", "<(GLint) v> !not yet!", TclGL_glColor3ivCmd } ,
    { "glColor3sv", "<(GLshort) v> !not yet!", TclGL_glColor3svCmd } ,
    { "glColor3ubv", "<(GLubyte) v> !not yet!", TclGL_glColor3ubvCmd } ,
    { "glColor3uiv", "<(GLuint) v> !not yet!", TclGL_glColor3uivCmd } ,
    { "glColor3usv", "<(GLushort) v> !not yet!", TclGL_glColor3usvCmd } ,
    { "glColor4bv", "<(GLbyte) v> !not yet!", TclGL_glColor4bvCmd } ,
    { "glColor4dv", "<(GLdouble) v> !not yet!", TclGL_glColor4dvCmd } ,
    { "glColor4fv", "<(GLfloat) v> !not yet!", TclGL_glColor4fvCmd } ,
    { "glColor4iv", "<(GLint) v> !not yet!", TclGL_glColor4ivCmd } ,
    { "glColor4sv", "<(GLshort) v> !not yet!", TclGL_glColor4svCmd } ,
    { "glColor4ubv", "<(GLubyte) v> !not yet!", TclGL_glColor4ubvCmd } ,
    { "glColor4uiv", "<(GLuint) v> !not yet!", TclGL_glColor4uivCmd } ,
    { "glColor4usv", "<(GLushort) v> !not yet!", TclGL_glColor4usvCmd } ,
    { "glTexCoord1d", "<(GLdouble) s>", TclGL_glTexCoord1dCmd } ,
    { "glTexCoord1f", "<(GLfloat) s>", TclGL_glTexCoord1fCmd } ,
    { "glTexCoord1i", "<(GLint) s>", TclGL_glTexCoord1iCmd } ,
    { "glTexCoord1s", "<(GLshort) s>", TclGL_glTexCoord1sCmd } ,
    { "glTexCoord2d", "<(GLdouble) s> <(GLdouble) t>", TclGL_glTexCoord2dCmd } ,
    { "glTexCoord2f", "<(GLfloat) s> <(GLfloat) t>", TclGL_glTexCoord2fCmd } ,
    { "glTexCoord2i", "<(GLint) s> <(GLint) t>", TclGL_glTexCoord2iCmd } ,
    { "glTexCoord2s", "<(GLshort) s> <(GLshort) t>", TclGL_glTexCoord2sCmd } ,
    { "glTexCoord3d", "<(GLdouble) s> <(GLdouble) t> <(GLdouble) r>", TclGL_glTexCoord3dCmd } ,
    { "glTexCoord3f", "<(GLfloat) s> <(GLfloat) t> <(GLfloat) r>", TclGL_glTexCoord3fCmd } ,
    { "glTexCoord3i", "<(GLint) s> <(GLint) t> <(GLint) r>", TclGL_glTexCoord3iCmd } ,
    { "glTexCoord3s", "<(GLshort) s> <(GLshort) t> <(GLshort) r>", TclGL_glTexCoord3sCmd } ,
    { "glTexCoord4d", "<(GLdouble) s> <(GLdouble) t> <(GLdouble) r> <(GLdouble) q>", TclGL_glTexCoord4dCmd } ,
    { "glTexCoord4f", "<(GLfloat) s> <(GLfloat) t> <(GLfloat) r> <(GLfloat) q>", TclGL_glTexCoord4fCmd } ,
    { "glTexCoord4i", "<(GLint) s> <(GLint) t> <(GLint) r> <(GLint) q>", TclGL_glTexCoord4iCmd } ,
    { "glTexCoord4s", "<(GLshort) s> <(GLshort) t> <(GLshort) r> <(GLshort) q>", TclGL_glTexCoord4sCmd } ,
    { "glTexCoord1dv", "<(GLdouble) v> !not yet!", TclGL_glTexCoord1dvCmd } ,
    { "glTexCoord1fv", "<(GLfloat) v> !not yet!", TclGL_glTexCoord1fvCmd } ,
    { "glTexCoord1iv", "<(GLint) v> !not yet!", TclGL_glTexCoord1ivCmd } ,
    { "glTexCoord1sv", "<(GLshort) v> !not yet!", TclGL_glTexCoord1svCmd } ,
    { "glTexCoord2dv", "<(GLdouble) v> !not yet!", TclGL_glTexCoord2dvCmd } ,
    { "glTexCoord2fv", "<(GLfloat) v> !not yet!", TclGL_glTexCoord2fvCmd } ,
    { "glTexCoord2iv", "<(GLint) v> !not yet!", TclGL_glTexCoord2ivCmd } ,
    { "glTexCoord2sv", "<(GLshort) v> !not yet!", TclGL_glTexCoord2svCmd } ,
    { "glTexCoord3dv", "<(GLdouble) v> !not yet!", TclGL_glTexCoord3dvCmd } ,
    { "glTexCoord3fv", "<(GLfloat) v> !not yet!", TclGL_glTexCoord3fvCmd } ,
    { "glTexCoord3iv", "<(GLint) v> !not yet!", TclGL_glTexCoord3ivCmd } ,
    { "glTexCoord3sv", "<(GLshort) v> !not yet!", TclGL_glTexCoord3svCmd } ,
    { "glTexCoord4dv", "<(GLdouble) v> !not yet!", TclGL_glTexCoord4dvCmd } ,
    { "glTexCoord4fv", "<(GLfloat) v> !not yet!", TclGL_glTexCoord4fvCmd } ,
    { "glTexCoord4iv", "<(GLint) v> !not yet!", TclGL_glTexCoord4ivCmd } ,
    { "glTexCoord4sv", "<(GLshort) v> !not yet!", TclGL_glTexCoord4svCmd } ,
    { "glRasterPos2d", "<(GLdouble) x> <(GLdouble) y>", TclGL_glRasterPos2dCmd } ,
    { "glRasterPos2f", "<(GLfloat) x> <(GLfloat) y>", TclGL_glRasterPos2fCmd } ,
    { "glRasterPos2i", "<(GLint) x> <(GLint) y>", TclGL_glRasterPos2iCmd } ,
    { "glRasterPos2s", "<(GLshort) x> <(GLshort) y>", TclGL_glRasterPos2sCmd } ,
    { "glRasterPos3d", "<(GLdouble) x> <(GLdouble) y> <(GLdouble) z>", TclGL_glRasterPos3dCmd } ,
    { "glRasterPos3f", "<(GLfloat) x> <(GLfloat) y> <(GLfloat) z>", TclGL_glRasterPos3fCmd } ,
    { "glRasterPos3i", "<(GLint) x> <(GLint) y> <(GLint) z>", TclGL_glRasterPos3iCmd } ,
    { "glRasterPos3s", "<(GLshort) x> <(GLshort) y> <(GLshort) z>", TclGL_glRasterPos3sCmd } ,
    { "glRasterPos4d", "<(GLdouble) x> <(GLdouble) y> <(GLdouble) z> <(GLdouble) w>", TclGL_glRasterPos4dCmd } ,
    { "glRasterPos4f", "<(GLfloat) x> <(GLfloat) y> <(GLfloat) z> <(GLfloat) w>", TclGL_glRasterPos4fCmd } ,
    { "glRasterPos4i", "<(GLint) x> <(GLint) y> <(GLint) z> <(GLint) w>", TclGL_glRasterPos4iCmd } ,
    { "glRasterPos4s", "<(GLshort) x> <(GLshort) y> <(GLshort) z> <(GLshort) w>", TclGL_glRasterPos4sCmd } ,
    { "glRasterPos2dv", "<(GLdouble) v> !not yet!", TclGL_glRasterPos2dvCmd } ,
    { "glRasterPos2fv", "<(GLfloat) v> !not yet!", TclGL_glRasterPos2fvCmd } ,
    { "glRasterPos2iv", "<(GLint) v> !not yet!", TclGL_glRasterPos2ivCmd } ,
    { "glRasterPos2sv", "<(GLshort) v> !not yet!", TclGL_glRasterPos2svCmd } ,
    { "glRasterPos3dv", "<(GLdouble) v> !not yet!", TclGL_glRasterPos3dvCmd } ,
    { "glRasterPos3fv", "<(GLfloat) v> !not yet!", TclGL_glRasterPos3fvCmd } ,
    { "glRasterPos3iv", "<(GLint) v> !not yet!", TclGL_glRasterPos3ivCmd } ,
    { "glRasterPos3sv", "<(GLshort) v> !not yet!", TclGL_glRasterPos3svCmd } ,
    { "glRasterPos4dv", "<(GLdouble) v> !not yet!", TclGL_glRasterPos4dvCmd } ,
    { "glRasterPos4fv", "<(GLfloat) v> !not yet!", TclGL_glRasterPos4fvCmd } ,
    { "glRasterPos4iv", "<(GLint) v> !not yet!", TclGL_glRasterPos4ivCmd } ,
    { "glRasterPos4sv", "<(GLshort) v> !not yet!", TclGL_glRasterPos4svCmd } ,
    { "glRectd", "<(GLdouble) x1> <(GLdouble) y1> <(GLdouble) x2> <(GLdouble) y2>", TclGL_glRectdCmd } ,
    { "glRectf", "<(GLfloat) x1> <(GLfloat) y1> <(GLfloat) x2> <(GLfloat) y2>", TclGL_glRectfCmd } ,
    { "glRecti", "<(GLint) x1> <(GLint) y1> <(GLint) x2> <(GLint) y2>", TclGL_glRectiCmd } ,
    { "glRects", "<(GLshort) x1> <(GLshort) y1> <(GLshort) x2> <(GLshort) y2>", TclGL_glRectsCmd } ,
    { "glRectdv", "<(GLdouble) v1> <(GLdouble) v2> !not yet!", TclGL_glRectdvCmd } ,
    { "glRectfv", "<(GLfloat) v1> <(GLfloat) v2> !not yet!", TclGL_glRectfvCmd } ,
    { "glRectiv", "<(GLint) v1> <(GLint) v2> !not yet!", TclGL_glRectivCmd } ,
    { "glRectsv", "<(GLshort) v1> <(GLshort) v2> !not yet!", TclGL_glRectsvCmd } ,
    { "glEdgeFlagPointer", "<(GLsizei) stride> <(GLvoid) ptr> !not yet!", TclGL_glEdgeFlagPointerCmd } ,
    { "glGetPointerv", "<(GLenum) pname> <(GLvoid) *params> !not yet!", TclGL_glGetPointervCmd } ,
    { "glArrayElement", "<(GLint) i>", TclGL_glArrayElementCmd } ,
    { "glDrawArrays", "<(GLenum) mode> <(GLint) first> <(GLsizei) count> !not yet!", TclGL_glDrawArraysCmd } ,
    { "glShadeModel", "<(GLenum) mode> !not yet!", TclGL_glShadeModelCmd } ,
    { "glLightf", "<(GLenum) light> <(GLenum) pname> <(GLfloat) param> !not yet!", TclGL_glLightfCmd } ,
    { "glLighti", "<(GLenum) light> <(GLenum) pname> <(GLint) param> !not yet!", TclGL_glLightiCmd } ,
    { "glLightModelf", "<(GLenum) pname> <(GLfloat) param> !not yet!", TclGL_glLightModelfCmd } ,
    { "glLightModeli", "<(GLenum) pname> <(GLint) param> !not yet!", TclGL_glLightModeliCmd } ,
    { "glLightModelfv", "<(GLenum) pname> <(GLfloat) params> !not yet!", TclGL_glLightModelfvCmd } ,
    { "glLightModeliv", "<(GLenum) pname> <(GLint) params> !not yet!", TclGL_glLightModelivCmd } ,
    { "glMaterialf", "<(GLenum) face> <(GLenum) pname> <(GLfloat) param> !not yet!", TclGL_glMaterialfCmd } ,
    { "glMateriali", "<(GLenum) face> <(GLenum) pname> <(GLint) param> !not yet!", TclGL_glMaterialiCmd } ,
    { "glMaterialfv", "<(GLenum) face> <(GLenum) pname> <(GLfloat) params> !not yet!", TclGL_glMaterialfvCmd } ,
    { "glMaterialiv", "<(GLenum) face> <(GLenum) pname> <(GLint) params> !not yet!", TclGL_glMaterialivCmd } ,
    { "glGetMaterialfv", "<(GLenum) face> <(GLenum) pname> <(GLfloat) params> !not yet!", TclGL_glGetMaterialfvCmd } ,
    { "glGetMaterialiv", "<(GLenum) face> <(GLenum) pname> <(GLint) params> !not yet!", TclGL_glGetMaterialivCmd } ,
    { "glColorMaterial", "<(GLenum) face> <(GLenum) mode> !not yet!", TclGL_glColorMaterialCmd } ,
    { "glPixelZoom", "<(GLfloat) xfactor> <(GLfloat) yfactor>", TclGL_glPixelZoomCmd } ,
    { "glPixelStoref", "<(GLenum) pname> <(GLfloat) param> !not yet!", TclGL_glPixelStorefCmd } ,
    { "glPixelStorei", "<(GLenum) pname> <(GLint) param> !not yet!", TclGL_glPixelStoreiCmd } ,
    { "glPixelTransferf", "<(GLenum) pname> <(GLfloat) param> !not yet!", TclGL_glPixelTransferfCmd } ,
    { "glPixelTransferi", "<(GLenum) pname> <(GLint) param> !not yet!", TclGL_glPixelTransferiCmd } ,
    { "glGetPixelMapfv", "<(GLenum) map> <(GLfloat) values> !not yet!", TclGL_glGetPixelMapfvCmd } ,
    { "glGetPixelMapuiv", "<(GLenum) map> <(GLuint) values> !not yet!", TclGL_glGetPixelMapuivCmd } ,
    { "glGetPixelMapusv", "<(GLenum) map> <(GLushort) values> !not yet!", TclGL_glGetPixelMapusvCmd } ,
    { "glStencilFunc", "<(GLenum) func> <(GLint) ref> <(GLuint) mask> !not yet!", TclGL_glStencilFuncCmd } ,
    { "glStencilMask", "<(GLuint) mask>", TclGL_glStencilMaskCmd } ,
    { "glStencilOp", "<(GLenum) fail> <(GLenum) zfail> <(GLenum) zpass> !not yet!", TclGL_glStencilOpCmd } ,
    { "glClearStencil", "<(GLint) s>", TclGL_glClearStencilCmd } ,
    { "glTexGend", "<(GLenum) coord> <(GLenum) pname> <(GLdouble) param> !not yet!", TclGL_glTexGendCmd } ,
    { "glTexGenf", "<(GLenum) coord> <(GLenum) pname> <(GLfloat) param> !not yet!", TclGL_glTexGenfCmd } ,
    { "glTexGeni", "<(GLenum) coord> <(GLenum) pname> <(GLint) param> !not yet!", TclGL_glTexGeniCmd } ,
    { "glTexGendv", "<(GLenum) coord> <(GLenum) pname> <(GLdouble) params> !not yet!", TclGL_glTexGendvCmd } ,
    { "glTexGenfv", "<(GLenum) coord> <(GLenum) pname> <(GLfloat) params> !not yet!", TclGL_glTexGenfvCmd } ,
    { "glTexGeniv", "<(GLenum) coord> <(GLenum) pname> <(GLint) params> !not yet!", TclGL_glTexGenivCmd } ,
    { "glGetTexGendv", "<(GLenum) coord> <(GLenum) pname> <(GLdouble) params> !not yet!", TclGL_glGetTexGendvCmd } ,
    { "glGetTexGenfv", "<(GLenum) coord> <(GLenum) pname> <(GLfloat) params> !not yet!", TclGL_glGetTexGenfvCmd } ,
    { "glGetTexGeniv", "<(GLenum) coord> <(GLenum) pname> <(GLint) params> !not yet!", TclGL_glGetTexGenivCmd } ,
    { "glTexEnvf", "<(GLenum) target> <(GLenum) pname> <(GLfloat) param> !not yet!", TclGL_glTexEnvfCmd } ,
    { "glTexEnvi", "<(GLenum) target> <(GLenum) pname> <(GLint) param> !not yet!", TclGL_glTexEnviCmd } ,
    { "glTexEnvfv", "<(GLenum) target> <(GLenum) pname> <(GLfloat) params> !not yet!", TclGL_glTexEnvfvCmd } ,
    { "glTexEnviv", "<(GLenum) target> <(GLenum) pname> <(GLint) params> !not yet!", TclGL_glTexEnvivCmd } ,
    { "glGetTexEnvfv", "<(GLenum) target> <(GLenum) pname> <(GLfloat) params> !not yet!", TclGL_glGetTexEnvfvCmd } ,
    { "glGetTexEnviv", "<(GLenum) target> <(GLenum) pname> <(GLint) params> !not yet!", TclGL_glGetTexEnvivCmd } ,
    { "glTexParameterf", "<(GLenum) target> <(GLenum) pname> <(GLfloat) param> !not yet!", TclGL_glTexParameterfCmd } ,
    { "glTexParameteri", "<(GLenum) target> <(GLenum) pname> <(GLint) param> !not yet!", TclGL_glTexParameteriCmd } ,
    { "glGenTextures", "<(GLsizei) n> <(GLuint) textures> !not yet!", TclGL_glGenTexturesCmd } ,
    { "glDeleteTextures", "<(GLsizei) n> <(GLuint) textures> !not yet!", TclGL_glDeleteTexturesCmd } ,
    { "glBindTexture", "<(GLenum) target> <(GLuint) texture> !not yet!", TclGL_glBindTextureCmd } ,
    { "glIsTexture", "<(GLuint) texture>", TclGL_glIsTextureCmd } ,
    { "glGetMapdv", "<(GLenum) target> <(GLenum) query> <(GLdouble) v> !not yet!", TclGL_glGetMapdvCmd } ,
    { "glGetMapfv", "<(GLenum) target> <(GLenum) query> <(GLfloat) v> !not yet!", TclGL_glGetMapfvCmd } ,
    { "glGetMapiv", "<(GLenum) target> <(GLenum) query> <(GLint) v> !not yet!", TclGL_glGetMapivCmd } ,
    { "glEvalCoord1d", "<(GLdouble) u>", TclGL_glEvalCoord1dCmd } ,
    { "glEvalCoord1f", "<(GLfloat) u>", TclGL_glEvalCoord1fCmd } ,
    { "glEvalCoord1dv", "<(GLdouble) u> !not yet!", TclGL_glEvalCoord1dvCmd } ,
    { "glEvalCoord1fv", "<(GLfloat) u> !not yet!", TclGL_glEvalCoord1fvCmd } ,
    { "glEvalCoord2d", "<(GLdouble) u> <(GLdouble) v>", TclGL_glEvalCoord2dCmd } ,
    { "glEvalCoord2f", "<(GLfloat) u> <(GLfloat) v>", TclGL_glEvalCoord2fCmd } ,
    { "glEvalCoord2dv", "<(GLdouble) u> !not yet!", TclGL_glEvalCoord2dvCmd } ,
    { "glEvalCoord2fv", "<(GLfloat) u> !not yet!", TclGL_glEvalCoord2fvCmd } ,
    { "glMapGrid1d", "<(GLint) un> <(GLdouble) u1> <(GLdouble) u2>", TclGL_glMapGrid1dCmd } ,
    { "glMapGrid1f", "<(GLint) un> <(GLfloat) u1> <(GLfloat) u2>", TclGL_glMapGrid1fCmd } ,
    { "glEvalPoint1", "<(GLint) i>", TclGL_glEvalPoint1Cmd } ,
    { "glEvalPoint2", "<(GLint) i> <(GLint) j>", TclGL_glEvalPoint2Cmd } ,
    { "glEvalMesh1", "<(GLenum) mode> <(GLint) i1> <(GLint) i2> !not yet!", TclGL_glEvalMesh1Cmd } ,
    { "glEvalMesh2", "<(GLenum) mode> <(GLint) i1> <(GLint) i2> <(GLint) j1> <(GLint) j2> !not yet!", TclGL_glEvalMesh2Cmd } ,
    { "glFogf", "<(GLenum) pname> <(GLfloat) param> !not yet!", TclGL_glFogfCmd } ,
    { "glFogi", "<(GLenum) pname> <(GLint) param> !not yet!", TclGL_glFogiCmd } ,
    { "glFogfv", "<(GLenum) pname> <(GLfloat) params> !not yet!", TclGL_glFogfvCmd } ,
    { "glFogiv", "<(GLenum) pname> <(GLint) params> !not yet!", TclGL_glFogivCmd } ,
    { "glFeedbackBuffer", "<(GLsizei) size> <(GLenum) type> <(GLfloat) buffer> !not yet!", TclGL_glFeedbackBufferCmd } ,
    { "glPassThrough", "<(GLfloat) token>", TclGL_glPassThroughCmd } ,
    { "glSelectBuffer", "<(GLsizei) size> <(GLuint) buffer> !not yet!", TclGL_glSelectBufferCmd } ,
    { "glInitNames", "", TclGL_glInitNamesCmd } ,
    { "glLoadName", "<(GLuint) name>", TclGL_glLoadNameCmd } ,
    { "glPushName", "<(GLuint) name>", TclGL_glPushNameCmd } ,
    { "glPopName", "", TclGL_glPopNameCmd } ,
    { "glBlendEquation", "<(GLenum) mode> !not yet!", TclGL_glBlendEquationCmd } ,
    { "glResetHistogram", "<(GLenum) target> !not yet!", TclGL_glResetHistogramCmd } ,
    { "glResetMinmax", "<(GLenum) target> !not yet!", TclGL_glResetMinmaxCmd } ,
    { "glActiveTexture", "<(GLenum) texture> !not yet!", TclGL_glActiveTextureCmd } ,
    { "glClientActiveTexture", "<(GLenum) texture> !not yet!", TclGL_glClientActiveTextureCmd } ,
    { "glCompressedTexImage1D", "<(GLenum) target> <(GLint) level> <(GLenum) internalformat> <(GLsizei) width> <(GLint) border> <(GLsizei) imageSize> <(GLvoid) data> !not yet!", TclGL_glCompressedTexImage1DCmd } ,
    { "glCompressedTexImage2D", "<(GLenum) target> <(GLint) level> <(GLenum) internalformat> <(GLsizei) width> <(GLsizei) height> <(GLint) border> <(GLsizei) imageSize> <(GLvoid) data> !not yet!", TclGL_glCompressedTexImage2DCmd } ,
    { "glCompressedTexImage3D", "<(GLenum) target> <(GLint) level> <(GLenum) internalformat> <(GLsizei) width> <(GLsizei) height> <(GLsizei) depth> <(GLint) border> <(GLsizei) imageSize> <(GLvoid) data> !not yet!", TclGL_glCompressedTexImage3DCmd } ,
    { "glCompressedTexSubImage1D", "<(GLenum) target> <(GLint) level> <(GLint) xoffset> <(GLsizei) width> <(GLenum) format> <(GLsizei) imageSize> <(GLvoid) data> !not yet!", TclGL_glCompressedTexSubImage1DCmd } ,
    { "glCompressedTexSubImage2D", "<(GLenum) target> <(GLint) level> <(GLint) xoffset> <(GLint) yoffset> <(GLsizei) width> <(GLsizei) height> <(GLenum) format> <(GLsizei) imageSize> <(GLvoid) data> !not yet!", TclGL_glCompressedTexSubImage2DCmd } ,
    { "glCompressedTexSubImage3D", "<(GLenum) target> <(GLint) level> <(GLint) xoffset> <(GLint) yoffset> <(GLint) zoffset> <(GLsizei) width> <(GLsizei) height> <(GLsizei) depth> <(GLenum) format> <(GLsizei) imageSize> <(GLvoid) data> !not yet!", TclGL_glCompressedTexSubImage3DCmd } ,
    { "glGetCompressedTexImage", "<(GLenum) target> <(GLint) lod> <(GLvoid) img> !not yet!", TclGL_glGetCompressedTexImageCmd } ,
    { "glMultiTexCoord1d", "<(GLenum) target> <(GLdouble) s> !not yet!", TclGL_glMultiTexCoord1dCmd } ,
    { "glMultiTexCoord1dv", "<(GLenum) target> <(GLdouble) v> !not yet!", TclGL_glMultiTexCoord1dvCmd } ,
    { "glMultiTexCoord1f", "<(GLenum) target> <(GLfloat) s> !not yet!", TclGL_glMultiTexCoord1fCmd } ,
    { "glMultiTexCoord1fv", "<(GLenum) target> <(GLfloat) v> !not yet!", TclGL_glMultiTexCoord1fvCmd } ,
    { "glMultiTexCoord1i", "<(GLenum) target> <(GLint) s> !not yet!", TclGL_glMultiTexCoord1iCmd } ,
    { "glMultiTexCoord1iv", "<(GLenum) target> <(GLint) v> !not yet!", TclGL_glMultiTexCoord1ivCmd } ,
    { "glMultiTexCoord1s", "<(GLenum) target> <(GLshort) s> !not yet!", TclGL_glMultiTexCoord1sCmd } ,
    { "glMultiTexCoord1sv", "<(GLenum) target> <(GLshort) v> !not yet!", TclGL_glMultiTexCoord1svCmd } ,
    { "glMultiTexCoord2d", "<(GLenum) target> <(GLdouble) s> <(GLdouble) t> !not yet!", TclGL_glMultiTexCoord2dCmd } ,
    { "glMultiTexCoord2dv", "<(GLenum) target> <(GLdouble) v> !not yet!", TclGL_glMultiTexCoord2dvCmd } ,
    { "glMultiTexCoord2f", "<(GLenum) target> <(GLfloat) s> <(GLfloat) t> !not yet!", TclGL_glMultiTexCoord2fCmd } ,
    { "glMultiTexCoord2fv", "<(GLenum) target> <(GLfloat) v> !not yet!", TclGL_glMultiTexCoord2fvCmd } ,
    { "glMultiTexCoord2i", "<(GLenum) target> <(GLint) s> <(GLint) t> !not yet!", TclGL_glMultiTexCoord2iCmd } ,
    { "glMultiTexCoord2iv", "<(GLenum) target> <(GLint) v> !not yet!", TclGL_glMultiTexCoord2ivCmd } ,
    { "glMultiTexCoord2s", "<(GLenum) target> <(GLshort) s> <(GLshort) t> !not yet!", TclGL_glMultiTexCoord2sCmd } ,
    { "glMultiTexCoord2sv", "<(GLenum) target> <(GLshort) v> !not yet!", TclGL_glMultiTexCoord2svCmd } ,
    { "glMultiTexCoord3d", "<(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r> !not yet!", TclGL_glMultiTexCoord3dCmd } ,
    { "glMultiTexCoord3dv", "<(GLenum) target> <(GLdouble) v> !not yet!", TclGL_glMultiTexCoord3dvCmd } ,
    { "glMultiTexCoord3f", "<(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r> !not yet!", TclGL_glMultiTexCoord3fCmd } ,
    { "glMultiTexCoord3fv", "<(GLenum) target> <(GLfloat) v> !not yet!", TclGL_glMultiTexCoord3fvCmd } ,
    { "glMultiTexCoord3i", "<(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r> !not yet!", TclGL_glMultiTexCoord3iCmd } ,
    { "glMultiTexCoord3iv", "<(GLenum) target> <(GLint) v> !not yet!", TclGL_glMultiTexCoord3ivCmd } ,
    { "glMultiTexCoord3s", "<(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r> !not yet!", TclGL_glMultiTexCoord3sCmd } ,
    { "glMultiTexCoord3sv", "<(GLenum) target> <(GLshort) v> !not yet!", TclGL_glMultiTexCoord3svCmd } ,
    { "glMultiTexCoord4d", "<(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r> <(GLdouble) q> !not yet!", TclGL_glMultiTexCoord4dCmd } ,
    { "glMultiTexCoord4dv", "<(GLenum) target> <(GLdouble) v> !not yet!", TclGL_glMultiTexCoord4dvCmd } ,
    { "glMultiTexCoord4f", "<(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r> <(GLfloat) q> !not yet!", TclGL_glMultiTexCoord4fCmd } ,
    { "glMultiTexCoord4fv", "<(GLenum) target> <(GLfloat) v> !not yet!", TclGL_glMultiTexCoord4fvCmd } ,
    { "glMultiTexCoord4i", "<(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r> <(GLint) q> !not yet!", TclGL_glMultiTexCoord4iCmd } ,
    { "glMultiTexCoord4iv", "<(GLenum) target> <(GLint) v> !not yet!", TclGL_glMultiTexCoord4ivCmd } ,
    { "glMultiTexCoord4s", "<(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r> <(GLshort) q> !not yet!", TclGL_glMultiTexCoord4sCmd } ,
    { "glMultiTexCoord4sv", "<(GLenum) target> <(GLshort) v> !not yet!", TclGL_glMultiTexCoord4svCmd } ,
    { "glLoadTransposeMatrixd", "<(GLdouble) m[16]> !not yet!", TclGL_glLoadTransposeMatrixdCmd } ,
    { "glLoadTransposeMatrixf", "<(GLfloat) m[16]> !not yet!", TclGL_glLoadTransposeMatrixfCmd } ,
    { "glMultTransposeMatrixd", "<(GLdouble) m[16]> !not yet!", TclGL_glMultTransposeMatrixdCmd } ,
    { "glMultTransposeMatrixf", "<(GLfloat) m[16]> !not yet!", TclGL_glMultTransposeMatrixfCmd } ,
    { "glSampleCoverage", "<(GLclampf) value> <(GLboolean) invert>", TclGL_glSampleCoverageCmd } ,
    { "glActiveTextureARB", "<(GLenum) texture> !not yet!", TclGL_glActiveTextureARBCmd } ,
    { "glClientActiveTextureARB", "<(GLenum) texture> !not yet!", TclGL_glClientActiveTextureARBCmd } ,
    { "glMultiTexCoord1dARB", "<(GLenum) target> <(GLdouble) s> !not yet!", TclGL_glMultiTexCoord1dARBCmd } ,
    { "glMultiTexCoord1dvARB", "<(GLenum) target> <(GLdouble) v> !not yet!", TclGL_glMultiTexCoord1dvARBCmd } ,
    { "glMultiTexCoord1fARB", "<(GLenum) target> <(GLfloat) s> !not yet!", TclGL_glMultiTexCoord1fARBCmd } ,
    { "glMultiTexCoord1fvARB", "<(GLenum) target> <(GLfloat) v> !not yet!", TclGL_glMultiTexCoord1fvARBCmd } ,
    { "glMultiTexCoord1iARB", "<(GLenum) target> <(GLint) s> !not yet!", TclGL_glMultiTexCoord1iARBCmd } ,
    { "glMultiTexCoord1ivARB", "<(GLenum) target> <(GLint) v> !not yet!", TclGL_glMultiTexCoord1ivARBCmd } ,
    { "glMultiTexCoord1sARB", "<(GLenum) target> <(GLshort) s> !not yet!", TclGL_glMultiTexCoord1sARBCmd } ,
    { "glMultiTexCoord1svARB", "<(GLenum) target> <(GLshort) v> !not yet!", TclGL_glMultiTexCoord1svARBCmd } ,
    { "glMultiTexCoord2dARB", "<(GLenum) target> <(GLdouble) s> <(GLdouble) t> !not yet!", TclGL_glMultiTexCoord2dARBCmd } ,
    { "glMultiTexCoord2dvARB", "<(GLenum) target> <(GLdouble) v> !not yet!", TclGL_glMultiTexCoord2dvARBCmd } ,
    { "glMultiTexCoord2fARB", "<(GLenum) target> <(GLfloat) s> <(GLfloat) t> !not yet!", TclGL_glMultiTexCoord2fARBCmd } ,
    { "glMultiTexCoord2fvARB", "<(GLenum) target> <(GLfloat) v> !not yet!", TclGL_glMultiTexCoord2fvARBCmd } ,
    { "glMultiTexCoord2iARB", "<(GLenum) target> <(GLint) s> <(GLint) t> !not yet!", TclGL_glMultiTexCoord2iARBCmd } ,
    { "glMultiTexCoord2ivARB", "<(GLenum) target> <(GLint) v> !not yet!", TclGL_glMultiTexCoord2ivARBCmd } ,
    { "glMultiTexCoord2sARB", "<(GLenum) target> <(GLshort) s> <(GLshort) t> !not yet!", TclGL_glMultiTexCoord2sARBCmd } ,
    { "glMultiTexCoord2svARB", "<(GLenum) target> <(GLshort) v> !not yet!", TclGL_glMultiTexCoord2svARBCmd } ,
    { "glMultiTexCoord3dARB", "<(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r> !not yet!", TclGL_glMultiTexCoord3dARBCmd } ,
    { "glMultiTexCoord3dvARB", "<(GLenum) target> <(GLdouble) v> !not yet!", TclGL_glMultiTexCoord3dvARBCmd } ,
    { "glMultiTexCoord3fARB", "<(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r> !not yet!", TclGL_glMultiTexCoord3fARBCmd } ,
    { "glMultiTexCoord3fvARB", "<(GLenum) target> <(GLfloat) v> !not yet!", TclGL_glMultiTexCoord3fvARBCmd } ,
    { "glMultiTexCoord3iARB", "<(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r> !not yet!", TclGL_glMultiTexCoord3iARBCmd } ,
    { "glMultiTexCoord3ivARB", "<(GLenum) target> <(GLint) v> !not yet!", TclGL_glMultiTexCoord3ivARBCmd } ,
    { "glMultiTexCoord3sARB", "<(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r> !not yet!", TclGL_glMultiTexCoord3sARBCmd } ,
    { "glMultiTexCoord3svARB", "<(GLenum) target> <(GLshort) v> !not yet!", TclGL_glMultiTexCoord3svARBCmd } ,
    { "glMultiTexCoord4dARB", "<(GLenum) target> <(GLdouble) s> <(GLdouble) t> <(GLdouble) r> <(GLdouble) q> !not yet!", TclGL_glMultiTexCoord4dARBCmd } ,
    { "glMultiTexCoord4dvARB", "<(GLenum) target> <(GLdouble) v> !not yet!", TclGL_glMultiTexCoord4dvARBCmd } ,
    { "glMultiTexCoord4fARB", "<(GLenum) target> <(GLfloat) s> <(GLfloat) t> <(GLfloat) r> <(GLfloat) q> !not yet!", TclGL_glMultiTexCoord4fARBCmd } ,
    { "glMultiTexCoord4fvARB", "<(GLenum) target> <(GLfloat) v> !not yet!", TclGL_glMultiTexCoord4fvARBCmd } ,
    { "glMultiTexCoord4iARB", "<(GLenum) target> <(GLint) s> <(GLint) t> <(GLint) r> <(GLint) q> !not yet!", TclGL_glMultiTexCoord4iARBCmd } ,
    { "glMultiTexCoord4ivARB", "<(GLenum) target> <(GLint) v> !not yet!", TclGL_glMultiTexCoord4ivARBCmd } ,
    { "glMultiTexCoord4sARB", "<(GLenum) target> <(GLshort) s> <(GLshort) t> <(GLshort) r> <(GLshort) q> !not yet!", TclGL_glMultiTexCoord4sARBCmd } ,
    { "glMultiTexCoord4svARB", "<(GLenum) target> <(GLshort) v> !not yet!", TclGL_glMultiTexCoord4svARBCmd } ,
    { "glBlendEquationSeparateATI", "<(GLenum) modeRGB> <(GLenum) modeA> !not yet!", TclGL_glBlendEquationSeparateATICmd } ,