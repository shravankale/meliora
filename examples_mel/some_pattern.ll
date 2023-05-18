; ModuleID = 'some_pattern.c'
source_filename = "some_pattern.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@.str.1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local void @array_access_pattern(i32 noundef %rows, i32 noundef %cols, i32* noundef %arr) #0 !dbg !8 {
entry:
  %rows.addr = alloca i32, align 4
  %cols.addr = alloca i32, align 4
  %arr.addr = alloca i32*, align 8
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %i9 = alloca i32, align 4
  %j13 = alloca i32, align 4
  store i32 %rows, i32* %rows.addr, align 4
  call void @llvm.dbg.declare(metadata i32* %rows.addr, metadata !17, metadata !DIExpression()), !dbg !18
  store i32 %cols, i32* %cols.addr, align 4
  call void @llvm.dbg.declare(metadata i32* %cols.addr, metadata !19, metadata !DIExpression()), !dbg !20
  store i32* %arr, i32** %arr.addr, align 8
  call void @llvm.dbg.declare(metadata i32** %arr.addr, metadata !21, metadata !DIExpression()), !dbg !22
  %0 = load i32, i32* %rows.addr, align 4, !dbg !23
  %1 = zext i32 %0 to i64
  %2 = load i32, i32* %cols.addr, align 4, !dbg !24
  %3 = zext i32 %2 to i64
  call void @llvm.dbg.declare(metadata i32* %i, metadata !25, metadata !DIExpression()), !dbg !27
  store i32 0, i32* %i, align 4, !dbg !27
  br label %for.cond, !dbg !28

for.cond:                                         ; preds = %for.inc6, %entry
  %4 = load i32, i32* %i, align 4, !dbg !29
  %5 = load i32, i32* %rows.addr, align 4, !dbg !31
  %cmp = icmp slt i32 %4, %5, !dbg !32
  br i1 %cmp, label %for.body, label %for.end8, !dbg !33

for.body:                                         ; preds = %for.cond
  call void @llvm.dbg.declare(metadata i32* %j, metadata !34, metadata !DIExpression()), !dbg !37
  store i32 0, i32* %j, align 4, !dbg !37
  br label %for.cond1, !dbg !38

for.cond1:                                        ; preds = %for.inc, %for.body
  %6 = load i32, i32* %j, align 4, !dbg !39
  %7 = load i32, i32* %cols.addr, align 4, !dbg !41
  %cmp2 = icmp slt i32 %6, %7, !dbg !42
  br i1 %cmp2, label %for.body3, label %for.end, !dbg !43

for.body3:                                        ; preds = %for.cond1
  %8 = load i32*, i32** %arr.addr, align 8, !dbg !44
  %9 = load i32, i32* %i, align 4, !dbg !46
  %idxprom = sext i32 %9 to i64, !dbg !44
  %10 = mul nsw i64 %idxprom, %3, !dbg !44
  %arrayidx = getelementptr inbounds i32, i32* %8, i64 %10, !dbg !44
  %11 = load i32, i32* %j, align 4, !dbg !47
  %idxprom4 = sext i32 %11 to i64, !dbg !44
  %arrayidx5 = getelementptr inbounds i32, i32* %arrayidx, i64 %idxprom4, !dbg !44
  store i32 0, i32* %arrayidx5, align 4, !dbg !48
  br label %for.inc, !dbg !49

for.inc:                                          ; preds = %for.body3
  %12 = load i32, i32* %j, align 4, !dbg !50
  %inc = add nsw i32 %12, 1, !dbg !50
  store i32 %inc, i32* %j, align 4, !dbg !50
  br label %for.cond1, !dbg !51, !llvm.loop !52

for.end:                                          ; preds = %for.cond1
  br label %for.inc6, !dbg !55

for.inc6:                                         ; preds = %for.end
  %13 = load i32, i32* %i, align 4, !dbg !56
  %inc7 = add nsw i32 %13, 1, !dbg !56
  store i32 %inc7, i32* %i, align 4, !dbg !56
  br label %for.cond, !dbg !57, !llvm.loop !58

for.end8:                                         ; preds = %for.cond
  call void @llvm.dbg.declare(metadata i32* %i9, metadata !60, metadata !DIExpression()), !dbg !62
  store i32 0, i32* %i9, align 4, !dbg !62
  br label %for.cond10, !dbg !63

for.cond10:                                       ; preds = %for.inc25, %for.end8
  %14 = load i32, i32* %i9, align 4, !dbg !64
  %15 = load i32, i32* %rows.addr, align 4, !dbg !66
  %cmp11 = icmp slt i32 %14, %15, !dbg !67
  br i1 %cmp11, label %for.body12, label %for.end27, !dbg !68

for.body12:                                       ; preds = %for.cond10
  call void @llvm.dbg.declare(metadata i32* %j13, metadata !69, metadata !DIExpression()), !dbg !72
  store i32 0, i32* %j13, align 4, !dbg !72
  br label %for.cond14, !dbg !73

for.cond14:                                       ; preds = %for.inc22, %for.body12
  %16 = load i32, i32* %j13, align 4, !dbg !74
  %17 = load i32, i32* %cols.addr, align 4, !dbg !76
  %cmp15 = icmp slt i32 %16, %17, !dbg !77
  br i1 %cmp15, label %for.body16, label %for.end24, !dbg !78

for.body16:                                       ; preds = %for.cond14
  %18 = load i32, i32* %i9, align 4, !dbg !79
  %19 = load i32, i32* %j13, align 4, !dbg !82
  %add = add nsw i32 %18, %19, !dbg !83
  %rem = srem i32 %add, 2, !dbg !84
  %cmp17 = icmp eq i32 %rem, 0, !dbg !85
  br i1 %cmp17, label %if.then, label %if.end, !dbg !86

if.then:                                          ; preds = %for.body16
  %20 = load i32*, i32** %arr.addr, align 8, !dbg !87
  %21 = load i32, i32* %i9, align 4, !dbg !89
  %idxprom18 = sext i32 %21 to i64, !dbg !87
  %22 = mul nsw i64 %idxprom18, %3, !dbg !87
  %arrayidx19 = getelementptr inbounds i32, i32* %20, i64 %22, !dbg !87
  %23 = load i32, i32* %j13, align 4, !dbg !90
  %idxprom20 = sext i32 %23 to i64, !dbg !87
  %arrayidx21 = getelementptr inbounds i32, i32* %arrayidx19, i64 %idxprom20, !dbg !87
  store i32 1, i32* %arrayidx21, align 4, !dbg !91
  br label %if.end, !dbg !92

if.end:                                           ; preds = %if.then, %for.body16
  br label %for.inc22, !dbg !93

for.inc22:                                        ; preds = %if.end
  %24 = load i32, i32* %j13, align 4, !dbg !94
  %inc23 = add nsw i32 %24, 1, !dbg !94
  store i32 %inc23, i32* %j13, align 4, !dbg !94
  br label %for.cond14, !dbg !95, !llvm.loop !96

for.end24:                                        ; preds = %for.cond14
  br label %for.inc25, !dbg !98

for.inc25:                                        ; preds = %for.end24
  %25 = load i32, i32* %i9, align 4, !dbg !99
  %inc26 = add nsw i32 %25, 1, !dbg !99
  store i32 %inc26, i32* %i9, align 4, !dbg !99
  br label %for.cond10, !dbg !100, !llvm.loop !101

for.end27:                                        ; preds = %for.cond10
  ret void, !dbg !103
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !104 {
entry:
  %retval = alloca i32, align 4
  %arr = alloca [5 x [5 x i32]], align 16
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @llvm.dbg.declare(metadata [5 x [5 x i32]]* %arr, metadata !107, metadata !DIExpression()), !dbg !111
  %arraydecay = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %arr, i64 0, i64 0, !dbg !112
  %0 = bitcast [5 x i32]* %arraydecay to i32*, !dbg !112
  call void @array_access_pattern(i32 noundef 5, i32 noundef 5, i32* noundef %0), !dbg !113
  call void @llvm.dbg.declare(metadata i32* %i, metadata !114, metadata !DIExpression()), !dbg !116
  store i32 0, i32* %i, align 4, !dbg !116
  br label %for.cond, !dbg !117

for.cond:                                         ; preds = %for.inc7, %entry
  %1 = load i32, i32* %i, align 4, !dbg !118
  %cmp = icmp slt i32 %1, 5, !dbg !120
  br i1 %cmp, label %for.body, label %for.end9, !dbg !121

for.body:                                         ; preds = %for.cond
  call void @llvm.dbg.declare(metadata i32* %j, metadata !122, metadata !DIExpression()), !dbg !125
  store i32 0, i32* %j, align 4, !dbg !125
  br label %for.cond1, !dbg !126

for.cond1:                                        ; preds = %for.inc, %for.body
  %2 = load i32, i32* %j, align 4, !dbg !127
  %cmp2 = icmp slt i32 %2, 5, !dbg !129
  br i1 %cmp2, label %for.body3, label %for.end, !dbg !130

for.body3:                                        ; preds = %for.cond1
  %3 = load i32, i32* %i, align 4, !dbg !131
  %idxprom = sext i32 %3 to i64, !dbg !133
  %arrayidx = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %arr, i64 0, i64 %idxprom, !dbg !133
  %4 = load i32, i32* %j, align 4, !dbg !134
  %idxprom4 = sext i32 %4 to i64, !dbg !133
  %arrayidx5 = getelementptr inbounds [5 x i32], [5 x i32]* %arrayidx, i64 0, i64 %idxprom4, !dbg !133
  %5 = load i32, i32* %arrayidx5, align 4, !dbg !133
  %call = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 noundef %5), !dbg !135
  br label %for.inc, !dbg !136

for.inc:                                          ; preds = %for.body3
  %6 = load i32, i32* %j, align 4, !dbg !137
  %inc = add nsw i32 %6, 1, !dbg !137
  store i32 %inc, i32* %j, align 4, !dbg !137
  br label %for.cond1, !dbg !138, !llvm.loop !139

for.end:                                          ; preds = %for.cond1
  %call6 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.1, i64 0, i64 0)), !dbg !141
  br label %for.inc7, !dbg !142

for.inc7:                                         ; preds = %for.end
  %7 = load i32, i32* %i, align 4, !dbg !143
  %inc8 = add nsw i32 %7, 1, !dbg !143
  store i32 %inc8, i32* %i, align 4, !dbg !143
  br label %for.cond, !dbg !144, !llvm.loop !145

for.end9:                                         ; preds = %for.cond
  ret i32 0, !dbg !147
}

declare dso_local i32 @printf(i8* noundef, ...) #2

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "some_pattern.c", directory: "/home/users/shravank/projects/meliora2/Meliora/examples_mel", checksumkind: CSK_MD5, checksum: "8677063f869ac7f13f53186d72a11db6")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"uwtable", i32 1}
!6 = !{i32 7, !"frame-pointer", i32 2}
!7 = !{!"clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)"}
!8 = distinct !DISubprogram(name: "array_access_pattern", scope: !1, file: !1, line: 12, type: !9, scopeLine: 12, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!9 = !DISubroutineType(types: !10)
!10 = !{null, !11, !11, !12}
!11 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!12 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !13, size: 64)
!13 = !DICompositeType(tag: DW_TAG_array_type, baseType: !11, elements: !14)
!14 = !{!15}
!15 = !DISubrange(count: -1)
!16 = !{}
!17 = !DILocalVariable(name: "rows", arg: 1, scope: !8, file: !1, line: 12, type: !11)
!18 = !DILocation(line: 12, column: 31, scope: !8)
!19 = !DILocalVariable(name: "cols", arg: 2, scope: !8, file: !1, line: 12, type: !11)
!20 = !DILocation(line: 12, column: 41, scope: !8)
!21 = !DILocalVariable(name: "arr", arg: 3, scope: !8, file: !1, line: 12, type: !12)
!22 = !DILocation(line: 12, column: 51, scope: !8)
!23 = !DILocation(line: 12, column: 55, scope: !8)
!24 = !DILocation(line: 12, column: 61, scope: !8)
!25 = !DILocalVariable(name: "i", scope: !26, file: !1, line: 14, type: !11)
!26 = distinct !DILexicalBlock(scope: !8, file: !1, line: 14, column: 5)
!27 = !DILocation(line: 14, column: 14, scope: !26)
!28 = !DILocation(line: 14, column: 10, scope: !26)
!29 = !DILocation(line: 14, column: 21, scope: !30)
!30 = distinct !DILexicalBlock(scope: !26, file: !1, line: 14, column: 5)
!31 = !DILocation(line: 14, column: 25, scope: !30)
!32 = !DILocation(line: 14, column: 23, scope: !30)
!33 = !DILocation(line: 14, column: 5, scope: !26)
!34 = !DILocalVariable(name: "j", scope: !35, file: !1, line: 15, type: !11)
!35 = distinct !DILexicalBlock(scope: !36, file: !1, line: 15, column: 9)
!36 = distinct !DILexicalBlock(scope: !30, file: !1, line: 14, column: 36)
!37 = !DILocation(line: 15, column: 18, scope: !35)
!38 = !DILocation(line: 15, column: 14, scope: !35)
!39 = !DILocation(line: 15, column: 25, scope: !40)
!40 = distinct !DILexicalBlock(scope: !35, file: !1, line: 15, column: 9)
!41 = !DILocation(line: 15, column: 29, scope: !40)
!42 = !DILocation(line: 15, column: 27, scope: !40)
!43 = !DILocation(line: 15, column: 9, scope: !35)
!44 = !DILocation(line: 16, column: 13, scope: !45)
!45 = distinct !DILexicalBlock(scope: !40, file: !1, line: 15, column: 40)
!46 = !DILocation(line: 16, column: 17, scope: !45)
!47 = !DILocation(line: 16, column: 20, scope: !45)
!48 = !DILocation(line: 16, column: 23, scope: !45)
!49 = !DILocation(line: 17, column: 9, scope: !45)
!50 = !DILocation(line: 15, column: 36, scope: !40)
!51 = !DILocation(line: 15, column: 9, scope: !40)
!52 = distinct !{!52, !43, !53, !54}
!53 = !DILocation(line: 17, column: 9, scope: !35)
!54 = !{!"llvm.loop.mustprogress"}
!55 = !DILocation(line: 18, column: 5, scope: !36)
!56 = !DILocation(line: 14, column: 32, scope: !30)
!57 = !DILocation(line: 14, column: 5, scope: !30)
!58 = distinct !{!58, !33, !59, !54}
!59 = !DILocation(line: 18, column: 5, scope: !26)
!60 = !DILocalVariable(name: "i", scope: !61, file: !1, line: 21, type: !11)
!61 = distinct !DILexicalBlock(scope: !8, file: !1, line: 21, column: 5)
!62 = !DILocation(line: 21, column: 14, scope: !61)
!63 = !DILocation(line: 21, column: 10, scope: !61)
!64 = !DILocation(line: 21, column: 21, scope: !65)
!65 = distinct !DILexicalBlock(scope: !61, file: !1, line: 21, column: 5)
!66 = !DILocation(line: 21, column: 25, scope: !65)
!67 = !DILocation(line: 21, column: 23, scope: !65)
!68 = !DILocation(line: 21, column: 5, scope: !61)
!69 = !DILocalVariable(name: "j", scope: !70, file: !1, line: 22, type: !11)
!70 = distinct !DILexicalBlock(scope: !71, file: !1, line: 22, column: 9)
!71 = distinct !DILexicalBlock(scope: !65, file: !1, line: 21, column: 36)
!72 = !DILocation(line: 22, column: 18, scope: !70)
!73 = !DILocation(line: 22, column: 14, scope: !70)
!74 = !DILocation(line: 22, column: 25, scope: !75)
!75 = distinct !DILexicalBlock(scope: !70, file: !1, line: 22, column: 9)
!76 = !DILocation(line: 22, column: 29, scope: !75)
!77 = !DILocation(line: 22, column: 27, scope: !75)
!78 = !DILocation(line: 22, column: 9, scope: !70)
!79 = !DILocation(line: 23, column: 18, scope: !80)
!80 = distinct !DILexicalBlock(scope: !81, file: !1, line: 23, column: 17)
!81 = distinct !DILexicalBlock(scope: !75, file: !1, line: 22, column: 40)
!82 = !DILocation(line: 23, column: 22, scope: !80)
!83 = !DILocation(line: 23, column: 20, scope: !80)
!84 = !DILocation(line: 23, column: 25, scope: !80)
!85 = !DILocation(line: 23, column: 29, scope: !80)
!86 = !DILocation(line: 23, column: 17, scope: !81)
!87 = !DILocation(line: 24, column: 17, scope: !88)
!88 = distinct !DILexicalBlock(scope: !80, file: !1, line: 23, column: 35)
!89 = !DILocation(line: 24, column: 21, scope: !88)
!90 = !DILocation(line: 24, column: 24, scope: !88)
!91 = !DILocation(line: 24, column: 27, scope: !88)
!92 = !DILocation(line: 25, column: 13, scope: !88)
!93 = !DILocation(line: 26, column: 9, scope: !81)
!94 = !DILocation(line: 22, column: 36, scope: !75)
!95 = !DILocation(line: 22, column: 9, scope: !75)
!96 = distinct !{!96, !78, !97, !54}
!97 = !DILocation(line: 26, column: 9, scope: !70)
!98 = !DILocation(line: 27, column: 5, scope: !71)
!99 = !DILocation(line: 21, column: 32, scope: !65)
!100 = !DILocation(line: 21, column: 5, scope: !65)
!101 = distinct !{!101, !68, !102, !54}
!102 = !DILocation(line: 27, column: 5, scope: !61)
!103 = !DILocation(line: 28, column: 1, scope: !8)
!104 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 30, type: !105, scopeLine: 30, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!105 = !DISubroutineType(types: !106)
!106 = !{!11}
!107 = !DILocalVariable(name: "arr", scope: !104, file: !1, line: 31, type: !108)
!108 = !DICompositeType(tag: DW_TAG_array_type, baseType: !11, size: 800, elements: !109)
!109 = !{!110, !110}
!110 = !DISubrange(count: 5)
!111 = !DILocation(line: 31, column: 9, scope: !104)
!112 = !DILocation(line: 32, column: 32, scope: !104)
!113 = !DILocation(line: 32, column: 5, scope: !104)
!114 = !DILocalVariable(name: "i", scope: !115, file: !1, line: 35, type: !11)
!115 = distinct !DILexicalBlock(scope: !104, file: !1, line: 35, column: 5)
!116 = !DILocation(line: 35, column: 14, scope: !115)
!117 = !DILocation(line: 35, column: 10, scope: !115)
!118 = !DILocation(line: 35, column: 21, scope: !119)
!119 = distinct !DILexicalBlock(scope: !115, file: !1, line: 35, column: 5)
!120 = !DILocation(line: 35, column: 23, scope: !119)
!121 = !DILocation(line: 35, column: 5, scope: !115)
!122 = !DILocalVariable(name: "j", scope: !123, file: !1, line: 36, type: !11)
!123 = distinct !DILexicalBlock(scope: !124, file: !1, line: 36, column: 9)
!124 = distinct !DILexicalBlock(scope: !119, file: !1, line: 35, column: 33)
!125 = !DILocation(line: 36, column: 18, scope: !123)
!126 = !DILocation(line: 36, column: 14, scope: !123)
!127 = !DILocation(line: 36, column: 25, scope: !128)
!128 = distinct !DILexicalBlock(scope: !123, file: !1, line: 36, column: 9)
!129 = !DILocation(line: 36, column: 27, scope: !128)
!130 = !DILocation(line: 36, column: 9, scope: !123)
!131 = !DILocation(line: 37, column: 31, scope: !132)
!132 = distinct !DILexicalBlock(scope: !128, file: !1, line: 36, column: 37)
!133 = !DILocation(line: 37, column: 27, scope: !132)
!134 = !DILocation(line: 37, column: 34, scope: !132)
!135 = !DILocation(line: 37, column: 13, scope: !132)
!136 = !DILocation(line: 38, column: 9, scope: !132)
!137 = !DILocation(line: 36, column: 33, scope: !128)
!138 = !DILocation(line: 36, column: 9, scope: !128)
!139 = distinct !{!139, !130, !140, !54}
!140 = !DILocation(line: 38, column: 9, scope: !123)
!141 = !DILocation(line: 39, column: 9, scope: !124)
!142 = !DILocation(line: 40, column: 5, scope: !124)
!143 = !DILocation(line: 35, column: 29, scope: !119)
!144 = !DILocation(line: 35, column: 5, scope: !119)
!145 = distinct !{!145, !121, !146, !54}
!146 = !DILocation(line: 40, column: 5, scope: !115)
!147 = !DILocation(line: 42, column: 5, scope: !104)
