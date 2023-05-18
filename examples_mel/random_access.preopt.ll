; ModuleID = 'random_access.ll'
source_filename = "random_access.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [4 x i8] c"%d \00", align 1
@.str.1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local void @array_access_pattern([5 x i32]* noundef %arr) #0 !dbg !8 {
entry:
  call void @llvm.dbg.value(metadata [5 x i32]* %arr, metadata !17, metadata !DIExpression()), !dbg !18
  call void @llvm.dbg.value(metadata i32 0, metadata !19, metadata !DIExpression()), !dbg !21
  br label %for.cond1.preheader, !dbg !22

for.cond1.preheader:                              ; preds = %entry, %for.inc6
  %indvars.iv7 = phi i64 [ 0, %entry ], [ %indvars.iv.next8, %for.inc6 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv7, metadata !19, metadata !DIExpression()), !dbg !21
  call void @llvm.dbg.value(metadata i32 0, metadata !23, metadata !DIExpression()), !dbg !27
  br label %for.body3, !dbg !28

for.body3:                                        ; preds = %for.cond1.preheader, %for.body3
  %indvars.iv = phi i64 [ 0, %for.cond1.preheader ], [ %indvars.iv.next, %for.body3 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv, metadata !23, metadata !DIExpression()), !dbg !27
  %arrayidx5 = getelementptr inbounds [5 x i32], [5 x i32]* %arr, i64 %indvars.iv7, i64 %indvars.iv, !dbg !29
  store i32 0, i32* %arrayidx5, align 4, !dbg !32
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1, !dbg !33
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next, metadata !23, metadata !DIExpression()), !dbg !27
  %exitcond6 = icmp ne i64 %indvars.iv.next, 5, !dbg !34
  br i1 %exitcond6, label %for.body3, label %for.inc6, !dbg !28, !llvm.loop !35

for.inc6:                                         ; preds = %for.body3
  %indvars.iv.next8 = add nuw nsw i64 %indvars.iv7, 1, !dbg !38
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next8, metadata !19, metadata !DIExpression()), !dbg !21
  %exitcond9 = icmp ne i64 %indvars.iv.next8, 5, !dbg !39
  br i1 %exitcond9, label %for.cond1.preheader, label %for.end8, !dbg !22, !llvm.loop !40

for.end8:                                         ; preds = %for.inc6
  %call = tail call i64 @time(i64* noundef null) #5, !dbg !42
  %conv = trunc i64 %call to i32, !dbg !42
  tail call void @srand(i32 noundef %conv) #5, !dbg !43
  call void @llvm.dbg.value(metadata i32 0, metadata !44, metadata !DIExpression()), !dbg !46
  br label %for.cond15.preheader, !dbg !47

for.cond15.preheader:                             ; preds = %for.end8, %for.inc29
  %i9.02 = phi i32 [ 0, %for.end8 ], [ %inc30, %for.inc29 ]
  call void @llvm.dbg.value(metadata i32 %i9.02, metadata !44, metadata !DIExpression()), !dbg !46
  call void @llvm.dbg.value(metadata i32 0, metadata !48, metadata !DIExpression()), !dbg !52
  br label %for.body18, !dbg !53

for.body18:                                       ; preds = %for.cond15.preheader, %for.body18
  %j14.01 = phi i32 [ 0, %for.cond15.preheader ], [ %inc27, %for.body18 ]
  call void @llvm.dbg.value(metadata i32 %j14.01, metadata !48, metadata !DIExpression()), !dbg !52
  %call19 = tail call i32 @rand() #5, !dbg !54
  %rem = srem i32 %call19, 5, !dbg !57
  call void @llvm.dbg.value(metadata i32 %rem, metadata !58, metadata !DIExpression()), !dbg !59
  %call20 = tail call i32 @rand() #5, !dbg !60
  %rem21 = srem i32 %call20, 5, !dbg !61
  call void @llvm.dbg.value(metadata i32 %rem21, metadata !62, metadata !DIExpression()), !dbg !59
  %idxprom22 = sext i32 %rem to i64, !dbg !63
  %idxprom24 = sext i32 %rem21 to i64, !dbg !63
  %arrayidx25 = getelementptr inbounds [5 x i32], [5 x i32]* %arr, i64 %idxprom22, i64 %idxprom24, !dbg !63
  store i32 1, i32* %arrayidx25, align 4, !dbg !64
  %inc27 = add nuw nsw i32 %j14.01, 1, !dbg !65
  call void @llvm.dbg.value(metadata i32 %inc27, metadata !48, metadata !DIExpression()), !dbg !52
  %exitcond = icmp ne i32 %inc27, 5, !dbg !66
  br i1 %exitcond, label %for.body18, label %for.inc29, !dbg !53, !llvm.loop !67

for.inc29:                                        ; preds = %for.body18
  %inc30 = add nuw nsw i32 %i9.02, 1, !dbg !69
  call void @llvm.dbg.value(metadata i32 %inc30, metadata !44, metadata !DIExpression()), !dbg !46
  %exitcond5 = icmp ne i32 %inc30, 5, !dbg !70
  br i1 %exitcond5, label %for.cond15.preheader, label %for.end31, !dbg !47, !llvm.loop !71

for.end31:                                        ; preds = %for.inc29
  ret void, !dbg !73
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
define dso_local i32 @main() #0 !dbg !74 {
entry:
  %arr = alloca [5 x [5 x i32]], align 16
  call void @llvm.dbg.declare(metadata [5 x [5 x i32]]* %arr, metadata !77, metadata !DIExpression()), !dbg !80
  %arraydecay = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %arr, i64 0, i64 0, !dbg !81
  call void @array_access_pattern([5 x i32]* noundef nonnull %arraydecay), !dbg !82
  call void @llvm.dbg.value(metadata i32 0, metadata !83, metadata !DIExpression()), !dbg !85
  br label %for.cond1.preheader, !dbg !86

for.cond1.preheader:                              ; preds = %entry, %for.end
  %indvars.iv3 = phi i64 [ 0, %entry ], [ %indvars.iv.next4, %for.end ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv3, metadata !83, metadata !DIExpression()), !dbg !85
  call void @llvm.dbg.value(metadata i32 0, metadata !87, metadata !DIExpression()), !dbg !91
  br label %for.body3, !dbg !92

for.body3:                                        ; preds = %for.cond1.preheader, %for.body3
  %indvars.iv = phi i64 [ 0, %for.cond1.preheader ], [ %indvars.iv.next, %for.body3 ]
  call void @llvm.dbg.value(metadata i64 %indvars.iv, metadata !87, metadata !DIExpression()), !dbg !91
  %arrayidx5 = getelementptr inbounds [5 x [5 x i32]], [5 x [5 x i32]]* %arr, i64 0, i64 %indvars.iv3, i64 %indvars.iv, !dbg !93
  %0 = load i32, i32* %arrayidx5, align 4, !dbg !93
  %call = call i32 (i8*, ...) @printf(i8* noundef nonnull dereferenceable(1) getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 noundef %0) #5, !dbg !96
  %indvars.iv.next = add nuw nsw i64 %indvars.iv, 1, !dbg !97
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next, metadata !87, metadata !DIExpression()), !dbg !91
  %exitcond = icmp ne i64 %indvars.iv.next, 5, !dbg !98
  br i1 %exitcond, label %for.body3, label %for.end, !dbg !92, !llvm.loop !99

for.end:                                          ; preds = %for.body3
  %putchar = call i32 @putchar(i32 10), !dbg !101
  %indvars.iv.next4 = add nuw nsw i64 %indvars.iv3, 1, !dbg !102
  call void @llvm.dbg.value(metadata i64 %indvars.iv.next4, metadata !83, metadata !DIExpression()), !dbg !85
  %exitcond5 = icmp ne i64 %indvars.iv.next4, 5, !dbg !103
  br i1 %exitcond5, label %for.cond1.preheader, label %for.end9, !dbg !86, !llvm.loop !104

for.end9:                                         ; preds = %for.end
  ret i32 0, !dbg !106
}

declare dso_local i32 @printf(i8* noundef, ...) #3

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #1

; Function Attrs: nofree nounwind
declare noundef i32 @putchar(i32 noundef) #4

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nofree nounwind }
attributes #5 = { nounwind }

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
!18 = !DILocation(line: 0, scope: !8)
!19 = !DILocalVariable(name: "i", scope: !20, file: !1, line: 27, type: !13)
!20 = distinct !DILexicalBlock(scope: !8, file: !1, line: 27, column: 5)
!21 = !DILocation(line: 0, scope: !20)
!22 = !DILocation(line: 27, column: 5, scope: !20)
!23 = !DILocalVariable(name: "j", scope: !24, file: !1, line: 28, type: !13)
!24 = distinct !DILexicalBlock(scope: !25, file: !1, line: 28, column: 9)
!25 = distinct !DILexicalBlock(scope: !26, file: !1, line: 27, column: 33)
!26 = distinct !DILexicalBlock(scope: !20, file: !1, line: 27, column: 5)
!27 = !DILocation(line: 0, scope: !24)
!28 = !DILocation(line: 28, column: 9, scope: !24)
!29 = !DILocation(line: 29, column: 13, scope: !30)
!30 = distinct !DILexicalBlock(scope: !31, file: !1, line: 28, column: 37)
!31 = distinct !DILexicalBlock(scope: !24, file: !1, line: 28, column: 9)
!32 = !DILocation(line: 29, column: 23, scope: !30)
!33 = !DILocation(line: 28, column: 33, scope: !31)
!34 = !DILocation(line: 28, column: 27, scope: !31)
!35 = distinct !{!35, !28, !36, !37}
!36 = !DILocation(line: 30, column: 9, scope: !24)
!37 = !{!"llvm.loop.mustprogress"}
!38 = !DILocation(line: 27, column: 29, scope: !26)
!39 = !DILocation(line: 27, column: 23, scope: !26)
!40 = distinct !{!40, !22, !41, !37}
!41 = !DILocation(line: 31, column: 5, scope: !20)
!42 = !DILocation(line: 34, column: 11, scope: !8)
!43 = !DILocation(line: 34, column: 5, scope: !8)
!44 = !DILocalVariable(name: "i", scope: !45, file: !1, line: 35, type: !13)
!45 = distinct !DILexicalBlock(scope: !8, file: !1, line: 35, column: 5)
!46 = !DILocation(line: 0, scope: !45)
!47 = !DILocation(line: 35, column: 5, scope: !45)
!48 = !DILocalVariable(name: "j", scope: !49, file: !1, line: 36, type: !13)
!49 = distinct !DILexicalBlock(scope: !50, file: !1, line: 36, column: 9)
!50 = distinct !DILexicalBlock(scope: !51, file: !1, line: 35, column: 33)
!51 = distinct !DILexicalBlock(scope: !45, file: !1, line: 35, column: 5)
!52 = !DILocation(line: 0, scope: !49)
!53 = !DILocation(line: 36, column: 9, scope: !49)
!54 = !DILocation(line: 37, column: 28, scope: !55)
!55 = distinct !DILexicalBlock(scope: !56, file: !1, line: 36, column: 37)
!56 = distinct !DILexicalBlock(scope: !49, file: !1, line: 36, column: 9)
!57 = !DILocation(line: 37, column: 35, scope: !55)
!58 = !DILocalVariable(name: "rand_row", scope: !55, file: !1, line: 37, type: !13)
!59 = !DILocation(line: 0, scope: !55)
!60 = !DILocation(line: 38, column: 28, scope: !55)
!61 = !DILocation(line: 38, column: 35, scope: !55)
!62 = !DILocalVariable(name: "rand_col", scope: !55, file: !1, line: 38, type: !13)
!63 = !DILocation(line: 39, column: 13, scope: !55)
!64 = !DILocation(line: 39, column: 37, scope: !55)
!65 = !DILocation(line: 36, column: 33, scope: !56)
!66 = !DILocation(line: 36, column: 27, scope: !56)
!67 = distinct !{!67, !53, !68, !37}
!68 = !DILocation(line: 40, column: 9, scope: !49)
!69 = !DILocation(line: 35, column: 29, scope: !51)
!70 = !DILocation(line: 35, column: 23, scope: !51)
!71 = distinct !{!71, !47, !72, !37}
!72 = !DILocation(line: 41, column: 5, scope: !45)
!73 = !DILocation(line: 42, column: 1, scope: !8)
!74 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 44, type: !75, scopeLine: 44, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!75 = !DISubroutineType(types: !76)
!76 = !{!13}
!77 = !DILocalVariable(name: "arr", scope: !74, file: !1, line: 45, type: !78)
!78 = !DICompositeType(tag: DW_TAG_array_type, baseType: !13, size: 800, elements: !79)
!79 = !{!15, !15}
!80 = !DILocation(line: 45, column: 9, scope: !74)
!81 = !DILocation(line: 46, column: 26, scope: !74)
!82 = !DILocation(line: 46, column: 5, scope: !74)
!83 = !DILocalVariable(name: "i", scope: !84, file: !1, line: 49, type: !13)
!84 = distinct !DILexicalBlock(scope: !74, file: !1, line: 49, column: 5)
!85 = !DILocation(line: 0, scope: !84)
!86 = !DILocation(line: 49, column: 5, scope: !84)
!87 = !DILocalVariable(name: "j", scope: !88, file: !1, line: 50, type: !13)
!88 = distinct !DILexicalBlock(scope: !89, file: !1, line: 50, column: 9)
!89 = distinct !DILexicalBlock(scope: !90, file: !1, line: 49, column: 33)
!90 = distinct !DILexicalBlock(scope: !84, file: !1, line: 49, column: 5)
!91 = !DILocation(line: 0, scope: !88)
!92 = !DILocation(line: 50, column: 9, scope: !88)
!93 = !DILocation(line: 51, column: 27, scope: !94)
!94 = distinct !DILexicalBlock(scope: !95, file: !1, line: 50, column: 37)
!95 = distinct !DILexicalBlock(scope: !88, file: !1, line: 50, column: 9)
!96 = !DILocation(line: 51, column: 13, scope: !94)
!97 = !DILocation(line: 50, column: 33, scope: !95)
!98 = !DILocation(line: 50, column: 27, scope: !95)
!99 = distinct !{!99, !92, !100, !37}
!100 = !DILocation(line: 52, column: 9, scope: !88)
!101 = !DILocation(line: 53, column: 9, scope: !89)
!102 = !DILocation(line: 49, column: 29, scope: !90)
!103 = !DILocation(line: 49, column: 23, scope: !90)
!104 = distinct !{!104, !86, !105, !37}
!105 = !DILocation(line: 54, column: 5, scope: !84)
!106 = !DILocation(line: 56, column: 5, scope: !74)
