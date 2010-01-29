" Vim syntax file
" This file should be installed in folder: ~/.vim/syntax (create it if it does
" not exists)
" Language:	Templates for Goil
" Maintainer:	Mikael Briday
" URL: http://trampoline.rts-software.org
" Last Change:	2010/01/29
" initial version: goil rev 1041 (goil 2.0b38)

" For version 5.x: Clear all syntax items
" For version 6.x: Quit when a syntax file was already loaded
if version < 600
 syntax clear
elseif exists("b:current_syntax")
 finish
endif

" templates are case-sensitive.
syn case match

" We don't need to look backwards to highlight correctly;
" this speeds things up greatly.
syn sync minlines=1 maxlines=1
syn region goilTemplatePart contains=templateKeyword,goilIdentifier,goilString,goilNumber,goilComment,goilDelimiter matchgroup=gtpStart start="%"  skip="\\%" matchgroup=gtpEnd end="%"

syn keyword templateKeyword contained after before between block do else elsif end for foreach no if in mod not prefixedby template then yes while 

" Identifiers
syn match goilIdentifier contained "[a-zA-Z_][a-zA-Z0-9_]*"

" Strings and numbers
syn region  goilString contained start=+"+ end=+"+
" integers and floats, with any number of '_'.
syn match   goilNumber contained "\<[0-9_]\*\.[0-9_]+\>"
syn match   goilNumber contained "\<[0-9_]\+\>"

" Comments.
syn region goilComment contained oneline contains=goilTodo start="#"  end="$"
" Todo (only highlighted in comments)
syn keyword goilTodo contained	TODO FIXME XXX

" Delimiters
syn match   goilDelimiter contained "[.=*|,+-:>;>?=!\[\]/&{}^~<]%"

" Define the default highlighting.
" For version 5.7 and earlier: only when not done already
" For version 5.8 and later: only when an item doesn't have highlighting yet
if version >= 508 || !exists("did_goil_templates_syn_inits")
  if version < 508
    let did_goil_templates_syn_inits = 1
    command -nargs=+ HiLink hi link <args>
  else
    command -nargs=+ HiLink hi def link <args>
  endif

  " The default methods for highlighting. Can be overridden later.
  HiLink goilComment		Comment
  HiLink templateKeyword	Keyword
  HiLink gtpEnd                 Todo
  HiLink gtpStart               Todo
  HiLink goilTodo		Todo
  HiLink goilIdentifier		Identifier
  HiLink goilString		String
  HiLink goilNumber		Number
  HiLink goilDelimiter		Delimiter
  delcommand HiLink
endif

let b:current_syntax = "goilTemplates"

" vim: ts=8
