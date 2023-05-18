; ModuleID = 'random_access.c'
source_filename = "random_access.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@.str.1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local void @array_access_pattern([5 x i32]* noundef %arr) #0 !dbg !8 {
entry:
  %arr.addr = alloca [5 x i32]*, align 8
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %i9 = alloca i32, align 4
  %j14 = alloca i32, align 4
  %rand_row = alloca i32, align 4
  %rand_col = alloca i32, align 4
  store [5 x i32]* %arr, [5 x i32]** %arr.addr, align 8
  call void @llvm.dbg.declare(metadata [5 x i32]** %arr.addr, metadata !17, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.declare(metadata i32* %i, metadata !19, metadata !DIExpression()), !dbg !21
  store i32 0, i32* %i, align 4, !dbg !21
  br label %for.cond, !dbg !22

for.cond:                                         ; preds = %for.inc6, %entry
  %0 = load i32, i32* %i, align 4, !dbg !23
  %cmp = icmp slt i32 %0, 5, !dbg !25
  br i1 %cmp, label %for.body, label %for.end8, !dbg !26

for.body:                                         ; preds = %for.cond
  call void @llvm.dbg.declare(metadata i32* %j, metadata !27, metadata !DIExpression()), !dbg !30
  store i32 0, i32* %j, align 4, !dbg !30
  br label %for.cond1, !dbg !31

for.cond1:                                        ; preds = %for.inc, %for.body
  %1 = load i32, i32* %j, align 4, !dbg !32
  %cmp2 = icmp slt i32 %1, 5, !dbg !34
  br i1 %cmp2, label %for.body3, label %for.end, !dbg !35

for.body3:                                        ; preds = %for.cond1
  %2 = load [5 x i32]*, [5 x i32]** %arr.addr, align 8, !dbg !36
  %3 = load i32, i32* %i, align 4, !dbg !38
  %idxprom = sext i32 %3 to i64, !dbg !36
  %arrayidx = getelementptr inbounds [5 x i32], [5 x i32]* %2, i64 %idxprom, !dbg !36
  %4 = load i32, i32* %j, align 4, !dbg !39
  %idxprom4 = sext i32 %4 to i64, !dbg !36
  %arrayidx5 = getelementptr inbounds [5 x i32], [5 x i32]* %arrayidx, i64 0, i64 %idxprom4, !dbg !36
  store i32 0, i32* %arrayidx5, align 4, !dbg !40
  br label %for.inc, !dbg !41

for.inc:                                          ; preds = %for.body3
  %5 = load i32, i32* %j, align 4, !dbg !42
  %inc = add nsw i32 %5, 1, !dbg !42
  store i32 %inc, i32* %j, align 4, !dbg !42
  br label %for.cond1, !dbg !43, !llvm.loop !44

for.end:                                          ; preds = %for.cond1
  br label %for.inc6, !dbg !47

for.inc6:                                         ; preds = %for.end
  %6 = load i32, i32* %i, align 4, !dbg !48
  %inc7 = add nsw i32 %6, 1, !dbg !48
  store i32 %inc7, i32* %i, align 4, !dbg !48
  br label %for.cond, !dbg !49, !llvm.loop !50

for.end8:                                         ; preds = %for.cond
  %call = call i64 @time(i64* noundef null) #4, !dbg !52
  %conv = trunc i64 %call to i32, !dbg !52
  call void @srand(i32 noundef %conv) #4, !dbg !53
  call void @llvm.dbg.declare(metadata i32* %i9, metadata !54, metadata !DIExpression()), !dbg !56
  store i32 0, i32* %i9, align 4, !dbg !56
  br label %for.cond10, !dbg !57

for.cond10:                                       ; preds = %for.inc29, %for.end8
  %7 = load i32, i32* %i9, align 4, !dbg !58
  %cmp11 = icmp slt i32 %7, 5, !dbg !60
  br i1 %cmp11, label %for.body13, label %for.end31, !dbg !61

for.body13:                                       ; preds = %for.cond10
  call void @llvm.dbg.declare(metadata i32* %j14, metadata !62, metadata !DIExpression()), !dbg !65
  store i32 0, i32* %j14, align 4, !dbg !65
  br label %for.cond15, !dbg !66

for.cond15:                                       ; preds = %for.inc26, %for.body13
  %8 = load i32, i32* %j14, align 4, !dbg !67
  %cmp16 = icmp slt i32 %8, 5, !dbg !69
  br i1 %cmp16, label %for.body18, label %for.end28, !dbg !70

for.body18:                                       ; preds = %for.cond15
  call void @llvm.dbg.declare(metadata i32* %rand_row, metadata !71, metadata !DIExpression()), !dbg !73
  %call19 = call i32 @rand() #4, !dbg !74
  %rem = srem i32 %call19, 5, !dbg !75
  store i32 %rem, i32* %rand_row, align 4, !dbg !73
  call void @llvm.dbg.declare(metadata i32* %rand_col, metadata !76, metadata !DIExpression()), !dbg !77
  %call20 = call i32 @rand() #4, !dbg !78
  %rem21 = srem i32 %call20, 5, !dbg !79
  store i32 %rem21, i32* %rand_col, align 4, !dbg !77
  %9 = load [5 x i32]*, [5 x i32]** %arr.addr, align 8, !dbg !80
  %10 = load i32, i32* %rand_row, align 4, !dbg !81
  %idxprom22 = sext i32 %10 to i64, !dbg !80
  %arrayidx23 = getelementptr inbounds [5 x i32], [5 x i32]* %9, i64 %idxprom22, !dbg !80
  %11 = load i32, i32* %rand_col, align 4, !dbg !82
  %idxprom24 = sext i32 %11 to i64, !dbg !80
  %arrayidx25 = getelementptr inbounds [5 x i32], [5 x i32]* %arrayidx23, i64 0, i64 %idxprom24, !dbg !80
  store i32 1, i32* %arrayidx25, align 4, !dbg !83
  br label %for.inc26, !dbg !84

for.inc26:                                        ; preds = %for.body18
  %12 = load i32, i32* %j14, align 4, !dbg !85
  %inc27 = add nsw i32 %12, 1, !dbg !85
  store i32 %inc27, i32* %j14, align 4, !dbg !85
  br label %for.cond15, !dbg !86, !llvm.loop !87

for.end28:                                        ; preds = %for.cond15
  br label %for.inc29, !dbg !89

for.inc29:                                        ; preds = %for.end28
  %13 = load i32, i32* %i9, align 4, !dbg !90
  %inc30 = add nsw i32 %13, 1, !dbg !90
  store i32 %inc30, i32* %i9, align 4, !dbg !90
  br label %for.cond10, !dbg !91, !llvm.loop !92

for.end31:                                        ; preds = %for.cond10
  ret void, !dbg !94
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: nounwind
declare dso_local void @srand(i32 noundef) #2

; Function Attrs: nounwind
declare dso_local i64 @time(i64* noundef) #2

; Function Attrs: nounwind
declare dso_local i32 @rand() #2

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !95 {
entry:
  %retval = alloca i32, align 4
  %arr = alloca [5 x [5 x i32]], align 16
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @llvm.dbg.declare(metadata [5 x [5 x i32]]* %arr, metadata !98, metadata !DIExpression()), !dbg !101
  %arraydecay = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %arr, i64 0, i64 0, !dbg !102
  call void @array_access_pattern([5 x i32]* noundef %arraydecay), !dbg !103
  call void @llvm.dbg.declare(metadata i32* %i, metadata !104, metadata !DIExpression()), !dbg !106
  store i32 0, i32* %i, align 4, !dbg !106
  br label %for.cond, !dbg !107

for.cond:                                         ; preds = %for.inc7, %entry
  %0 = load i32, i32* %i, align 4, !dbg !108
  %cmp = icmp slt i32 %0, 5, !dbg !110
  br i1 %cmp, label %for.body, label %for.end9, !dbg !111

for.body:                                         ; preds = %for.cond
  call void @llvm.dbg.declare(metadata i32* %j, metadata !112, metadata !DIExpression()), !dbg !115
  store i32 0, i32* %j, align 4, !dbg !115
  br label %for.cond1, !dbg !116

for.cond1:                                        ; preds = %for.inc, %for.body
  %1 = load i32, i32* %j, align 4, !dbg !117
  %cmp2 = icmp slt i32 %1, 5, !dbg !119
  br i1 %cmp2, label %for.body3, label %for.end, !dbg !120

for.body3:                                        ; preds = %for.cond1
  %2 = load i32, i32* %i, align 4, !dbg !121
  %idxprom = sext i32 %2 to i64, !dbg !123
  %arrayidx = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %arr, i64 0, i64 %idxprom, !dbg !123
  %3 = load i32, i32* %j, align 4, !dbg !124
  %idxprom4 = sext i32 %3 to i64, !dbg !123
  %arrayidx5 = getelementptr inbounds [5 x i32], [5 x i32]* %arrayidx, i64 0, i64 %idxprom4, !dbg !123
  %4 = load i32, i32* %arrayidx5, align 4, !dbg !123
  %call = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 noundef %4), !dbg !125
  br label %for.inc, !dbg !126

for.inc:                                          ; preds = %for.body3
  %5 = load i32, i32* %j, align 4, !dbg !127
  %inc = add nsw i32 %5, 1, !dbg !127
  store i32 %inc, i32* %j, align 4, !dbg !127
  br label %for.cond1, !dbg !128, !llvm.loop !129

for.end:                                          ; preds = %for.cond1
  %call6 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.1, i64 0, i64 0)), !dbg !131
  br label %for.inc7, !dbg !132

for.inc7:                                         ; preds = %for.end
  %6 = load i32, i32* %i, align 4, !dbg !133
  %inc8 = add nsw i32 %6, 1, !dbg !133
  store i32 %inc8, i32* %i, align 4, !dbg !133
  br label %for.cond, !dbg !134, !llvm.loop !135

for.end9:                                         ; preds = %for.cond
  ret i32 0, !dbg !137
}

declare dso_local i32 @printf(i8* noundef, ...) #3

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "random_access.c", directory: "/home/users/shravank/projects/meliora2/Meliora/examples_mel", checksumkind: CSK_MD5, checksum: "d08687b798fc1c4063a7c7b507fc2933")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"uwtable", i32 1}
!6 = !{i32 7, !"frame-pointer", i32 2}
!7 = !{!"clang version 14.0.1 (https://github.com/llvm/llvm-project.git c62053979489ccb002efe411c3af059addcb5d7d)"}
!8 = distinct !DISubprogram(name: "array_access_pattern", scope: !1, file: !1, line: 25, type: !9, scopeLine: 25, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!9 = !DISubroutineType(types: !10)
!10 = !{null, !11}
!11 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !12, size: 64)
!12 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 160, elements: !14)
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !{!15}
!15 = !DISubrange(count: 5)
!16 = !{}
!17 = !DILocalVariable(name: "arr", arg: 1, scope: !8, file: !1, line: 25, type: !11)
!18 = !DILocation(line: 25, column: 31, scope: !8)
!19 = !DILocalVariable(name: "i", scope: !20, file: !1, line: 27, type: !13)
!20 = distinct !DILexicalBlock(scope: !8, file: !1, line: 27, column: 5)
!21 = !DILocation(line: 27, column: 14, scope: !20)
!22 = !DILocation(line: 27, column: 10, scope: !20)
!23 = !DILocation(line: 27, column: 21, scope: !24)
!24 = distinct !DILexicalBlock(scope: !20, file: !1, line: 27, column: 5)
!25 = !DILocation(line: 27, column: 23, scope: !24)
!26 = !DILocation(line: 27, column: 5, scope: !20)
!27 = !DILocalVariable(name: "j", scope: !28, file: !1, line: 28, type: !13)
!28 = distinct !DILexicalBlock(scope: !29, file: !1, line: 28, column: 9)
!29 = distinct !DILexicalBlock(scope: !24, file: !1, line: 27, column: 33)
!30 = !DILocation(line: 28, column: 18, scope: !28)
!31 = !DILocation(line: 28, column: 14, scope: !28)
!32 = !DILocation(line: 28, column: 25, scope: !33)
!33 = distinct !DILexicalBlock(scope: !28, file: !1, line: 28, column: 9)
!34 = !DILocation(line: 28, column: 27, scope: !33)
!35 = !DILocation(line: 28, column: 9, scope: !28)
!36 = !DILocation(line: 29, column: 13, scope: !37)
!37 = distinct !DILexicalBlock(scope: !33, file: !1, line: 28, column: 37)
!38 = !DILocation(line: 29, column: 17, scope: !37)
!39 = !DILocation(line: 29, column: 20, scope: !37)
!40 = !DILocation(line: 29, column: 23, scope: !37)
!41 = !DILocation(line: 30, column: 9, scope: !37)
!42 = !DILocation(line: 28, column: 33, scope: !33)
!43 = !DILocation(line: 28, column: 9, scope: !33)
!44 = distinct !{!44, !35, !45, !46}
!45 = !DILocation(line: 30, column: 9, scope: !28)
!46 = !{!"llvm.loop.mustprogress"}
!47 = !DILocation(line: 31, column: 5, scope: !29)
!48 = !DILocation(line: 27, column: 29, scope: !24)
!49 = !DILocation(line: 27, column: 5, scope: !24)
!50 = distinct !{!50, !26, !51, !46}
!51 = !DILocation(line: 31, column: 5, scope: !20)
!52 = !DILocation(line: 34, column: 11, scope: !8)
!53 = !DILocation(line: 34, column: 5, scope: !8)
!54 = !DILocalVariable(name: "i", scope: !55, file: !1, line: 35, type: !13)
!55 = distinct !DILexicalBlock(scope: !8, file: !1, line: 35, column: 5)
!56 = !DILocation(line: 35, column: 14, scope: !55)
!57 = !DILocation(line: 35, column: 10, scope: !55)
!58 = !DILocation(line: 35, column: 21, scope: !59)
!59 = distinct !DILexicalBlock(scope: !55, file: !1, line: 35, column: 5)
!60 = !DILocation(line: 35, column: 23, scope: !59)
!61 = !DILocation(line: 35, column: 5, scope: !55)
!62 = !DILocalVariable(name: "j", scope: !63, file: !1, line: 36, type: !13)
!63 = distinct !DILexicalBlock(scope: !64, file: !1, line: 36, column: 9)
!64 = distinct !DILexicalBlock(scope: !59, file: !1, line: 35, column: 33)
!65 = !DILocation(line: 36, column: 18, scope: !63)
!66 = !DILocation(line: 36, column: 14, scope: !63)
!67 = !DILocation(line: 36, column: 25, scope: !68)
!68 = distinct !DILexicalBlock(scope: !63, file: !1, line: 36, column: 9)
!69 = !DILocation(line: 36, column: 27, scope: !68)
!70 = !DILocation(line: 36, column: 9, scope: !63)
!71 = !DILocalVariable(name: "rand_row", scope: !72, file: !1, line: 37, type: !13)
!72 = distinct !DILexicalBlock(scope: !68, file: !1, line: 36, column: 37)
!73 = !DILocation(line: 37, column: 17, scope: !72)
!74 = !DILocation(line: 37, column: 28, scope: !72)
!75 = !DILocation(line: 37, column: 35, scope: !72)
!76 = !DILocalVariable(name: "rand_col", scope: !72, file: !1, line: 38, type: !13)
!77 = !DILocation(line: 38, column: 17, scope: !72)
!78 = !DILocation(line: 38, column: 28, scope: !72)
!79 = !DILocation(line: 38, column: 35, scope: !72)
!80 = !DILocation(line: 39, column: 13, scope: !72)
!81 = !DILocation(line: 39, column: 17, scope: !72)
!82 = !DILocation(line: 39, column: 27, scope: !72)
!83 = !DILocation(line: 39, column: 37, scope: !72)
!84 = !DILocation(line: 40, column: 9, scope: !72)
!85 = !DILocation(line: 36, column: 33, scope: !68)
!86 = !DILocation(line: 36, column: 9, scope: !68)
!87 = distinct !{!87, !70, !88, !46}
!88 = !DILocation(line: 40, column: 9, scope: !63)
!89 = !DILocation(line: 41, column: 5, scope: !64)
!90 = !DILocation(line: 35, column: 29, scope: !59)
!91 = !DILocation(line: 35, column: 5, scope: !59)
!92 = distinct !{!92, !61, !93, !46}
!93 = !DILocation(line: 41, column: 5, scope: !55)
!94 = !DILocation(line: 42, column: 1, scope: !8)
!95 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 44, type: !96, scopeLine: 44, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!96 = !DISubroutineType(types: !97)
!97 = !{!13}
!98 = !DILocalVariable(name: "arr", scope: !95, file: !1, line: 45, type: !99)
!99 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 800, elements: !100)
!100 = !{!15, !15}
!101 = !DILocation(line: 45, column: 9, scope: !95)
!102 = !DILocation(line: 46, column: 26, scope: !95)
!103 = !DILocation(line: 46, column: 5, scope: !95)
!104 = !DILocalVariable(name: "i", scope: !105, file: !1, line: 49, type: !13)
!105 = distinct !DILexicalBlock(scope: !95, file: !1, line: 49, column: 5)
!106 = !DILocation(line: 49, column: 14, scope: !105)
!107 = !DILocation(line: 49, column: 10, scope: !105)
!108 = !DILocation(line: 49, column: 21, scope: !109)
!109 = distinct !DILexicalBlock(scope: !105, file: !1, line: 49, column: 5)
!110 = !DILocation(line: 49, column: 23, scope: !109)
!111 = !DILocation(line: 49, column: 5, scope: !105)
!112 = !DILocalVariable(name: "j", scope: !113, file: !1, line: 50, type: !13)
!113 = distinct !DILexicalBlock(scope: !114, file: !1, line: 50, column: 9)
!114 = distinct !DILexicalBlock(scope: !109, file: !1, line: 49, column: 33)
!115 = !DILocation(line: 50, column: 18, scope: !113)
!116 = !DILocation(line: 50, column: 14, scope: !113)
!117 = !DILocation(line: 50, column: 25, scope: !118)
!118 = distinct !DILexicalBlock(scope: !113, file: !1, line: 50, column: 9)
!119 = !DILocation(line: 50, column: 27, scope: !118)
!120 = !DILocation(line: 50, column: 9, scope: !113)
!121 = !DILocation(line: 51, column: 31, scope: !122)
!122 = distinct !DILexicalBlock(scope: !118, file: !1, line: 50, column: 37)
!123 = !DILocation(line: 51, column: 27, scope: !122)
!124 = !DILocation(line: 51, column: 34, scope: !122)
!125 = !DILocation(line: 51, column: 13, scope: !122)
!126 = !DILocation(line: 52, column: 9, scope: !122)
!127 = !DILocation(line: 50, column: 33, scope: !118)
!128 = !DILocation(line: 50, column: 9, scope: !118)
!129 = distinct !{!129, !120, !130, !46}
!130 = !DILocation(line: 52, column: 9, scope: !113)
!131 = !DILocation(line: 53, column: 9, scope: !114)
!132 = !DILocation(line: 54, column: 5, scope: !114)
!133 = !DILocation(line: 49, column: 29, scope: !109)
!134 = !DILocation(line: 49, column: 5, scope: !109)
!135 = distinct !{!135, !111, !136, !46}
!136 = !DILocation(line: 54, column: 5, scope: !105)
!137 = !DILocation(line: 56, column: 5, scope: !95)
